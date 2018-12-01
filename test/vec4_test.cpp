#include "pch.h"
#include <math/vec4.h>

namespace {

	class Vec4Test : public ::testing::Test {};

	TEST_F(Vec4Test, setDefaultValues)
	{
		math::vec4 vec;

		EXPECT_EQ(vec.x, 0.0f);
		EXPECT_EQ(vec.y, 0.0f);
		EXPECT_EQ(vec.z, 0.0f);
		EXPECT_EQ(vec.w, 0.0f);
	}

	TEST_F(Vec4Test, setScalar)
	{
		math::vec4 vec(5.0f);

		EXPECT_EQ(vec.x, 5.0f);
		EXPECT_EQ(vec.y, 5.0f);
		EXPECT_EQ(vec.z, 5.0f);
		EXPECT_EQ(vec.w, 5.0f);
	}

	TEST_F(Vec4Test, setValuesByContructor)
	{
		math::vec4 vec(10.0f, 20.0f, 30.0f, 40.0f);

		EXPECT_EQ(vec.x, 10.0f);
		EXPECT_EQ(vec.y, 20.0f);
		EXPECT_EQ(vec.z, 30.0f);
		EXPECT_EQ(vec.w, 40.0f);
	}

	TEST_F(Vec4Test, initiateANewVec4ByCopy)
	{
		math::vec4 vec(math::vec4(10.0f, 20.0f, 30.0f, 40.0f));

		EXPECT_EQ(vec.x, 10.0f);
		EXPECT_EQ(vec.y, 20.0f);
		EXPECT_EQ(vec.z, 30.0f);
		EXPECT_EQ(vec.w, 40.0f);
	}

	TEST_F(Vec4Test, setX)
	{
		math::vec4 vec;
		vec.x = 10.0f;

		EXPECT_EQ(vec.x, 10.0f);
	}

	TEST_F(Vec4Test, setY)
	{
		math::vec4 vec;
		vec.y = 20.0f;

		EXPECT_EQ(vec.y, 20.0f);
	}

	TEST_F(Vec4Test, setZ)
	{
		math::vec4 vec;
		vec.z = 30.0f;

		EXPECT_EQ(vec.z, 30.0f);
	}

	TEST_F(Vec4Test, setW)
	{
		math::vec4 vec;
		vec.z = 40.0f;

		EXPECT_EQ(vec.z, 40.0f);
	}

	TEST_F(Vec4Test, addAVec4)
	{
		math::vec4 vec(10.0f, 20.0f, 30.0f, 40.0f);
		vec.add(math::vec4(5.0f, 5.0f, 5.0f, 5.0f));

		EXPECT_EQ(vec.x, 15.0f);
		EXPECT_EQ(vec.y, 25.0f);
		EXPECT_EQ(vec.z, 35.0f);
		EXPECT_EQ(vec.w, 45.0f);
	}

	TEST_F(Vec4Test, subtractAVec4)
	{
		math::vec4 vec(10.0f, 20.0f, 30.0f, 40.0f);
		vec.subtract(math::vec4(5.0f, 5.0f, 5.0f, 5.0f));

		EXPECT_EQ(vec.x, 5.0f);
		EXPECT_EQ(vec.y, 15.0f);
		EXPECT_EQ(vec.z, 25.0f);
		EXPECT_EQ(vec.w, 35.0f);
	}

	TEST_F(Vec4Test, multiplyAVec4)
	{
		math::vec4 vec(10.0f, 20.0f, 30.0f, 40.0f);
		vec.multiply(math::vec4(2.0f, 3.0f, 4.0f, 5.0f));

		EXPECT_EQ(vec.x, 20.0f);
		EXPECT_EQ(vec.y, 60.0f);
		EXPECT_EQ(vec.z, 120.0f);
		EXPECT_EQ(vec.w, 200.0f);
	}

	TEST_F(Vec4Test, divideAVec4)
	{
		math::vec4 vec(10.0f, 20.0f, 30.0f, 40.0f);
		vec.divide(math::vec4(2.0f, 2.0f, 2.0f, 2.0f));

		EXPECT_EQ(vec.x, 5.0f);
		EXPECT_EQ(vec.y, 10.0f);
		EXPECT_EQ(vec.z, 15.0f);
		EXPECT_EQ(vec.w, 20.0f);
	}

