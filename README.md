# TimerManager_lib

## Description 
TimerManager_lib  is a library created to manage Timers used commonly while working with microcontrollers. 

While talking about microcontrollers it is mandatory to speak about Timers.
Timers are used to automatize processes, for example switching a led state every 500ms, or reading a sensor every hour.

However, this library has been created to be **independent from the time source you are using**. Time reference can be set by millis(), system clock, a RTC or whatever.

### Notes
- TimerManager uses a TimerPool in order to manager a set of Timers at a time.
- Timer Pool is just a Timer Array.
- [UnitTest](src/UnitTest)
- [Examples](src/Examples)

## Features
- Create Timer
- Create Timer Manager
- Activate/Deactivate a Timer
- Activate/Deactivate a TimerManager
- Deactivate Timer after time has past
- Copy timers
- Clear Timer Pool
- Getter/Setter on every variable
- Get time difference between two references
- Flag based alert

## Known Bugs
- [ ] If maximum number of timers is bigger than timer pool size, program may break.

## TODO List
- [ ] Select Flag mode (activate at true/false)

- [ ] Create new Timer based classes

- [ ] Add examples in documentation


## Author Information
[Github](https://github.com/Presmanes3)

[Mail] - Premanes3@gmail.com

