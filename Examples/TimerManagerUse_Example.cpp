//
// Created by presmanes3 on 12/1/20.
//


#include "Timer.h"
#include "TimerManager.h"

#define DONT_DEACTIVATE_TIMER false
#define DEACTIVATE_TIMER true


Timer* timer1;
Timer* timer2;

TimerManager manager1 = TimerManager((char*)"TimerManager1", nullptr, 0);

void printTimerFeatures(Timer* t, char* name);
void DeactivateTimer_Example();
void Normal_Example();
void CopyTimers_Example();

int main(){

    //Normal_Example();
    //DeactivateTimer_Example();
    //CopyTimers_Example();

}

void printTimerFeatures(Timer* t, char* name){
    printf("Name: %s\n", name);
    printf("Time: %d\nReference: %d\nFlag: %d\nStatus: %d\n\n", t->getTime(), t->getReference(), t->isFlagActivated(), t->isRunning());
}

void DeactivateTimer_Example(){
    // Simulate time source deactivating timer at the end ==============================
    printf("Example of TimerManager deactivating timer at the end.");
    timer1 = new Timer(500, 0, SEC, TIMER_FLAG_DEACTIVATED, TIMER_STATUS_ON);

    printTimerFeatures(timer1, (char*)"Timer 1 Before time simulation starts");

    for(uint32_t time_simulation = 0; time_simulation <= 10000; time_simulation += 100){
        if(manager1.checkTimer(timer1, time_simulation, DEACTIVATE_TIMER)){
            printf("LED on\n\n");
            break;
        }
    }
    printTimerFeatures(timer1, (char*)"Timer 1 After time simulation starts");
}

void Normal_Example(){
    // Create a timer every 500 sec
    printf("Example of TimerManager.");
    timer1 = new Timer(500, 0, SEC, TIMER_FLAG_DEACTIVATED, TIMER_STATUS_ON);

    // Simulate time source from 0ms to 10000ms =========================================
    printTimerFeatures(timer1, (char*)"Timer 1 Before time simulation starts");

    for(uint32_t time_simulation = 0; time_simulation <= 10000; time_simulation += 100){
        if(manager1.checkTimer(timer1, time_simulation, DONT_DEACTIVATE_TIMER)){
            printf("LED on\n\n");
            break;
        }
    }
    printTimerFeatures(timer1, (char*)"Timer 1 After time simulation starts");
}

void CopyTimers_Example(){
    timer1 = new Timer(500, 0, SEC, TIMER_FLAG_DEACTIVATED, TIMER_STATUS_ON);
    timer2 = new Timer(250, 200, MIL, TIMER_FLAG_DEACTIVATED, TIMER_STATUS_ON);

    printTimerFeatures(timer1, (char*)"Timer 1");
    printTimerFeatures(timer2, (char*)"Timer 2 before copy");

    manager1.copyTimer(timer1, timer2);

    printTimerFeatures(timer1, (char*)"Timer 1");
    printTimerFeatures(timer2, (char*)"Timer 2 after copy");
}

