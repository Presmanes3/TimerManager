//
// Created by presmanes3 on 8/1/20.
//

#ifndef TIMERMANAGERPROJECT_TIMER_H
#define TIMERMANAGERPROJECT_TIMER_H

#include <cinttypes>
#include "TimerManagerConstants.h"

enum timerType {MIL, SEC, MIN, HOUR};

class Timer {

public:

    /**** CONSTRUCTORS ****/
    
    /**
     * @brief full Timer constructor
     *
     * @param time that must pass to activate the flag
     * @param reference is the time to compare
     * @param id
     * @param flag is activated when time check occurs
     * @param status marks is timer is being used or not
     */
    Timer(uint32_t time, uint32_t reference, timerType id, bool flag, bool status);

    /**
     * @brief Timer starts with flag and status deactivated
     *
     * @param time that must pass to activate the flag
     * @param reference is the time to compare
     * @param id
     */
    Timer(uint32_t time, uint32_t reference, timerType id);

    /**
     * @brief Timer starts with id : milliseconds
     *
     * @param time that must pass to activate the flag
     * @param reference is the time to compare
     */
    Timer(uint32_t time, uint32_t reference);

    /**
     * @brief Timers starts with reference equal to time
     *
     * @param time that must pass to activate the flag
     */
    Timer(uint32_t time);

    /**** SETTERS ****/
    
    /**
     *
     * @param newTime change timer frequency
     */
    void setTime(uint32_t newTime);

    /**
     *
     * @param newReference change time reference
     */
    void setReference(uint32_t newReference);

    /**
     *
     * @param newId change id
     */
    void setIdentifier(timerType newId);

    /**** GETTERS ****/
    
    /**
     *
     * @return timer frequency
     */
    uint32_t getTime();

    /**
     *
     * @return time reference
     */
    uint32_t getReference();

    /**
     *
     * @return id
     */
    uint32_t getIdentifier();

    /**
     *
     * @return true if status is true
     */
    bool isRunning();

    /**
     *
     * @return true if flag is true
     */
    bool isFlagActivated();

    /**** FLAG ACTIVATION *****/
    /**
     * @brief turn flag true
     */
    void activateFlag();

    /**
     * @brief turn flag false
     */
    void deactivateFlag();

    /**** START / STOP ****/
    /**
     * @brief when starting the timer you must specify a time reference
     *
     * @param startTime reference time at start
     */
    void start(uint32_t startTime);

    /**
     * @brief when you stop the timer it saves the last time value
     *
     * @param stopTime reference time at stop
     */
    void stop(uint32_t stopTime);


private:
    uint32_t reference;
    uint32_t time;

    timerType id;

    bool flag;
    bool status;


};


#endif //TIMERMANAGERPROJECT_TIMER_H
