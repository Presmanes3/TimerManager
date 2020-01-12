//
// Created by presmanes3 on 12/1/20.
//


#include "Timer.h"
#include <cstdio>

Timer* timer1;
Timer* timer2;

void printTimerFeatures(Timer* t, char* name);

int main(){

    timer1 = new Timer(25, 0, SEC, TIMER_FLAG_DEACTIVATED, TIMER_STATUS_ON);
    timer2 = new Timer(123437, 27, MIL);

    printTimerFeatures(timer1, "Timer 1");
    printTimerFeatures(timer2, "Timer 2");


}

void printTimerFeatures(Timer* t, char* name){
    printf("Name: %s\n", name);
    printf("Time: %d\nReference: %d\nFlag: %d\nStatus: %d\n\n", t->getTime(), t->getReference(), t->isFlagActivated(), t->isRunning());
}