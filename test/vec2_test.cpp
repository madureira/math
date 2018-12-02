#include "pch.h"
#include <math/vec2.h>

namespace {

	class Vec2Test : public ::testing::Test{};

	TEST_F(Vec2Test, initByDefaultValues)
	{
		math::vec2 vec;

		EXPECT_EQ(vec.x, 0.0f);
		EXPECT_EQ(vec.y, 0.0f);
	}

	TEST_F(Vec2Test, initByScalar)
	{
		math::vec2 vec(5.0f);

		EXPECT_EQ(vec.x, 5.0f);
		EXPECT_EQ(vec.y, 5.0f);
	}

	TEST_F(Vec2Test, initBySettingValues)
	{
		math::vec2 vec(1.5f, 2.0f);

		EXPECT_EQ(vec.x, 1.5f);
		EXPECT_EQ(vec.y, 2.0f);
	}

	TEST_F(Vec2Test, initByVec2Copy)
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

	TEST_F(Vec2Test, addAScalar)
	{
		math::vec2 vec(10.0f, 20.0f);
		vec.add(15.0f);

		EXPECT_EQ(vec.x, 25.0f);
		EXPECT_EQ(vec.y, 35.0f);
	}

	TEST_F(Vec2Test, subtractByScalar)
	{
		math::vec2 vec(20.0f, 30.0f);
		vec.subtract(4.0f);

		EXPECT_EQ(vec.x, 16.0f);
		EXPECT_EQ(vec.y, 26.0f);
	}

	TEST_F(Vec2Test, multiplyByScalar)
	{
		math::vec2 vec(20.0f, 30.0f);
		vec.multiply(2.0f);

		EXPECT_EQ(vec.x, 40.0f);
		EXPECT_EQ(vec.y, 60.0f);
	}

	TEST_F(Vec2Test, divideByScalar)
	{
		math::vec2 vec(20.0f, 30.0f);
		vec.divide(2.0f);

		EXPECT_EQ(vec.x, 10.0f);
		EXPECT_EQ(vec.y, 15.0f);
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

	TEST_F(Vec2Test, operatorPlusWithScalar)
	{
		math::vec2 vec(20.0f, 30.0f);

		vec = vec + 5.0f;

		EXPECT_EQ(vec.x, 25.0f);
		EXPECT_EQ(vec.y, 35.0f);
	}

	TEST_F(Vec2Test, operatorMinusWithScalar)
	{
		math::vec2 vec(20.0f, 30.0f);

		vec = vec - 5.0f;

		EXPECT_EQ(vec.x, 15.0f);
		EXPECT_EQ(vec.y, 25.0f);
	}

	TEST_F(Vec2Test, operatorTimesWithScalar)
	{
		math::vec2 vec(20.0f, 30.0f);

		vec = vec * 2.0f;

		EXPECT_EQ(vec.x, 40.0f);
		EXPECT_EQ(vec.y, 60.0f);
	}

	TEST_F(Vec2Test, operatorSlashWithScalar)
	{
		math::vec2 vec(20.0f, 30.0f);

		vec = vec / 2.0f;

		EXPECT_EQ(vec.x, 10.0f);
		EXPECT_EQ(vec.y, 15.0f);
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

	TEST_F(Vec2Test, operatorPlusEqualsWithScalar)
	{
		math::vec2 vec(20.0f, 30.0f);
		vec += 10.0f;

		EXPECT_EQ(vec.x, 30.0f);
		EXPECT_EQ(vec.y, 40.0f);
	}

	TEST_F(Vec2Test, operatorMinusEqualsWithScalar)
	{
		math::vec2 vec(20.0f, 30.0f);
		vec -= 5.0f;

		EXPECT_EQ(vec.x, 15.0f);
		EXPECT_EQ(vec.y, 25.0f);
	}

	TEST_F(Vec2Test, operatorTimesEqualsWithScalar)
	{
		math::vec2 vec(20.0f, 30.0f);
		vec *= 2.0f;

		EXPECT_EQ(vec.x, 40.0f);
		EXPECT_EQ(vec.y, 60.0f);
	}

	TEST_F(Vec2Test, operatorSlashEqualsWithScalar)
	{
		math::vec2 vec(20.0f, 30.0f);
		vec /= 2.0f;

		EXPECT_EQ(vec.x, 10.0f);
		EXPECT_EQ(vec.y, 15.0f);
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

	TEST_F(Vec2Test, operatorLessThan)
	{
		math::vec2 vecOne(10.0f, 20.0f);
		math::vec2 vecTwo(20.0f, 30.0f);

		EXPECT_TRUE(vecOne < vecTwo);
	}

	TEST_F(Vec2Test, operatorLessThanOrEquals)
	{
		math::vec2 vecOne(10.0f, 20.0f);
		math::vec2 vecTwo(20.0f, 30.0f);
		math::vec2 vecThree(10.0f, 20.0f);

		EXPECT_TRUE(vecOne <= vecTwo);
		EXPECT_TRUE(vecOne <= vecThree);
	}

	TEST_F(Vec2Test, operatorGreaterThan)
	{
		math::vec2 vecOne(20.0f, 30.0f);
		math::vec2 vecTwo(10.0f, 20.0f);

		EXPECT_TRUE(vecOne > vecTwo);
	}

	TEST_F(Vec2Test, operatorGreaterThanOrEquals)
	{
		math::vec2 vecOne(20.0f, 30.0f);
		math::vec2 vecTwo(10.0f, 20.0f);
		math::vec2 vecThree(20.0f, 30.0f);

		EXPECT_TRUE(vecOne >= vecTwo);
		EXPECT_TRUE(vecOne >= vecThree);
	}

	TEST_F(Vec2Test, dotProduct)
	{
		math::vec2 vecOne(20.0f, 30.0f);
		math::vec2 vecTwo(3.0f, 2.0f);

		float dotProduct = vecOne.dot(vecTwo);

		EXPECT_EQ(dotProduct, 120);
	}

	TEST_F(Vec2Test, magnitude)
	{
		math::vec2 vec(3.0f, 4.0f);

		float magnitude = vec.magnitude();

		EXPECT_EQ(magnitude, 5.0f);
	}

	TEST_F(Vec2Test, distance)
	{
		math::vec2 vecOne(3.0f, 4.0f);
		math::vec2 vecTwo(6.0f, 0.0f);

		float distance = vecOne.distance(vecTwo);

		EXPECT_EQ(distance, 5.0f);
	}

	TEST_F(Vec2Test, normalize)
	{
		math::vec2 vec(3.0f, 4.0f);

		math::vec2 normalized = vec.normalize();

		EXPECT_EQ(normalized.x, 0.6f);
		EXPECT_EQ(normalized.y, 0.8f);
	}

}
