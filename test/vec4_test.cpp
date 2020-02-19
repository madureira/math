#include "pch.h"
#include <math/vec4.h>

namespace UnitTests {

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

	TEST_F(Vec4Test, addAScalar)
	{
		math::vec4 vec(10.0f, 20.0f, 30.0f, 40.0f);
		vec.add(5.0f);

		EXPECT_EQ(vec.x, 15.0f);
		EXPECT_EQ(vec.y, 25.0f);
		EXPECT_EQ(vec.z, 35.0f);
		EXPECT_EQ(vec.w, 45.0f);
	}

	TEST_F(Vec4Test, subtractAScalar)
	{
		math::vec4 vec(10.0f, 20.0f, 30.0f, 40.0f);
		vec.subtract(5.0f);

		EXPECT_EQ(vec.x, 5.0f);
		EXPECT_EQ(vec.y, 15.0f);
		EXPECT_EQ(vec.z, 25.0f);
		EXPECT_EQ(vec.w, 35.0f);
	}

	TEST_F(Vec4Test, multiplyByScalar)
	{
		math::vec4 vec(10.0f, 20.0f, 30.0f, 40.0f);
		vec.multiply(2.0f);

		EXPECT_EQ(vec.x, 20.0f);
		EXPECT_EQ(vec.y, 40.0f);
		EXPECT_EQ(vec.z, 60.0f);
		EXPECT_EQ(vec.w, 80.0f);
	}

