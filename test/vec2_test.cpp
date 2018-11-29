#include "pch.h"
#include <math/vec2.h>

namespace {

	class Vec2Test : public ::testing::Test{};

	TEST_F(Vec2Test, setDefaultValues)
	{
		math::vec2 position;
		EXPECT_EQ(position.x, 0.0f);
		EXPECT_EQ(position.y, 0.0f);
	}

	TEST_F(Vec2Test, setValuesByConstructor)
	{
		math::vec2 position(1.5f, 2.0f);
		EXPECT_EQ(position.x, 1.5f);
		EXPECT_EQ(position.y, 2.0f);
	}

	TEST_F(Vec2Test, initiateANewVec2ByCopy)
	{
		math::vec2 position(10.0f, 20.0f);

		math::vec2 coordinates(position);

		EXPECT_EQ(coordinates.x, 10.0f);
		EXPECT_EQ(coordinates.y, 20.0f);
	}

	TEST_F(Vec2Test, setX)
	{
		math::vec2 position;
		position.x = 30.0f;
		EXPECT_EQ(position.x, 30.0f);
	}

	TEST_F(Vec2Test, setY)
	{
		math::vec2 position;
		position.y = 20.0f;
		EXPECT_EQ(position.y, 20.0f);
	}

	TEST_F(Vec2Test, addAVec2)
	{
		math::vec2 position(10.0f, 20.0f);

		math::vec2 coordinates(20.0f, 30.0f);

		position.add(coordinates);

		EXPECT_EQ(position.x, 30.0f);
		EXPECT_EQ(position.y, 50.0f);
	}

	TEST_F(Vec2Test, subtractAVec2)
	{
		math::vec2 position(20.0f, 30.0f);

		math::vec2 coordinates(5.0f, 25.0f);

		position.subtract(coordinates);

		EXPECT_EQ(position.x, 15.0f);
		EXPECT_EQ(position.y, 5.0f);
	}

	TEST_F(Vec2Test, multiplyAVec2)
	{
		math::vec2 position(20.0f, 30.0f);

		math::vec2 coordinates(2.0f, 3.0f);

		position.multiply(coordinates);

		EXPECT_EQ(position.x, 40.0f);
		EXPECT_EQ(position.y, 90.0f);
	}

	TEST_F(Vec2Test, divideAVec2)
	{
		math::vec2 position(20.0f, 30.0f);

		math::vec2 coordinates(2.0f, 3.0f);

		position.divide(coordinates);

		EXPECT_EQ(position.x, 10.0f);
		EXPECT_EQ(position.y, 10.0f);
	}

}
