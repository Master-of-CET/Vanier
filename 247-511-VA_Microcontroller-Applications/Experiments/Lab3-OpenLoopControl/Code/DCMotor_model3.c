/* DCMotor_model3.c     see also DCMotor_model2.c    
 * Mathematical model representing a BDC motor    
 * 
 *  Author  Date                    Comments/version 
 *  SH      22 Jan. 2021            V1.0    Implement position model. Tested OK
 *  SH      28 Jan. 2021            V1.1    Fine tune according to real motor 
 *                                          measured characteristics 
 *									v1.2	readADC() was re-scaled
 * 
 * 
 * 
 * */                                                 

#include <math.h>
#include <xc.h>
#include <stdio.h>
#include "console32.h"
#include "DCMotor_model3.h"
#include <stdint.h>
#include <string.h>
#include "configuration.h"

/* Model parameters for a 100mS loop*/
#define KI      0.1     // inv prop to Capacitor
#define KR      1      // inv prop to Resistor
#define KIp     0.006     // position integral gain

/* Globals */
int friction =0; // Motor friction - controlled by DCMI adc_sim

/* UART BUG*/
/*
 * During simulation when printing to UARTs, we sometime get the following 
 * infamous exception message from the simulator:
 *  W0011-CORE: Access attempt to unimplemented RAM memory.
 *  Simulator halted
 * 
 * In order to continue runinng, variable have been set persistent so if 
 * RUN is pressed again, variables won't get reset.
 * Just keep running by pressing RUN again. (DO NOT Restart or Reset)
 */

static double i __attribute__((persistent));
static double ITerm2 __attribute__((persistent));
static int16_t ITerm2_int16 __attribute__((persistent));
static int time __attribute__((persistent));
static int pos __attribute__((persistent));
int adc_sim=512;
void response_print_pos(int console, char* txt, int range, int val);
void response_print_pos_neg(int console, char* txt, int range, int scale, int val);

/********************************************************/
/*  Model for a BDC motor                              */
/*  Motor gain 50 RPM/pwm                               */
/*      E.g.    pwm =50% -> speed = 2500 RPM            */
/*              pwm =100% -> speed = 5000 RPM           */
/*                                                      */
/* Vs = Vr + Vc                                         */
/* Vc represents speed in RPM - integral term           */
/* Vs/R represents the pwm input -  initial current     */
/* Vs = Ri + i/C * integral of ic * dt                  */
/* Vs - integral of ic * dt = Ri                        */
/* (Vs - integral  of ic * dt) / R = i                  */
/* KR* Vs - KI *integral  of ic * dt = i                */
/*                                                      */
/************************ pv vs time*********************/
/*                                                      */
/*   scaled_pwm*KR _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*/
/*                                      *****************/
/*                              *                       */
/*                         *                            */
/*                     *                                */
/*                 *                                    */
/*              *                                       */
/*            *                                         */
/*          *                                           */
/*         *                                            */
/************************   time->   ********************/
#ifdef  SIMULATION
void set_pwm(int _pwm){
    if(_pwm >HUNDRED_DUTY-1   ) _pwm = HUNDRED_DUTY-1  ;
    else if(_pwm  < -HUNDRED_DUTY+1 ) _pwm = -HUNDRED_DUTY+1;
    char buff[100];
    int scaled_pwm =100;
    int j, debug2;
    time++;
    scaled_pwm = (long)_pwm;// no friction
    ITerm2 = ITerm2 + KI *i;  // ITerm2 represents the speed in RPM - Vc voltage
    i = (double)scaled_pwm*KR - ITerm2;     // current in a RC circuit
    debug2 =i;
    
    ITerm2_int16 = (long) ITerm2;
    pos = pos + KIp*ITerm2; //position is the integral of speed
    response_print_pos_neg(C_UART2, " pwm", 1000, 40, _pwm);
    response_print_pos(C_UART1, " pos", 200, pos);
}
#endif
/* Function to plot positive values only */
void response_print_pos(int console, char* txt, int range, int val){
    int j, val_print;
    char buff[100];
    val_print =val;
    if(val> range) val = range;
    else if(val < 0) val = 0;
    /* Prints time line */
    sprintf(buff,"%4dmS ",time*10);
    fprintf2(console, buff);

    /* Prints scaled down val to a specific range */
    for(j=0; j< (val*60)/range ; j++) {
        fprintf2(console, "*");
    }
    sprintf(buff,"%3d",val_print);
    strcat(buff,txt);
    fprintf2(console, buff);
    for(j=(val*60)/range; j< (val*120)/range ; j++) {
        fprintf2(console, "*");
    }
    fprintf2(console, "\n");
}


/* Function to plot positive and negative values*/
void response_print_pos_neg(int console, char* txt, int range, int scale, int val){
    int j, half_scale, lim, val_print;
    val_print =val;
   // static int time=0;
    char buff[100];
    if(val> range) val = range;
    else if(val < -range) val = -range;
    half_scale = scale/2;
    /* Prints time line */
    sprintf(buff,"%4dmS ",time*10);
    fprintf2(console, buff);
    
    sprintf(buff,"%3d",val_print);
    strcat(buff,txt);
    
    if(val<0){
        /* Prints negative plot scaled down val to a specific range */
        lim = (50+(val*scale)/range)-strlen(buff); 
        for(j=0; j< lim ; j++) {
            fprintf2(console, " ");
        }
        for(j=0; j< (-val*half_scale)/range ; j++)  {
            fprintf2(console, "*");
        }
        fprintf2(console, buff);
        for(j=0; j< (-val*half_scale)/range ; j++) {
            fprintf2(console, "*");
        }
        fprintf2(console, "|");
    }
     /* Prints positive plot scaled down val to a specific range */
    else{
         /* Prints ... */
        for(j=0; j< 57-strlen(buff) ; j++) {
            fprintf2(console, " ");
        }
        fprintf2(console, "|");
        for(j=0; j< (val*half_scale)/range ; j++)  {
            fprintf2(console, "*");
        }
        sprintf(buff,"%3d",val_print);
        strcat(buff,txt);
        fprintf2(console, buff);
        for(j=0; j< (val*half_scale)/range ; j++)  {
            fprintf2(console, "*");
        }
    }
    fprintf2(console, "\n");
}

#ifdef  SIMULATION
int get_pv(void){
        return pos;
}

int readADC( int ch){
    long adc;
    adc = adc_sim;
    adc = adc_sim + 0x8000;
    adc = ((long)adc*1024/0x10000);
    return adc;
}
#endif
