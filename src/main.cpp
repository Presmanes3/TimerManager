//
// Created by presmanes3 on 10/1/20.
//

#include "Timer.h"
#include "TimerManager.h"
#include "stdio.h"

Timer t = Timer(15 ,0, SEC, TIMER_FLAG_ACTIVATED, TIMER_STATUS_ON);
TimerManager m = TimerManager((char*)"Pepe", 15);

int main(){

}