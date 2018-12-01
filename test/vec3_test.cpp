#include "pch.h"
#include <math/vec3.h>

namespace {

	class Vec3Test : public ::testing::Test {};

	TEST_F(Vec3Test, setDefaultValues)
	{
		math::vec3 vec;

		EXPECT_EQ(vec.x, 0.0f);
		EXPECT_EQ(vec.y, 0.0f);
		EXPECT_EQ(vec.z, 0.0f);
	}

	TEST_F(Vec3Test, setScalar)
	{
		math::vec3 vec(5.0f);

		EXPECT_EQ(vec.x, 5.0f);
		EXPECT_EQ(vec.y, 5.0f);
		EXPECT_EQ(vec.z, 5.0f);
	}

	TEST_F(Vec3Test, setValuesByConstructor)
	{
		math::vec3 vec(10.0, 20.0f, 30.0f);

		EXPECT_EQ(vec.x, 10.0f);
		EXPECT_EQ(vec.y, 20.0f);
		EXPECT_EQ(vec.z, 30.0f);
	}

	TEST_F(Vec3Test, initiateANewVec3ByCopy)
	{
		math::vec3 vec(math::vec3(10.0, 20.0f, 30.0f));

		EXPECT_EQ(vec.x, 10.0f);
		EXPECT_EQ(vec.y, 20.0f);
		EXPECT_EQ(vec.z, 30.0f);
	}

	TEST_F(Vec3Test, setX)
	{
		math::vec3 vec;
		vec.x = 30.0f;

		EXPECT_EQ(vec.x, 30.0f);
	}

	TEST_F(Vec3Test, setY)
	{
		math::vec3 vec;
		vec.y = 20.0f;

		EXPECT_EQ(vec.y, 20.0f);
	}

	TEST_F(Vec3Test, setZ)
	{
		math::vec3 vec;
		vec.z = 10.0f;

		EXPECT_EQ(vec.z, 10.0f);
	}

	TEST_F(Vec3Test, addAVec3)
	{
		math::vec3 vec(10.0f, 20.0f, 30.0f);
		vec.add(math::vec3(20.0f, 30.0f, 40.0f));

		EXPECT_EQ(vec.x, 30.0f);
		EXPECT_EQ(vec.y, 50.0f);
		EXPECT_EQ(vec.z, 70.0f);
	}

	TEST_F(Vec3Test, subtractAVec3)
	{
		math::vec3 vec(10.0f, 20.0f, 30.0f);
		vec.subtract(math::vec3(4.0f, 5.0f, 6.0f));

		EXPECT_EQ(vec.x, 6.0f);
		EXPECT_EQ(vec.y, 15.0f);
		EXPECT_EQ(vec.z, 24.0f);
	}

	TEST_F(Vec3Test, multiplyAVec3)
	{
		math::vec3 vec(10.0f, 20.0f, 30.0f);
		vec.multiply(math::vec3(4.0f, 5.0f, 3.0f));

		EXPECT_EQ(vec.x, 40.0f);
		EXPECT_EQ(vec.y, 100.0f);
		EXPECT_EQ(vec.z, 90.0f);
	}

	TEST_F(Vec3Test, divideAVec3)
	{
		math::vec3 vec(10.0f, 20.0f, 30.0f);
		vec.divide(math::vec3(5.0f, 5.0f, 3.0f));

		EXPECT_EQ(vec.x, 2.0f);
		EXPECT_EQ(vec.y, 4.0f);
		EXPECT_EQ(vec.z, 10.0f);
	}

	TEST_F(Vec3Test, operatorPlus)
	{
		math::vec3 vec(20.0f, 30.0f, 40.0f);
		vec = vec + math::vec3(2.0f, 3.0f, 4.0f);

		EXPECT_EQ(vec.x, 22.0f);
		EXPECT_EQ(vec.y, 33.0f);
		EXPECT_EQ(vec.z, 44.0f);
	}

	TEST_F(Vec3Test, operatorMinus)
	{
		math::vec3 vec(20.0f, 30.0f, 40.0f);
		vec = vec - math::vec3(2.0f, 3.0f, 4.0f);

		EXPECT_EQ(vec.x, 18.0f);
		EXPECT_EQ(vec.y, 27.0f);
		EXPECT_EQ(vec.z, 36.0f);
	}

	TEST_F(Vec3Test, operatorTimes)
	{
		math::vec3 vec(20.0f, 30.0f, 40.0f);
		vec = vec * math::vec3(2.0f, 3.0f, 4.0f);

		EXPECT_EQ(vec.x, 40.0f);
		EXPECT_EQ(vec.y, 90.0f);
		EXPECT_EQ(vec.z, 160.0f);
	}

	TEST_F(Vec3Test, operatorSlash)
	{
		math::vec3 vec(20.0f, 30.0f, 40.0f);
		vec = vec / math::vec3(2.0f, 3.0f, 4.0f);

		EXPECT_EQ(vec.x, 10.0f);
		EXPECT_EQ(vec.y, 10.0f);
		EXPECT_EQ(vec.z, 10.0f);
	}

	TEST_F(Vec3Test, operatorPlusEquals)
	{
		math::vec3 vec(20.0f, 30.0f, 40.0f);
		vec += math::vec3(2.0f, 3.0f, 4.0f);

		EXPECT_EQ(vec.x, 22.0f);
		EXPECT_EQ(vec.y, 33.0f);
		EXPECT_EQ(vec.z, 44.0f);
	}

	TEST_F(Vec3Test, operatorMinusEquals)
	{
		math::vec3 vec(20.0f, 30.0f, 40.0f);
		vec -= math::vec3(2.0f, 3.0f, 4.0f);

		EXPECT_EQ(vec.x, 18.0f);
		EXPECT_EQ(vec.y, 27.0f);
		EXPECT_EQ(vec.z, 36.0f);
	}

	TEST_F(Vec3Test, operatorTimesEquals)
	{
		math::vec3 vec(20.0f, 30.0f, 40.0f);
		vec *= math::vec3(2.0f, 3.0f, 4.0f);

		EXPECT_EQ(vec.x, 40.0f);
		EXPECT_EQ(vec.y, 90.0f);
		EXPECT_EQ(vec.z, 160.0f);
	}

	TEST_F(Vec3Test, operatorSlashEquals)
	{
		math::vec3 vec(20.0f, 30.0f, 40.0f);
		vec /= math::vec3(2.0f, 3.0f, 4.0f);

		EXPECT_EQ(vec.x, 10.0f);
		EXPECT_EQ(vec.y, 10.0f);
		EXPECT_EQ(vec.z, 10.0f);
	}

	TEST_F(Vec3Test, operatorEqualsEquals)
	{
		math::vec3 position(10.0f, 20.0f, 30.0f);
		math::vec3 coordinates(10.0f, 20.0f, 30.0f);
		math::vec3 anotherVec(111.0f, 222.0f, 333.0f);

		EXPECT_TRUE(position == coordinates);
		EXPECT_FALSE(position == anotherVec);
	}

	TEST_F(Vec3Test, operatorNotEquals)
	{
		math::vec3 position(10.0f, 20.0f, 30.0f);
		math::vec3 coordinates(10.0f, 20.0f, 30.0f);
		math::vec3 anotherVec(111.0f, 222.0f, 333.0f);

		EXPECT_FALSE(position != coordinates);
		EXPECT_TRUE(position != anotherVec);
	}

}
