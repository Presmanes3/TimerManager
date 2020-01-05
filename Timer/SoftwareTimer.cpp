#include "SoftwareTimer.h"

SoftwareTimer::SoftwareTimer(uint32_t timerPeriod, uint32_t sleepTime, bool initialState){
    this->timePeriod = timerPeriod;
    this->sleepTime = sleepTime;
    this->flag = initialState;
}

SoftwareTimer::SoftwareTimer(uint32_t commonPeriod, bool initialState){
    this->timePeriod = commonPeriod;
    this->sleepTime = commonPeriod;
    this->flag = initialState;
}

uint32_t SoftwareTimer::getTimerPeriod() {
    return this->timePeriod;
    }

uint32_t SoftwareTimer::getSleepTime(){
    return this->sleepTime;
    }

void SoftwareTimer::setTimerPeriod(uint32_t newTimerPeriod){
this->timePeriod = newTimerPeriod;
}

void SoftwareTimer::setSleepTime(uint32_t newSleepTime){
    this->sleepTime = newSleepTime;
}

void SoftwareTimer::activateFlag(){
    this->flag = true;
}

void SoftwareTimer::deactivateFlag(){
    this->flag = false;
}

bool SoftwareTimer::getFlag(){
    return this->flag;
}
