#include <CppUTest/TestHarness.h>

class Rover
{
    int m_maxCol;
    int m_maxRow;
public:
    Rover(int maxrow, int maxcol) : m_maxCol(maxcol), m_maxRow(maxrow)
    {}

    bool setPosition(int x, int y)
    {
        return true;
    }
};

TEST_GROUP(RoverTests) {
    void setup() {
    }
    void teardown() {
    }
};

TEST(RoverTests, setPositionInsideBoundaries)
{
    Rover rov(5, 5);
    CHECK_EQUAL(true, rov.setPosition(0, 0));

}


