//
// Created by presmanes3 on 10/1/20.
//

#include "gtest/gtest.h"
#include "Timer.h"

class TimerTestClass : public testing::Test{

public:

    Timer* timer1 = nullptr;
    Timer* timer2 = nullptr;
    Timer* timer3 = nullptr;
    Timer* timer4 = nullptr;

    Timer* timer5 = nullptr;

    uint32_t timeReference;
    uint32_t newTimeReference;

    uint32_t time;
    uint32_t newTime;

    timerType id;
    timerType newId;


    void SetUp() override{

        timer1 = new Timer(250, 0, MIN, TIMER_FLAG_DEACTIVATED, TIMER_STATUS_ON);
        timer2 = new Timer(130 , 25 , SEC);
        timer3 = new Timer(200, 400);
        timer4 = new Timer(0);

        timeReference = 500;
        newTimeReference = 700;

        time = 100;
        newTime = 1000;

        id = MIN;
        newId = HOUR;

        timer5 = new Timer(time, timeReference, id, TIMER_FLAG_DEACTIVATED, TIMER_STATUS_ON);

    }

    void TearDown() override{

        delete timer1;
        delete timer2;
        delete timer3;
        delete timer4;
    }

};

TEST_F(TimerTestClass, ConstructorOne){

    EXPECT_EQ(250, timer1->getTime());
    EXPECT_EQ(0, timer1->getReference());
    EXPECT_EQ(MIN, timer1->getIdentifier());

    EXPECT_EQ(TIMER_FLAG_DEACTIVATED, timer1->isFlagActivated());
    EXPECT_EQ(TIMER_STATUS_ON, timer1->isRunning());
}


TEST_F(TimerTestClass, ConstructorTwo){

    EXPECT_EQ(130, timer2->getTime());
    EXPECT_EQ(25, timer2->getReference());
    EXPECT_EQ(SEC, timer2->getIdentifier());

    EXPECT_EQ(TIMER_FLAG_DEACTIVATED, timer2->isFlagActivated());
    EXPECT_EQ(TIMER_STATUS_OFF, timer2->isRunning());
}

TEST_F(TimerTestClass, ConstructorThree){

    EXPECT_EQ(200, timer3->getTime());
    EXPECT_EQ(400, timer3->getReference());
    EXPECT_EQ(MIL, timer3->getIdentifier());

    EXPECT_EQ(TIMER_FLAG_DEACTIVATED, timer3->isFlagActivated());
    EXPECT_EQ(TIMER_STATUS_OFF, timer3->isRunning());
}

TEST_F(TimerTestClass, ConstructorFour){

    EXPECT_EQ(0, timer4->getTime());
    EXPECT_EQ(0, timer4->getReference());
    EXPECT_EQ(MIL, timer4->getIdentifier());

    EXPECT_EQ(TIMER_FLAG_DEACTIVATED, timer4->isFlagActivated());
    EXPECT_EQ(TIMER_STATUS_OFF, timer4->isRunning());
}

TEST_F(TimerTestClass, timeSetter){
    timer5->setTime(newTime);
    EXPECT_EQ(newTime, timer5->getTime());
}

TEST_F(TimerTestClass, timeReferenceSetter){
    timer5->setReference(newTimeReference);
    EXPECT_EQ(newTimeReference, timer5->getReference());
}

TEST_F(TimerTestClass, identifierSetter){
    timer5->setIdentifier(newId);
    EXPECT_EQ(newId, timer5->getIdentifier());
}

TEST_F(TimerTestClass, timeGetter){
    EXPECT_EQ(time, timer5->getTime());
}

TEST_F(TimerTestClass, timeReferenceGetter){
    EXPECT_EQ(timeReference, timer5->getReference());
}

TEST_F(TimerTestClass, identifierGetter){
    EXPECT_EQ(id,timer5->getIdentifier());
}

TEST_F(TimerTestClass, isRunningTest){
  EXPECT_EQ(TIMER_STATUS_ON, timer5->isRunning());
  EXPECT_NE(TIMER_STATUS_OFF, timer5->isRunning());
}

TEST_F(TimerTestClass, isFlagActivatedTest){
  EXPECT_EQ(TIMER_FLAG_ACTIVATED, timer5->isFlagActivated());
  EXPECT_NE(TIMER_FLAG_DEACTIVATED, timer5->isFlagActivated());
}

TEST_F(TimerTestClass, startTest){
  timer5->start(timeReference);

  EXPECT_EQ(timeReference, timer5->getReference());
  EXPECT_EQ(TIMER_STATUS_ON, timer5->isRunning());
}

TEST_F(TimerTestClass, stopTest){
  timer5->stop(newTimeReference);

  EXPECT_EQ(newTimeReference, timer5->getReference());
  EXPECT_EQ(TIMER_STATUS_OFF, timer5->isRunning());
}