//
// Created by presmanes3 on 10/1/20.
//

#include "Timer.h"
#include "TimerManager.h"
#include "stdio.h"

Timer t = Timer(15 ,0, SEC, TIMER_FLAG_ACTIVATED, TIMER_STATUS_ON);
Timer* t2 = nullptr;

Timer* p[25];
TimerManager m = TimerManager((char*)"Pepe", p,25);

int main(){

    m.clearPool(p, 25);

    m.addTimer(&t);
    for(uint8_t x = 1; x < 25; x++){
        m.addTimer(new Timer(x));
    }

    Timer** pool = m.getTimerPool();

    printf("Size of Pool : %d\n", (int)(sizeof(pool)));
    printf("Size of *Pool : %d\n", (int)(sizeof(*pool)));
    printf("Size of **Pool : %d\n", (int)(sizeof(**pool)));

return 0;
}