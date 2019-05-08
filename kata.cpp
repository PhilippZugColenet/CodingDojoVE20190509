#include <CppUTest/TestHarness.h>

int doSomething(std::string input) {
    return 0;
}

TEST_GROUP(sampleGroup) {
    void setup() {
    }
    void teardown() {
    }
};

TEST(sampleGroup, it_should_just_work)
{
    CHECK_EQUAL(0, doSomething(""))
}

TEST(sampleGroup, fixMe)
{
    CHECK_EQUAL(5, doSomething("Hello"))
}

