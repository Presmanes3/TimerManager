//
// Created by presmanes3 on 10/1/20.
//

#include "gtest/gtest.h"
#include "TimerManager.h"
#include "Timer.h"


class TimerManagerTest : public testing::Test{

public:

    TimerManager* m1 = nullptr;
    TimerManager* m2 = nullptr;
    TimerManager* m3 = nullptr;

    uint8_t maxTimers = 25;

    Timer* pool[25];

    Timer* t = nullptr;
    Timer* r = nullptr;

    uint32_t timeReference;
    uint32_t newTimeReference;

    uint32_t time;
    uint32_t newTime;

    timerType id;
    timerType newId;


    void SetUp() override{

        timeReference = 500;
        newTimeReference = 700;

        time = 100;
        newTime = 1000;

        id = MIN;
        newId = HOUR;

       m1 = new TimerManager((char*)"Manager1", pool,maxTimers);

       m1->clearPool(pool, maxTimers);

       m2 = new TimerManager((char*)"Manager2", pool);
       m3 = new TimerManager(pool);

       t = new Timer(time, timeReference, id, true, true);
    }

    void TearDown() override {

        delete m1;
        delete m2;
        delete m3;

        delete t;
        delete r;
    }


};

/**** CONSTRUCTORS ****/

TEST_F(TimerManagerTest, Constructor1){
    char* s = (char*)"Manager1";

    EXPECT_EQ(0, strcmp(s, m1->getIdentifier()));
    EXPECT_EQ(maxTimers, m1->getMaxTimers());

    for(uint8_t x = 0; x < m1->getMaxTimers(); x++){
        EXPECT_EQ(nullptr, m1->getTimer(x));
    }

    EXPECT_EQ(TIMER_MANAGER_ACTIVATED, m1->isRunning());
}

TEST_F(TimerManagerTest, Constructor2){
    char* s = (char*)"Manager2";

    EXPECT_EQ(0, strcmp(s, m2->getIdentifier()));
    EXPECT_EQ(TIMER_MANAGER_DEFAULT_MAX_TIMERS, m2->getMaxTimers());

    for(uint8_t x = 0; x < m2->getMaxTimers(); x++){
        EXPECT_EQ(nullptr, m2->getTimer(x));
    }

    EXPECT_EQ(TIMER_MANAGER_ACTIVATED, m2->isRunning());
}

TEST_F(TimerManagerTest, Constructor3){
    char* s = (char*)TIMER_MANAGER_DEFAULT_IDENTIFIER;

    EXPECT_EQ(0, strcmp(s, m3->getIdentifier()));
    EXPECT_EQ(TIMER_MANAGER_DEFAULT_MAX_TIMERS, m3->getMaxTimers());

    for(uint8_t x = 0; x < m3->getMaxTimers(); x++){
        EXPECT_EQ(nullptr, m3->getTimer(x));
    }

    EXPECT_EQ(TIMER_MANAGER_ACTIVATED, m3->isRunning());
}


/**** SETTERS ****/

TEST_F(TimerManagerTest, setTimerTest){
    m1->setTimer(t, 0);

    EXPECT_EQ(t, m1->getTimer(0));
}

TEST_F(TimerManagerTest, setTimerPoolTest){
    Timer* p1[25];

    EXPECT_NE(p1, m1->getTimerPool());

    m1->setTimerPool(p1, 25);

    EXPECT_EQ(p1, m1->getTimerPool());
}

TEST_F(TimerManagerTest, addTimerTest){
    m1->addTimer(t);
    EXPECT_EQ(t, m1->getTimer(0));

    Timer* test = new Timer(25);

    m1->addTimer(test);
    EXPECT_EQ(test, m1->getTimer(1));

    delete test;
}

TEST_F(TimerManagerTest, setIdentifierTest){
    char* newid = (char*)"Charo";

    m1->setIdentifier(newid);
    EXPECT_EQ(0, strcmp(newid, m1->getIdentifier()));
}

TEST_F(TimerManagerTest, setMaxTimersTest){
    uint8_t newVal = 2;
    m1->setMaxTimers(2);

    EXPECT_EQ(2, m1->getMaxTimers());

    newVal = 200;
    m1->setMaxTimers(newVal);

    EXPECT_NE(0, m1->getMaxTimers());  // TODO change when set limit for maximum value of maxTimers
}

TEST_F(TimerManagerTest, startTest){
    m1->start();

    EXPECT_EQ(true, m1->isRunning());
}

TEST_F(TimerManagerTest, stopTest){
    m1->stop();

    EXPECT_EQ(false, m1->isRunning());
}

/**** GETTERS ****/
TEST_F(TimerManagerTest, getTimerPoolTest){
    Timer* p1[25];

    EXPECT_NE(p1, m1->getTimerPool());

    m1->setTimerPool(p1, 25);

    EXPECT_EQ(p1, m1->getTimerPool());

    Timer* p2[70];

    EXPECT_NE(p2, m1->getTimerPool());
}

