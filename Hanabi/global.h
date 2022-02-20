#ifndef _GLOBALH_		//protectes from multiple including...
#define _GLOBALH_		//... needs an #endif at bottom

#include <stdio.h>
#include <stdlib.h>






void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 

    // Stroing start time 
    clock_t start_time = clock(); 

    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds) 
        ; 
}





#endif
