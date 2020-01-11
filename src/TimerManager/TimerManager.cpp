//
// Created by presmanes3 on 6/1/20.
//

#include "TimerManager.h"
#include "Timer.h"

/**** CONSTUCTORS ****/

TimerManager::TimerManager(char *tmID,Timer** pool ,uint8_t maxTimers) {
    snprintf(this->identifier, TIMER_MANAGER_IDENTIFIER_MAX_LENGTH, "%s", tmID);

    this->maxTimers = maxTimers;

    this->pool = pool; // TODO Check if maxTimers is bigger than pool size

    this->numTimers = 0;
    this->status = TIMER_MANAGER_ACTIVATED;
}

TimerManager::TimerManager(char *tmID, Timer** pool) {
    snprintf(this->identifier, TIMER_MANAGER_IDENTIFIER_MAX_LENGTH, "%s", tmID);

    this->maxTimers = TIMER_MANAGER_DEFAULT_MAX_TIMERS;

    this->pool = pool;

    this->numTimers = 0;
    this->status = TIMER_MANAGER_ACTIVATED;
}

TimerManager::TimerManager(Timer** pool) {
    snprintf(this->identifier, TIMER_MANAGER_IDENTIFIER_MAX_LENGTH, "%s", TIMER_MANAGER_DEFAULT_IDENTIFIER);

    this->maxTimers = TIMER_MANAGER_DEFAULT_MAX_TIMERS;

    this->pool = pool;

    this->numTimers = 0;
    this->status = TIMER_MANAGER_ACTIVATED;
}

/**** SETTERS ****/

void TimerManager::setTimer(Timer *t, uint32_t position) {
    this->pool[position] = t;
}

void TimerManager::addTimer(Timer *t) {
    if (t != nullptr) {
        if (this->numTimers < this->maxTimers) {
            this->pool[numTimers] = t;
            this->numTimers++;
        }else{
            // TODO Error out of range
        }
    } else {
        errno = EINVAL;
        perror("Error adding Timer");
    }
}

void TimerManager::setIdentifier(char *newIdentifier) {
    snprintf(this->identifier, TIMER_MANAGER_IDENTIFIER_MAX_LENGTH, "%s", newIdentifier);
}

void TimerManager::start() {
    this->status = true;
}

void TimerManager::stop() {
    this->status = false;
}

void TimerManager::setMaxTimers(uint8_t newValue) { // TODO limit max number based on pool size
    this->maxTimers = newValue;
}

/**** GETTERS ****/

Timer **TimerManager::getTimerPool() {
    return this->pool;
}

Timer *TimerManager::getTimer(uint32_t position) {
    return this->pool[position];
}

char *TimerManager::getIdentifier() {
    return this->identifier;
}

bool TimerManager::isRunning() {
    return this->status;
}

uint8_t TimerManager::getMaxTimers() {
    return this->maxTimers;
}

/**** UTILITIES ****/

bool TimerManager::checkTimer(Timer *Timer, uint32_t reference, bool deactivateTimer) {
    if (Timer->isRunning()) {

        uint32_t timerReference = Timer->getReference();
        uint32_t timePast = this->getTimeDifference(reference, timerReference);

        if (timePast >= Timer->getTime()) {

            Timer->activateFlag();
            Timer->setReference(reference);

            if (deactivateTimer) Timer->stop(reference);

            return true;
        } else return false;
    }

    return false;
}

uint32_t TimerManager::getTimeDifference(uint32_t currentTime, uint32_t referenceTime) {
    return abs(int(currentTime - referenceTime));
}

void TimerManager::copyTimer(Timer *t1, Timer *t2) {
    if (t1 == nullptr && t2 == nullptr) return;

    t2->setTime(t1->getTime());
    t2->setIdentifier(timerType(t1->getIdentifier()));
    t2->setReference(t1->getReference());
}

void TimerManager::clearPool(Timer **pool, uint8_t size) {
    for(uint8_t x = 0; x < size; x++){
        pool[x] = nullptr;
    }
}