	TEST_F(Vec4Test, divideByScalar)
	{
		math::vec4 vec(10.0f, 20.0f, 30.0f, 40.0f);
		vec.divide(2.0f);

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

	TEST_F(Vec4Test, operatorPlusWithScalar)
	{
		math::vec4 vec(10.0f, 20.0f, 30.0f, 40.0f);
		vec = vec + 5.0f;

		EXPECT_EQ(vec.x, 15.0f);
		EXPECT_EQ(vec.y, 25.0f);
		EXPECT_EQ(vec.z, 35.0f);
		EXPECT_EQ(vec.w, 45.0f);
	}

	TEST_F(Vec4Test, operatorMinusWithScalar)
	{
		math::vec4 vec(10.0f, 20.0f, 30.0f, 40.0f);
		vec = vec - 5.0f;

		EXPECT_EQ(vec.x, 5.0f);
		EXPECT_EQ(vec.y, 15.0f);
		EXPECT_EQ(vec.z, 25.0f);
		EXPECT_EQ(vec.w, 35.0f);
	}

	TEST_F(Vec4Test, operatorTimesWithScalar)
	{
		math::vec4 vec(10.0f, 20.0f, 30.0f, 40.0f);
		vec = vec * 2.0f;

		EXPECT_EQ(vec.x, 20.0f);
		EXPECT_EQ(vec.y, 40.0f);
		EXPECT_EQ(vec.z, 60.0f);
		EXPECT_EQ(vec.w, 80.0f);
	}

	TEST_F(Vec4Test, operatorSlashWithScalar)
	{
		math::vec4 vec(10.0f, 20.0f, 30.0f, 40.0f);
		vec = vec / 2.0f;

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

	TEST_F(Vec4Test, operatorPlusEqualsWithScalar)
	{
		math::vec4 vec(10.0f, 20.0f, 30.0f, 40.0f);
		vec += 5.0f;

		EXPECT_EQ(vec.x, 15.0f);
		EXPECT_EQ(vec.y, 25.0f);
		EXPECT_EQ(vec.z, 35.0f);
		EXPECT_EQ(vec.w, 45.0f);
	}

	TEST_F(Vec4Test, operatorMinusEqualsWithScalar)
	{
		math::vec4 vec(10.0f, 20.0f, 30.0f, 40.0f);
		vec -= 5.0f;

		EXPECT_EQ(vec.x, 5.0f);
		EXPECT_EQ(vec.y, 15.0f);
		EXPECT_EQ(vec.z, 25.0f);
		EXPECT_EQ(vec.w, 35.0f);
	}

	TEST_F(Vec4Test, operatorTimesEqualsWithScalar)
	{
		math::vec4 vec(10.0f, 20.0f, 30.0f, 40.0f);
		vec *= 2.0f;

		EXPECT_EQ(vec.x, 20.0f);
		EXPECT_EQ(vec.y, 40.0f);
		EXPECT_EQ(vec.z, 60.0f);
		EXPECT_EQ(vec.w, 80.0f);
	}

	TEST_F(Vec4Test, operatorSlashEqualsWithScalar)
	{
		math::vec4 vec(10.0f, 20.0f, 30.0f, 40.0f);
		vec /= 2.0f;

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

	TEST_F(Vec4Test, operatorLessThan)
	{
		math::vec4 vecOne(10.0f, 20.0f, 30.0f, 40.0f);
		math::vec4 vecTwo(20.0f, 30.0f, 40.0f, 50.0f);

		EXPECT_TRUE(vecOne < vecTwo);
	}

	TEST_F(Vec4Test, operatorLessThanOrEquals)
	{
		math::vec4 vecOne(10.0f, 20.0f, 30.0f, 40.0f);
		math::vec4 vecTwo(20.0f, 30.0f, 40.0f, 50.0f);
		math::vec4 vecThree(10.0f, 20.0f, 30.0f, 40.0f);

		EXPECT_TRUE(vecOne <= vecTwo);
		EXPECT_TRUE(vecOne <= vecThree);
	}

	TEST_F(Vec4Test, operatorGreaterThan)
	{
		math::vec4 vecOne(20.0f, 30.0f, 40.0f, 50.0f);
		math::vec4 vecTwo(10.0f, 20.0f, 30.0f, 40.0f);

		EXPECT_TRUE(vecOne > vecTwo);
	}

	TEST_F(Vec4Test, operatorGreaterThanOrEquals)
	{
		math::vec4 vecOne(20.0f, 30.0f, 40.0f, 50.0f);
		math::vec4 vecTwo(10.0f, 20.0f, 30.0f, 40.0f);
		math::vec4 vecThree(20.0f, 30.0f, 40.0f, 50.0f);

		EXPECT_TRUE(vecOne >= vecTwo);
		EXPECT_TRUE(vecOne >= vecThree);
	}

	TEST_F(Vec4Test, negateTheVec4)
	{
		math::vec4 vecOne(20.0f, 30.0f, 40.0f, 50.0f);
		math::vec4 vecTwo(-10.0f, -20.0f, -30.0f, -40.0f);

		vecOne = -vecOne;
		vecTwo = -vecTwo;

		EXPECT_EQ(vecOne.x, -20.0f);
		EXPECT_EQ(vecOne.y, -30.0f);
		EXPECT_EQ(vecOne.z, -40.0f);
		EXPECT_EQ(vecOne.w, -50.0f);
		EXPECT_EQ(vecTwo.x, 10.0f);
		EXPECT_EQ(vecTwo.y, 20.0f);
		EXPECT_EQ(vecTwo.z, 30.0f);
		EXPECT_EQ(vecTwo.w, 40.0f);
	}

	TEST_F(Vec4Test, magnitude)
	{
		math::vec4 vec(2.0f, 3.0f, 4.0f, 5.0f);

		float magnitude = vec.length();

		EXPECT_FLOAT_EQ(magnitude, 7.34847f);
	}

	TEST_F(Vec4Test, distance)
	{
		math::vec4 vecOne(3.0f, 4.0f, 5.0f, 10.0f);
		math::vec4 vecTwo(6.0f, 0.0f, 5.0f, 6.0f);

		float distance = vecOne.distance(vecTwo);

		EXPECT_FLOAT_EQ(distance, 6.4031243f);
	}

	TEST_F(Vec4Test, dotProduct)
	{
		math::vec4 vecOne(10.0f, 20.0f, 30.0f, 40.0f);
		math::vec4 vecTwo(4.0f, 3.0f, 2.0f, 1.0f);

		float dotProduct = vecOne.dot(vecTwo);

		EXPECT_EQ(dotProduct, 200.0f);
	}

	TEST_F(Vec4Test, toString)
	{
		math::vec4 vec(1.0f, 2.0f, 3.0f, 4.0f);

		std::string output = vec.toString();

		EXPECT_EQ(output, "vec4:(1, 2, 3, 4)");
	}
}
