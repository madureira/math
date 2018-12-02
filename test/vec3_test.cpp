#include "pch.h"
#include <math/vec3.h>

namespace {

	class Vec3Test : public ::testing::Test {};

	TEST_F(Vec3Test, initByDefaultValues)
	{
		math::vec3 vec;

		EXPECT_EQ(vec.x, 0.0f);
		EXPECT_EQ(vec.y, 0.0f);
		EXPECT_EQ(vec.z, 0.0f);
	}

	TEST_F(Vec3Test, initByScalar)
	{
		math::vec3 vec(5.0f);

		EXPECT_EQ(vec.x, 5.0f);
		EXPECT_EQ(vec.y, 5.0f);
		EXPECT_EQ(vec.z, 5.0f);
	}

	TEST_F(Vec3Test, initBySettingValues)
	{
		math::vec3 vec(10.0, 20.0f, 30.0f);

		EXPECT_EQ(vec.x, 10.0f);
		EXPECT_EQ(vec.y, 20.0f);
		EXPECT_EQ(vec.z, 30.0f);
	}

	TEST_F(Vec3Test, initByVec3Copy)
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

	TEST_F(Vec3Test, addAScalar)
	{
		math::vec3 vec(10.0f, 20.0f, 30.0f);
		vec.add(5.0f);

		EXPECT_EQ(vec.x, 15.0f);
		EXPECT_EQ(vec.y, 25.0f);
		EXPECT_EQ(vec.z, 35.0f);
	}

	TEST_F(Vec3Test, subtractByScalar)
	{
		math::vec3 vec(10.0f, 20.0f, 30.0f);
		vec.subtract(5.0f);

		EXPECT_EQ(vec.x, 5.0f);
		EXPECT_EQ(vec.y, 15.0f);
		EXPECT_EQ(vec.z, 25.0f);
	}

	TEST_F(Vec3Test, multiplyByScalar)
	{
		math::vec3 vec(10.0f, 20.0f, 30.0f);
		vec.multiply(2.0f);

		EXPECT_EQ(vec.x, 20.0f);
		EXPECT_EQ(vec.y, 40.0f);
		EXPECT_EQ(vec.z, 60.0f);
	}

