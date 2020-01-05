/**
 * @file SoftwareTimer.h
 * @author Javier Presmanes Cardama (presmanes3@gmail.com)
 * @brief The aim of this class is to avoid creating timing logic within your code, just create a Timer!
 * @version 0.1
 * @date 2019-12-29
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef _TIMER_H_

#include "inttypes.h"

/**
 * @brief SoftwareTimer creates a timer which will be checked constantly by TimeManager or independently
 * 
 */
class SoftwareTimer{
    public:
    
    /**
     * @brief Construct a new Software Timer object
     * 
     * @param timerPeriod time which must pass to activate Timer Flag
     * @param sleepTime time which the Timer Flag will be deactivated
     * @param initialState initial state for Timer Flag (default true)
     */
    SoftwareTimer(uint32_t timerPeriod, uint32_t sleepTime, bool initialState);

    /**
     * @brief Construct a new Software Timer object
     * 
     * @param commonPeriod time which must pass to activate and deactivate Timer Flag are equal
     * @param initialState initial state for Timer Flag
     */
    SoftwareTimer(uint32_t commonPeriod, bool initialState);

    /**
    * @brief Get the period for activating Timer Flag
    * 
    * @return uint32_t timePeriod
    */
    uint32_t getTimerPeriod();

    /**
     * @brief Get the sleep time
     * 
     * @return uint32_t sleepTime
     */
    uint32_t getSleepTime();

    /**
     * @brief Set the timer period
     * 
     * @param newTimerPeriod new timer period value
     */

    void setTimerPeriod(uint32_t newTimerPeriod);

    /**
     * @brief Set the sleep time
     * 
     * @param newSleepTime new sleep time value
     */
    void setSleepTime(uint32_t newSleepTime);

    /**
     * @brief Activate Timer Flag
     * 
     */
    void activateFlag();

    /**
     * @brief Deactivate Timer Flag
     * 
     */
    void deactivateFlag();

    /**
     * @brief Get the Timer Flag
     * 
     * @return true if timer period has past
     * @return false if timer is sleeping
     */
    bool getFlag();

    private:
        uint32_t timePeriod, sleepTime;
        bool flag;

};

#endif
