#include "pch.h"
#include <math/vec2.h>

namespace {

	class Vec2Test : public ::testing::Test{};

	TEST_F(Vec2Test, setDefaultValues)
	{
		math::vec2 vec;

		EXPECT_EQ(vec.x, 0.0f);
		EXPECT_EQ(vec.y, 0.0f);
	}

	TEST_F(Vec2Test, setValuesByConstructor)
	{
		math::vec2 vec(1.5f, 2.0f);

		EXPECT_EQ(vec.x, 1.5f);
		EXPECT_EQ(vec.y, 2.0f);
	}

	TEST_F(Vec2Test, initiateANewVec2ByCopy)
	{
		math::vec2 vec(math::vec2(10.0f, 20.0f));

		EXPECT_EQ(vec.x, 10.0f);
		EXPECT_EQ(vec.y, 20.0f);
	}

	TEST_F(Vec2Test, setX)
	{
		math::vec2 vec;
		vec.x = 30.0f;

		EXPECT_EQ(vec.x, 30.0f);
	}

	TEST_F(Vec2Test, setY)
	{
		math::vec2 vec;
		vec.y = 20.0f;

		EXPECT_EQ(vec.y, 20.0f);
	}

	TEST_F(Vec2Test, addAVec2)
	{
		math::vec2 vec(10.0f, 20.0f);
		vec.add(math::vec2(20.0f, 30.0f));

		EXPECT_EQ(vec.x, 30.0f);
		EXPECT_EQ(vec.y, 50.0f);
	}

	TEST_F(Vec2Test, subtractAVec2)
	{
		math::vec2 vec(20.0f, 30.0f);
		vec.subtract(math::vec2(5.0f, 25.0f));

		EXPECT_EQ(vec.x, 15.0f);
		EXPECT_EQ(vec.y, 5.0f);
	}

	TEST_F(Vec2Test, multiplyAVec2)
	{
		math::vec2 vec(20.0f, 30.0f);
		vec.multiply(math::vec2(2.0f, 3.0f));

		EXPECT_EQ(vec.x, 40.0f);
		EXPECT_EQ(vec.y, 90.0f);
	}

	TEST_F(Vec2Test, divideAVec2)
	{
		math::vec2 vec(20.0f, 30.0f);

		vec.divide(math::vec2(2.0f, 3.0f));

		EXPECT_EQ(vec.x, 10.0f);
		EXPECT_EQ(vec.y, 10.0f);
	}

	TEST_F(Vec2Test, operatorPlus)
	{
		math::vec2 vec(20.0f, 30.0f);

		vec = vec + math::vec2(2.0f, 3.0f);

		EXPECT_EQ(vec.x, 22.0f);
		EXPECT_EQ(vec.y, 33.0f);
	}

	TEST_F(Vec2Test, operatorMinus)
	{
		math::vec2 vec(20.0f, 30.0f);
		vec = vec - math::vec2(2.0f, 3.0f);

		EXPECT_EQ(vec.x, 18.0f);
		EXPECT_EQ(vec.y, 27.0f);
	}

	TEST_F(Vec2Test, operatorTimes)
	{
		math::vec2 vec(20.0f, 30.0f);
		vec = vec * math::vec2(2.0f, 3.0f);

		EXPECT_EQ(vec.x, 40.0f);
		EXPECT_EQ(vec.y, 90.0f);
	}

	TEST_F(Vec2Test, operatorSlash)
	{
		math::vec2 vec(20.0f, 30.0f);
		vec = vec / math::vec2(2.0f, 3.0f);

		EXPECT_EQ(vec.x, 10.0f);
		EXPECT_EQ(vec.y, 10.0f);
	}

	TEST_F(Vec2Test, operatorPlusEquals)
	{
		math::vec2 vec(20.0f, 30.0f);
		vec += math::vec2(2.0f, 3.0f);

		EXPECT_EQ(vec.x, 22.0f);
		EXPECT_EQ(vec.y, 33.0f);
	}

	TEST_F(Vec2Test, operatorMinusEquals)
	{
		math::vec2 vec(20.0f, 30.0f);
		vec -= math::vec2(2.0f, 3.0f);

		EXPECT_EQ(vec.x, 18.0f);
		EXPECT_EQ(vec.y, 27.0f);
	}

	TEST_F(Vec2Test, operatorTimesEquals)
	{
		math::vec2 vec(20.0f, 30.0f);
		vec *= math::vec2(2.0f, 3.0f);

		EXPECT_EQ(vec.x, 40.0f);
		EXPECT_EQ(vec.y, 90.0f);
	}

	TEST_F(Vec2Test, operatorSlashEquals)
	{
		math::vec2 vec(20.0f, 30.0f);
		vec /= math::vec2(2.0f, 3.0f);

		EXPECT_EQ(vec.x, 10.0f);
		EXPECT_EQ(vec.y, 10.0f);
	}

	TEST_F(Vec2Test, operatorEqualsEquals)
	{
		math::vec2 position(20.0f, 30.0f);
		math::vec2 coordinates(20.0f, 30.0f);
		math::vec2 anotherVec(111.0f, 222.0f);

		EXPECT_TRUE(position == coordinates);
		EXPECT_FALSE(position == anotherVec);
	}

	TEST_F(Vec2Test, operatorNotEquals)
	{
		math::vec2 position(20.0f, 30.0f);
		math::vec2 coordinates(20.0f, 30.0f);
		math::vec2 anotherVec(111.0f, 222.0f);

		EXPECT_FALSE(position != coordinates);
		EXPECT_TRUE(position != anotherVec);
	}

}