	TEST_F(Vec4Test, operatorPlus)
	{
		math::vec4 vec(10.0f, 20.0f, 30.0f, 40.0f);
		vec = vec + math::vec4(5.0f, 5.0f, 5.0f, 5.0f);

		EXPECT_EQ(vec.x, 15.0f);
		EXPECT_EQ(vec.y, 25.0f);
		EXPECT_EQ(vec.z, 35.0f);
		EXPECT_EQ(vec.w, 45.0f);
	}

	TEST_F(Vec4Test, operatorMinus)
	{
		math::vec4 vec(10.0f, 20.0f, 30.0f, 40.0f);
		vec = vec - math::vec4(5.0f, 5.0f, 5.0f, 5.0f);

		EXPECT_EQ(vec.x, 5.0f);
		EXPECT_EQ(vec.y, 15.0f);
		EXPECT_EQ(vec.z, 25.0f);
		EXPECT_EQ(vec.w, 35.0f);
	}

	TEST_F(Vec4Test, operatorTimes)
	{
		math::vec4 vec(10.0f, 20.0f, 30.0f, 40.0f);
		vec = vec * math::vec4(2.0f, 2.0f, 2.0f, 2.0f);

		EXPECT_EQ(vec.x, 20.0f);
		EXPECT_EQ(vec.y, 40.0f);
		EXPECT_EQ(vec.z, 60.0f);
		EXPECT_EQ(vec.w, 80.0f);
	}

	TEST_F(Vec4Test, operatorSlash)
	{
		math::vec4 vec(10.0f, 20.0f, 30.0f, 40.0f);
		vec = vec / math::vec4(2.0f, 2.0f, 2.0f, 2.0f);

		EXPECT_EQ(vec.x, 5.0f);
		EXPECT_EQ(vec.y, 10.0f);
		EXPECT_EQ(vec.z, 15.0f);
		EXPECT_EQ(vec.w, 20.0f);
	}

	TEST_F(Vec4Test, operatorPlusEquals)
	{
		math::vec4 vec(10.0f, 20.0f, 30.0f, 40.0f);
		vec += math::vec4(5.0f, 5.0f, 5.0f, 5.0f);

		EXPECT_EQ(vec.x, 15.0f);
		EXPECT_EQ(vec.y, 25.0f);
		EXPECT_EQ(vec.z, 35.0f);
		EXPECT_EQ(vec.w, 45.0f);
	}

	TEST_F(Vec4Test, operatorMinusEquals)
	{
		math::vec4 vec(10.0f, 20.0f, 30.0f, 40.0f);
		vec -= math::vec4(5.0f, 5.0f, 5.0f, 5.0f);

		EXPECT_EQ(vec.x, 5.0f);
		EXPECT_EQ(vec.y, 15.0f);
		EXPECT_EQ(vec.z, 25.0f);
		EXPECT_EQ(vec.w, 35.0f);
	}

	TEST_F(Vec4Test, operatorTimesEquals)
	{
		math::vec4 vec(10.0f, 20.0f, 30.0f, 40.0f);
		vec *= math::vec4(2.0f, 2.0f, 2.0f, 2.0f);

		EXPECT_EQ(vec.x, 20.0f);
		EXPECT_EQ(vec.y, 40.0f);
		EXPECT_EQ(vec.z, 60.0f);
		EXPECT_EQ(vec.w, 80.0f);
	}

	TEST_F(Vec4Test, operatorSlashEquals)
	{
		math::vec4 vec(10.0f, 20.0f, 30.0f, 40.0f);
		vec /= math::vec4(2.0f, 2.0f, 2.0f, 2.0f);

		EXPECT_EQ(vec.x, 5.0f);
		EXPECT_EQ(vec.y, 10.0f);
		EXPECT_EQ(vec.z, 15.0f);
		EXPECT_EQ(vec.w, 20.0f);
	}

	TEST_F(Vec4Test, operatorEqualsEquals)
	{
		math::vec4 position(10.0f, 20.0f, 30.0f, 40.0f);
		math::vec4 coordinates(10.0f, 20.0f, 30.0f, 40.0f);
		math::vec4 anotherVec(111.0f, 222.0f, 333.0f, 444.0f);

		EXPECT_TRUE(position == coordinates);
		EXPECT_FALSE(position == anotherVec);
	}

	TEST_F(Vec4Test, operatorNotEquals)
	{
		math::vec4 position(10.0f, 20.0f, 30.0f, 40.0f);
		math::vec4 coordinates(10.0f, 20.0f, 30.0f, 40.0f);
		math::vec4 anotherVec(111.0f, 222.0f, 333.0f, 444.0f);

		EXPECT_FALSE(position != coordinates);
		EXPECT_TRUE(position != anotherVec);
	}
}
