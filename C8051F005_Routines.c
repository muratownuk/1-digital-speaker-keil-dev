/*
    C8051F005_Routines: 
    this module contains routines that are commonly used for the device 
    C8051F005.
*/
#define _C8051F005_ROUTINES_C_ 

/*
    includes 
*/
#include "./SiLABS/c8051F000.h" 
#include "on_off.h" 
#include "C8051F005_Routines.h" 

/*
    function prototypes
*/
void vGlobalInterrupts(bit status);
void vTimer1(bit status);

/*
    routines 
*/
/*
    vGlobalInterrupts: 
    enables/disables global interrupts (EA).

    parameters: status 
        bit status: ON to enable, OFF to disable. 
    return    : none 
*/
void vGlobalInterrupts(bit status){

    if(status==ON) 
        EA=ON; 
    else 
        EA=OFF;

}

/*
    vTimer1:
    start/stop timer 1 (TR1). 
    
    parameters: status 
        bit status: ON to start timer 1, OFF to stop. 
    return    : none
*/
void vTimer1(bit status){

    if(status==ON) 
        TR1=ON; 
    else 
        TR1=OFF;

}



