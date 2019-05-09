#include <CppUTest/TestHarness.h>

class Rover
{
public:
    enum Direction {
        North,
        East,
        South,
        West
    };

    Rover(uint maxrow, uint maxcol) : m_maxCol(maxcol), m_maxRow(maxrow)
    {}

    bool setPosition(uint x, uint y)
    {
      if (x < m_maxRow && y < m_maxCol) {
        m_x = x;
        m_y = y;

        return true;
      }
      return false;
    }

    uint getPositionX() const {
      return m_x;
    }

    uint getPositionY() const {
      return m_y;
    }

    Direction getDirection() const {
        return m_dir;
    }

    void setDirection(Direction dir) {
        m_dir = dir;
    }

    void turnLeft() {
      switch (m_dir) {
        case Direction::North:
          m_dir = Direction::West;
          break;
        case Direction::West:
          m_dir = Direction::South;
          break;
      }
    }

private:
    uint m_maxCol;
    uint m_maxRow;
    uint m_x = 0;
    uint m_y = 0;
    Direction m_dir = Direction::North;
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

TEST(RoverTests, getPositionY)
{
    Rover rov(5,5);
    rov.setPosition(3, 3);
    CHECK_EQUAL(3, rov.getPositionY());
}

TEST(RoverTests, getInitialPositionY)
{
  Rover rov(5,5);
  CHECK_EQUAL(0, rov.getPositionY());
}

TEST(RoverTests, getDirection)
{
  Rover rov(5,5);
  CHECK_EQUAL(Rover::Direction::North, rov.getDirection());
}

TEST(RoverTests, setDirection)
{
  Rover rov(5,5);
  rov.setDirection(Rover::Direction::East);
  CHECK_EQUAL(Rover::Direction::East, rov.getDirection());
}

TEST(RoverTests, setAllDirections)
{
  Rover rov(5,5);
  rov.setDirection(Rover::Direction::South);
  CHECK_EQUAL(Rover::Direction::South, rov.getDirection());

  rov.setDirection(Rover::Direction::North);
  CHECK_EQUAL(Rover::Direction::North, rov.getDirection());

  rov.setDirection(Rover::Direction::West);
  CHECK_EQUAL(Rover::Direction::West, rov.getDirection());

  rov.setDirection(Rover::Direction::East);
  CHECK_EQUAL(Rover::Direction::East, rov.getDirection());
}

TEST(RoverTests, turnLeftInitially)
{
  Rover rov(5,5);
  rov.turnLeft();
  CHECK_EQUAL(Rover::Direction::West, rov.getDirection());
}

TEST(RoverTests, turnLeftFromWest)
{
  Rover rov(5,5);
  rov.setDirection(Rover::Direction::West);
  rov.turnLeft();
  CHECK_EQUAL(Rover::Direction::South, rov.getDirection());
}
