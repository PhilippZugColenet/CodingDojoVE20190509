#include <CppUTest/TestHarness.h>

class Rover
{
    uint m_maxCol;
    uint m_maxRow;
    uint m_curRow = 0;
    uint m_curCol;
public:
    Rover(uint maxrow, uint maxcol) : m_maxCol(maxcol), m_maxRow(maxrow)
    {}

    bool setPosition(uint x, uint y)
    {
      if (x < m_maxRow && y < m_maxCol) {
        m_curRow = x;
        m_curCol = y;

        return true;
      }
      return false;
    }

    uint getPositionX() {
      return m_curRow;
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

TEST(RoverTests, setPositionOutsideBoundariesShouldFail)
{
    Rover rov(5, 5);
    CHECK_EQUAL(false, rov.setPosition(6, 4));
    CHECK_EQUAL(false, rov.setPosition(4, 6));
    CHECK_EQUAL(false, rov.setPosition(5, 5));
    CHECK_EQUAL(false, rov.setPosition(6, 7));
}

TEST(RoverTests, getPositionX)
{
    Rover rov(5,5);
    rov.setPosition(3, 3);
    CHECK_EQUAL(3, rov.getPositionX());
}

TEST(RoverTests, getInitialPositionX)
{
  Rover rov(5,5);
  CHECK_EQUAL(0, rov.getPositionX());
}
