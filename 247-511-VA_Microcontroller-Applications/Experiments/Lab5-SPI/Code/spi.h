/**************************************************************************************************
* FileName: spi.h
*
* Name: Leonardo Fusser (1946995)       Lab 5       SPI communication 
*
* Description: Incudes all macros and dependencies needed for spi.c source file.
*  
* REVISION HISTORY: 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   30 November 2021    v1.0.0      First version of header file.
* Leonardo Fusser   7 December 2021     v1.0.1      Cleaned up header file.
* Leonardo Fusser   11 December 2021    v1.0.2      Added WriteSPI2 function prototype.
*                                                   Cleaned up header file 
*                                                   Completed header file.
*                                                   Added comments.   
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#ifndef SPI_H
#define SPI_H

/*All dependencies required included below*/
#include "public.h"


#define SS      LATGbits.LATG9     //Chip select/slave select pin on PIC32.
#define DC      LATBbits.LATB15    //Data command/control pin on PMOD OLED display.


/*SPI mode select*/
#if defined Mode0   //SPI mode 0.
    #define CPOL 0  //Clock polarity of 0.
    #define CPHA 0  //Clock phase of 0.

        #elif defined Mode1     //SPI mode 1.
            #define CPOL 0      //Clock polarity of 0.
            #define CPHA 1      //Clock phase of 1.

                #elif defined Mode2     //SPI mode 2.
                    #define CPOL 1      //Clock polarity of 1.
                    #define CPHA 0      //Clock phase of 0.

                        #elif defined Mode3     //SPI mode 3.
                            #define CPOL 1      //Clock polarity of 1.
                            #define CPHA 1      //Clock phase of 1.
#endif


/*Function prototypes*/
void spi_init(int baud, int cpol, int cpha);
int spi_ld_buffer(int load);
void WriteSPI2(int load);

#endif
