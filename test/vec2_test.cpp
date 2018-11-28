#include <gtest/gtest.h>
#include <math/vec2.h>

namespace {

  class Vec2Test : public ::testing::Test{};

  TEST_F(Vec2Test, setValues)
  {
    math::vec2 position(1.5f, 2.0f);
    EXPECT_EQ(position.x, 1.5f);
    EXPECT_EQ(position.y, 2.0f);
  }

}
