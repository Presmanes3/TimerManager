/**
 * @name Timer Library
 * @author Javier Presmanes Cardama (https://github.com/Presmanes3)
 * @version 1.0
 * @date 11/01/2020
 *
 */
#ifndef TIMERMANAGERPROJECT_TIMER_H
#define TIMERMANAGERPROJECT_TIMER_H

#if !defined(ARDUINO)

#include <cstdint>

#else
#include "stdint.h"
#endif

#define TIMER_FLAG_ACTIVATED true
#define TIMER_FLAG_DEACTIVATED false

#define TIMER_STATUS_ON true
#define TIMER_STATUS_OFF false

/**
 * @brief Identifier can be used by the user in order to have a visual method to know the frequency
 * of the timer. It can be milliseconds, Seconds, Minutes, Hours etc...
 *
 * @attention - You can add your own values to this variable
 */
enum timerType {
    MIL, SEC, MIN, HOUR
};

/**
 * @brief The aim of this class is to define what a Timer is.
 *
 * This class can be used by itself, but there is also a class called TimerManager
 * which will help you to manage/handle a group of Timers
 *
 * @attention - Notice that you should initialize all the timers with status = true otherwise it will stay
 * in stand-by
 */
class Timer {

public:

    //**** CONSTRUCTORS ****/

    /**
     * @brief The aim of this constructor is to create a Timer object with all the
     * features specified
     *
     * @attention - Please check ID enum at header file (Timer.h)
     *
     * @param time that must pass to activate the flag
     * @param reference is the time to compare
     * @param id is a reference for the user, check header file (Timer.h)
     * @param flag is activated when time has past
     * @param status marks if the timer is running or not
     */
    Timer(uint32_t time, uint32_t reference, timerType id, bool flag, bool status);

    /**
     * @brief Timer starts with flag and status deactivated
     *
     * @attention - Please check ID enum at header file (Timer.h)
     * @attention - Please check default values
     *
     * @param time that must pass to activate the flag
     * @param reference is the time to compare
     * @param id is a reference for the user, check header file (Timer.h)
     */
    Timer(uint32_t time, uint32_t reference, timerType id);

    /**
     * @brief Timer starts with id : milliseconds
     *
     * @attention - Please check ID enum at header file (Timer.h)
     * @attention - Please check default values
     *
     * @param time that must pass to activate the flag
     * @param reference is the time to compare
     */
    Timer(uint32_t time, uint32_t reference);

    /**
     * @brief Timers starts with reference equal to time
     *
     * @attention - Please check ID enum at header file (Timer.h)
     * @attention - Please check default values
     *
     * @param time that must pass to activate the flag
     */
    Timer(uint32_t time);

    //**** SETTERS ****/

    /**
     * @brief This function sets a new value for Timer time
     *
     * @param newTime change timer frequency
     */
    void setTime(uint32_t newTime);

    /**
     * @brief This function sets a new time reference
     *
     * @param newReference change time reference
     */
    void setReference(uint32_t newReference);

    /**
     * @brief This function sets a new ID for timer
     *
     * @attention Please check the ID at header file (Timer.h)
     *
     * @param newId change id
     */
    void setIdentifier(timerType newId);

    //**** GETTERS ****/

    /**
     * @brief Getter for time variable. This variable defines the frequency for timer flag being activated
     *
     * @return time
     */
    uint32_t getTime();

    /**
     * @brief Getter for reference variable. This variable defines the time reference for time comparison
     *
     * @return time reference
     */
    uint32_t getReference();

    /**
     * @brief Getter for identifier variable
     *
     * @attention - Please check the ID at header file (Timer.h)
     *
     * @return id
     */
    uint32_t getIdentifier();

    /**
     * @brief Getter for status variable
     *
     * @return true if status == true
     */
    bool isRunning();

    /**
     * @brief Getter for flag variable
     *
     * @return true if flag == true
     */
    bool isFlagActivated();

    //**** FLAG ACTIVATION *****/
    /**
     * @brief turn flag = true
     */
    void activateFlag();

    /**
     * @brief turn flag = false
     */
    void deactivateFlag();

    //**** START / STOP ****/

    /**
     * @brief This function starts the timer. It sets status = true
     *
     * @attention StartTime must be past
     *
     * @param startTime reference time at function call
     */
    void start(uint32_t startTime);

    /**
     * @brief This function stops the timer. It sets status = false
     *
     * @attention StopTime must be past
     *
     * @param stopTime reference time at function call
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
