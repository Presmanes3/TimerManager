/**
 * @brief The aim of this function is to manage all the Timers created inside a program. It is independent
 * from the source of the time.
 *
 */
#ifndef TIMERMANAGERPROJECT_TIMERMANAGER_H
#define TIMERMANAGERPROJECT_TIMERMANAGER_H

#include <cstdint>
#include <cstdio>
#include <cmath>
#include <cstring>
#include "TimerManagerConstants.h"
#include <errno.h>

class Timer;

/**
 * @brief The aim of this class is to manage different Timer created previously
 *
 */
class TimerManager {

public:

    //**** CONSTRUCTORS ****/

    /**
     * @brief This constructor will create a timer manager with a given number of timers inside (timerPool)
     * it also receives a name.
     *
     * @attention TimerManagerIdentifier must be shorter than 25 chars
     * @attention Pool should not be null
     * @attention maxTimers must not be bigger than pool size
     *
     * @param tmID  is the timer manager name
     * @param pool contains timers to be managed
     * @param maxTimers total number of timer that can managed by timer manager
     */
    TimerManager(char *tmID, Timer** pool ,uint8_t maxTimers);

    /**
     * @brief This constructor will create a timer manager without timers inside
     *
     * @attention TimerManagerIdentifier must be shorter than 25 chars
     * @attention Pool should not be null
     * @attention maxTimers must not be bigger than pool size
     * @attention check TIMER_MANAGER_DEFAULT_MAX_TIMERS in TimerManager.h
     *
     * @param tmID  is the timer manager name
     * @param pool contains timers to be managed
     */
    TimerManager(char *tmID, Timer** pool);

    /**
     * @brief This constructor will create an empty timer manager
     *
     * @attention Pool should not be null
     * @attention maxTimers must not be bigger than pool size
     * @attention check TIMER_MANAGER_DEFAULT_MAX_TIMERS in TimerManager.h
     *
     * @param pool contains timers to be managed
     */
    TimerManager(Timer** pool);


    //**** SETTERS ****/

    /**
     * @brief This function sets a new Timer in a given position
     *
     * @param t Timer
     * @param position
     */
    void setTimer(Timer *t, uint32_t position);

    /**
     * @brief This function changes the timer pool to manage
     *
     * @attention Pool should not be null
     * @attention maxTimers must not be bigger than pool size
     *
     * @param pool pool of timers to handle
     * @param maxTimers maximum number of timers that the class can handle
     */
    void setTimerPool(Timer** pool, uint8_t maxTimers);

    void addTimer(Timer* t);

    /**
     * @brief This function changes the identifier of the object
     *
     * @param newIdentifier
     */
    void setIdentifier(char *newIdentifier);

    /**
     * @brief This functions changes the maximum number of timers managed by the timer manager
     *
     * @attention maxTimers must not be bigger than pool size
     *
     * @param newValue
     */
    void setMaxTimers(uint8_t newValue);

    /**
     * @brief This function starts the object. It is supposed to be used when you have stopped it previously
     * since you do not need to call this function at the start of your program.
     *
     * It sets status to true
     */
    void start();

    /**
     * @brief This function stops the object.
     *
     * It sets status to false
     */
    void stop();

    //**** GETTERS ****/

    /**
     * @brief This function returns a timer pool
     *
     * @return timer pool
     */
    Timer **getTimerPool();

    /**
     * @brief This function returns a pointer to a Timer
     *
     * @param position of the Timer inside the pool
     * @return
     */
    Timer *getTimer(uint32_t position);

    /**
     * @brief This function returns the timer manager identifier
     *
     * @return identifier
     */
    char *getIdentifier();

    /**
     * @brief This function returns true if time manager is activated or not
     *
     * @return true/false
     */
    bool isRunning();

    /**
     * @brief This function returns the maximum number of timers that the timer manager can handle
     *
     * @return max number of timers
     */
    uint8_t getMaxTimers();


    /**** UTILITIES ****/

    /**
     * @brief This function checks if the timer time has past and returns true if so
     *
     * @param Timer, pointer to timer
     * @param reference, time reference
     * @param deactivate, true = deactivate timer at the end.
     *
     * @return true if timer time has past
     */
    bool checkTimer(Timer *Timer, uint32_t reference, bool deactivateTimer);

    /**
     * @brief This function returns the difference between 2 values in absolute values.
     *
     * @param currentTime
     * @param referenceTime
     *
     * @return difference between currentTime and referenceTime
     */
     uint32_t getTimeDifference(uint32_t currentTime, uint32_t referenceTime);

    /**
     * @brief This function copies the contain of t1 into t2
     *
     * @param t1
     * @param t2
     */
    void copyTimer(Timer *t1, Timer *t2);

    void clearPool(Timer** pool, uint8_t size);

private:

    uint8_t maxTimers;
    uint8_t numTimers;

    Timer **pool;


    char identifier[TIMER_MANAGER_IDENTIFIER_MAX_LENGTH];
    bool status;
};


#endif //TIMERMANAGERPROJECT_TIMERMANAGER_H
