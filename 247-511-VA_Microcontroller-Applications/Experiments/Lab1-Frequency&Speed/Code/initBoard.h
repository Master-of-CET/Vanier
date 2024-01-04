/**********************************************************************************************
* FileName: initBoard.h
*
* Name: Leonardo Fusser (1946995)   Lab 1       Function Generator
*
* Description: 
*  
* REVISION HISTORY: 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date            Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Serge Hould       14 January 2021 v1.0.0      Setup for PIC32.
* Leonardo Fusser   24 August  2021 v1.0.1      Added more function prototypes and comments.
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#ifndef INITBOARD_H
#define INITBOARD_H

#include <stdint.h>
#include <xc.h>
#include <sys/attribs.h>

#define     S3  PORTDbits.RD6
#define     S6  PORTDbits.RD7
#define     S5  PORTAbits.RA6
#define     S4  PORTDbits.RD13

void initIO(void);                  //Function prototype
void initT2(void);                  //" "
void initCN9(void);                 //" "

#endif