TEST_F(TimerManagerTest, getTimerTest){

    r = new Timer(75);
    m1->addTimer(t);
    m1->addTimer(r);
    m1->addTimer(r);

    EXPECT_EQ(t, m1->getTimer(0));
    EXPECT_NE(t, m1->getTimer(1));
    EXPECT_EQ(r, m1->getTimer(1));
    EXPECT_EQ(r, m1->getTimer(2));
}

TEST_F(TimerManagerTest, getIdentifierTest){
    EXPECT_EQ(0, strcmp("Manager1", m1->getIdentifier()));
}

TEST_F(TimerManagerTest, isRunningTest){
    m1->start();
    EXPECT_EQ(true, m1->isRunning());

    m1->stop();
    EXPECT_EQ(false, m1->isRunning());
}

TEST_F(TimerManagerTest, getMaxTimersTest){
    EXPECT_EQ(maxTimers, m1->getMaxTimers());
}

/**** UTILITIES ****/

TEST_F(TimerManagerTest, checkTimerTest0){
    /**
     * @brief Test perfect conditions
     *
     */

    r = new Timer(10, 0, MIL, false, true);
    uint32_t ref1 = 1000;

    EXPECT_EQ(true, m1->checkTimer(r, ref1, false));
    EXPECT_EQ(true, r->isFlagActivated());
    EXPECT_EQ(true, r->isRunning());
}

TEST_F(TimerManagerTest, checkTimerTest1){
    /**
     * @brief Test with reference < time
     *
     */

    r = new Timer(1001, 0, MIL, false, true);
    uint32_t ref1 = 1000;

    EXPECT_EQ(false, m1->checkTimer(r, ref1, false));
    EXPECT_EQ(false, r->isFlagActivated());
    EXPECT_EQ(true, r->isRunning());
}

TEST_F(TimerManagerTest, checkTimerTest2){
    /**
     * @brief Test with status = false
     */

    r = new Timer(10, 0, MIL, false, false);
    uint32_t ref1 = 1000;

    EXPECT_EQ(false, m1->checkTimer(r, ref1, false));
    EXPECT_EQ(false, r->isFlagActivated());
    EXPECT_EQ(false, r->isRunning());
}

TEST_F(TimerManagerTest, checkTimerTest3){
    /**
     * @brief Test with initialRef > ref
     */

    r = new Timer(1000, 2000, MIL, false, true);
    uint32_t ref1 = 1000;

    EXPECT_EQ(true, m1->checkTimer(r, ref1, false));
    EXPECT_EQ(true, r->isFlagActivated());
    EXPECT_EQ(true, r->isRunning());
}

TEST_F(TimerManagerTest, checkTimerTest4){
    /**
     * @brief Test with initialRef > ref and time > difference(ref, initialRed)
     */

    r = new Timer(1500, 2000, MIL, false, true);
    uint32_t ref1 = 1000;

    EXPECT_EQ(false, m1->checkTimer(r, ref1, false));
    EXPECT_EQ(false, r->isFlagActivated());
    EXPECT_EQ(true, r->isRunning());
}

TEST_F(TimerManagerTest, checkTimerTest5){
    /**
     * @brief Test deactivating the Timer at the end
     */

    r = new Timer(10, 0, MIL, false, true);
    uint32_t ref1 = 1000;

    EXPECT_EQ(true, m1->checkTimer(r, ref1, true));
    EXPECT_EQ(true, r->isFlagActivated());
    EXPECT_EQ(false, r->isRunning());
}

TEST_F(TimerManagerTest, getDifferenceTest){
    uint32_t a = 1000;
    uint32_t b = 2000;
    uint32_t c = 500;

    EXPECT_EQ(0, m1->getTimeDifference(a,a));
    EXPECT_EQ(1000, m1->getTimeDifference(a,b));
    EXPECT_EQ(1000, m1->getTimeDifference(b,a));
    EXPECT_EQ(1500, m1->getTimeDifference(b,c));
    EXPECT_EQ(1500, m1->getTimeDifference(c,b));
}

TEST_F(TimerManagerTest, copyTimerTest){
    r = new Timer(50);
    EXPECT_NE(t->getIdentifier(), r->getIdentifier());
    EXPECT_NE(t->getTime(), r->getTime());
    EXPECT_NE(t->getReference(), r->getReference());

    m1->copyTimer(t,r);
    EXPECT_EQ(t->getIdentifier(), r->getIdentifier());
    EXPECT_EQ(t->getTime(), r->getTime());
    EXPECT_EQ(t->getReference(), r->getReference());
}

TEST_F(TimerManagerTest, clearPoolTest){
    Timer* p[25];

    for(uint8_t x = 0; x < 25; x++){
        p[x] = new Timer(x);
    }

    EXPECT_NE(nullptr, p[0]);

    m1->clearPool(p, 25);

    EXPECT_EQ(nullptr, p[0]);
}