//
// Created by presmanes3 on 8/1/20.
//

#include "Timer.h"

/**** CONSTRUCTORS ****/
Timer::Timer(uint32_t time, uint32_t reference, timerType id, bool flag, bool status) {
    this->time = time;
    this->reference = reference;
    this->id = id;
    this->flag = flag;
    this->status = status;
}

Timer::Timer(uint32_t time, uint32_t reference, timerType id) {
    this->time = time;
    this->reference = reference;
    this->id = id;
    this->flag = TIMER_FLAG_DEACTIVATED;
    this->status = TIMER_STATUS_OFF;
}

Timer::Timer(uint32_t time, uint32_t reference) {
    this->time = time;
    this->reference = reference;
    this->id = timerType::MIL;
    this->flag = TIMER_FLAG_DEACTIVATED;
    this->status = TIMER_STATUS_OFF;
}

Timer::Timer(uint32_t time) {
    this->time = time;
    this->reference = time;
    this->id = timerType::MIL;
    this->flag = TIMER_FLAG_DEACTIVATED;
    this->status = TIMER_STATUS_OFF;
}

/**** SETTERS ****/
void Timer::setTime(uint32_t newTime) {
    this->time = newTime;
}

void Timer::setReference(uint32_t newReference) {
    this->reference = newReference;
}

void Timer::setIdentifier(timerType newId) {
    this->id = newId;
}

/**** GETTERS ****/
uint32_t Timer::getTime() {
    return this->time;
}

uint32_t Timer::getReference() {
    return this->reference;
}

uint32_t Timer::getIdentifier() {
    return this->id;
}

bool Timer::isRunning() {
    return this->status;
}

bool Timer::isFlagActivated() {
    return this->flag;
}

/**** FLAG ACTIVATION ****/
void Timer::activateFlag() {
    this->flag = TIMER_FLAG_ACTIVATED;
}

void Timer::deactivateFlag() {
    this->flag = TIMER_FLAG_DEACTIVATED;
}

/**** START / STOP ****/
void Timer::start(uint32_t startTime) {
    this->reference = startTime;
    this->status = TIMER_STATUS_ON;
}

void Timer::stop(uint32_t stopTime) {
    this->reference = stopTime;
    this->status = TIMER_STATUS_OFF;
}