	TEST_F(Vec3Test, divideByScalar)
	{
		math::vec3 vec(10.0f, 20.0f, 30.0f);
		vec.divide(2.0f);

		EXPECT_EQ(vec.x, 5.0f);
		EXPECT_EQ(vec.y, 10.0f);
		EXPECT_EQ(vec.z, 15.0f);
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

	TEST_F(Vec3Test, operatorPlusWithScalar)
	{
		math::vec3 vec(20.0f, 30.0f, 40.0f);
		vec = vec + 5.0f;

		EXPECT_EQ(vec.x, 25.0f);
		EXPECT_EQ(vec.y, 35.0f);
		EXPECT_EQ(vec.z, 45.0f);
	}

	TEST_F(Vec3Test, operatorMinusWithScalar)
	{
		math::vec3 vec(20.0f, 30.0f, 40.0f);
		vec = vec - 5.0f;

		EXPECT_EQ(vec.x, 15.0f);
		EXPECT_EQ(vec.y, 25.0f);
		EXPECT_EQ(vec.z, 35.0f);
	}

	TEST_F(Vec3Test, operatorTimesWithScalar)
	{
		math::vec3 vec(20.0f, 30.0f, 40.0f);
		vec = vec * 2.0f;

		EXPECT_EQ(vec.x, 40.0f);
		EXPECT_EQ(vec.y, 60.0f);
		EXPECT_EQ(vec.z, 80.0f);
	}

	TEST_F(Vec3Test, operatorSlashWithScalar)
	{
		math::vec3 vec(20.0f, 30.0f, 40.0f);
		vec = vec / 2.0f;

		EXPECT_EQ(vec.x, 10.0f);
		EXPECT_EQ(vec.y, 15.0f);
		EXPECT_EQ(vec.z, 20.0f);
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

	TEST_F(Vec3Test, operatorPlusEqualsWithScalar)
	{
		math::vec3 vec(20.0f, 30.0f, 40.0f);
		vec += 5.0f;

		EXPECT_EQ(vec.x, 25.0f);
		EXPECT_EQ(vec.y, 35.0f);
		EXPECT_EQ(vec.z, 45.0f);
	}

	TEST_F(Vec3Test, operatorMinusEqualsWithScalar)
	{
		math::vec3 vec(20.0f, 30.0f, 40.0f);
		vec -= 5.0f;

		EXPECT_EQ(vec.x, 15.0f);
		EXPECT_EQ(vec.y, 25.0f);
		EXPECT_EQ(vec.z, 35.0f);
	}

	TEST_F(Vec3Test, operatorTimesEqualsWithScalar)
	{
		math::vec3 vec(20.0f, 30.0f, 40.0f);
		vec *= 2.0f;

		EXPECT_EQ(vec.x, 40.0f);
		EXPECT_EQ(vec.y, 60.0f);
		EXPECT_EQ(vec.z, 80.0f);
	}

	TEST_F(Vec3Test, operatorSlashEqualsWithScalar)
	{
		math::vec3 vec(20.0f, 30.0f, 40.0f);
		vec /= 2.0f;

		EXPECT_EQ(vec.x, 10.0f);
		EXPECT_EQ(vec.y, 15.0f);
		EXPECT_EQ(vec.z, 20.0f);
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

	TEST_F(Vec3Test, operatorLessThan)
	{
		math::vec3 vecOne(10.0f, 20.0f, 30.0f);
		math::vec3 vecTwo(20.0f, 30.0f, 40.0f);

		EXPECT_TRUE(vecOne < vecTwo);
	}

	TEST_F(Vec3Test, operatorLessThanOrEquals)
	{
		math::vec3 vecOne(10.0f, 20.0f, 30.0f);
		math::vec3 vecTwo(20.0f, 30.0f, 40.0f);
		math::vec3 vecThree(10.0f, 20.0f, 30.0f);

		EXPECT_TRUE(vecOne <= vecTwo);
		EXPECT_TRUE(vecOne <= vecThree);
	}

	TEST_F(Vec3Test, operatorGreaterThan)
	{
		math::vec3 vecOne(20.0f, 30.0f, 40.0f);
		math::vec3 vecTwo(10.0f, 20.0f, 30.0f);

		EXPECT_TRUE(vecOne > vecTwo);
	}

	TEST_F(Vec3Test, operatorGreaterThanOrEquals)
	{
		math::vec3 vecOne(20.0f, 30.0f, 40.0f);
		math::vec3 vecTwo(10.0f, 20.0f, 30.0f);
		math::vec3 vecThree(20.0f, 30.0f, 40.0f);

		EXPECT_TRUE(vecOne >= vecTwo);
		EXPECT_TRUE(vecOne >= vecThree);
	}

	TEST_F(Vec3Test, negateTheVec2)
	{
		math::vec3 vecOne(20.0f, 30.0f, 40.0f);
		math::vec3 vecTwo(-80.0f, -90.0f, -10.0f);

		vecOne = -vecOne;
		vecTwo = -vecTwo;

		EXPECT_EQ(vecOne.x, -20.0f);
		EXPECT_EQ(vecOne.y, -30.0f);
		EXPECT_EQ(vecOne.z, -40.0f);
		EXPECT_EQ(vecTwo.x, 80.0f);
		EXPECT_EQ(vecTwo.y, 90.0f);
		EXPECT_EQ(vecTwo.z, 10.0f);
	}

	TEST_F(Vec3Test, dotProduct)
	{
		math::vec3 vecOne(20.0f, 30.0f, 40.0f);
		math::vec3 vecTwo(3.0f, 2.0f, 1.0f);

		float dotProduct = vecOne.dot(vecTwo);

		EXPECT_EQ(dotProduct, 160.0f);
	}

	TEST_F(Vec3Test, crossProduct)
	{
		math::vec3 vecOne(20.0f, 30.0f, 40.0f);
		math::vec3 vecTwo(3.0f, 2.0f, 1.0f);

		math::vec3 crossProduct = vecOne.cross(vecTwo);

		EXPECT_EQ(crossProduct.x, -50.0f);
		EXPECT_EQ(crossProduct.y, 100.0f);
		EXPECT_EQ(crossProduct.z, -50.0f);
	}

	TEST_F(Vec3Test, magnitude)
	{
		math::vec3 vec(2.0f, -4.0f, 4.0f);

		float magnitude = vec.length();

		EXPECT_EQ(magnitude, 6.0f);
	}

	TEST_F(Vec3Test, distance)
	{
		math::vec3 vecOne(3.0f, 4.0f, 5.0f);
		math::vec3 vecTwo(6.0f, 0.0f, 5.0f);

		float distance = vecOne.distance(vecTwo);

		EXPECT_EQ(distance, 5.0f);
	}

	TEST_F(Vec3Test, normalize)
	{
		math::vec3 vec(2.0f, 3.0f, 4.0f);

		math::vec3 normalized = vec.normalize();

		EXPECT_FLOAT_EQ(normalized.x, 0.37139067f);
		EXPECT_FLOAT_EQ(normalized.y, 0.55708605f);
		EXPECT_FLOAT_EQ(normalized.z, 0.74278134f);
	}

}
