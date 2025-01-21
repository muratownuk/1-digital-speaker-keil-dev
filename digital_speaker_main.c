/*
    digital_speaker_main: 
    the main routine where the program starts. the C8051F005 oscillator 
    frequency is default (2MHz). 
*/ 
/*
    includes 
*/
#include "./SiLABS/c8051F000.h" 
#include "on_off.h" 
#include "C8051F005_Init.h" 
#include "C8051F005_Routines.h" 
#include "digital_speaker.h" 

/*
    defines 
*/
#define     PRESSED     1

/*
    sbit definitions 
*/
sbit button = P1^7;                       // 0 = PRESSED 

/*
    main routine 
*/
void main(void){ 
    
    vWatchdog(OFF);                     // turn off watchdog timer 
    vPort_Init();                       // initialize used port(s) 
    vTimer1_Init();                     // initialize timer 1 

    while(button!=PRESSED)              // start button (here until pressed) 
        ;

    vGlobalInterrupts(ON);              // enable global interrupts 
    vTimer1(ON);                        // start timer 1 

    while(1) 
        ;                               // forever loop 

}

