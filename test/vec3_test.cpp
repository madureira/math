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

	TEST_F(Vec3Test, initiateANewVec2ByCopy)
	{
		math::vec3 vec(math::vec2(10.0, 20.0f), 30.0f);

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

	TEST_F(Vec3Test, addAVec2)
	{
		math::vec3 vec(10.0f, 20.0f, 30.0f);
		vec.add(math::vec2(20.0f, 30.0f));

		EXPECT_EQ(vec.x, 30.0f);
		EXPECT_EQ(vec.y, 50.0f);
		EXPECT_EQ(vec.z, 30.0f);
	}

	TEST_F(Vec3Test, subtractAVec3)
	{
		math::vec3 vec(10.0f, 20.0f, 30.0f);
		vec.subtract(math::vec3(4.0f, 5.0f, 6.0f));

		EXPECT_EQ(vec.x, 6.0f);
		EXPECT_EQ(vec.y, 15.0f);
		EXPECT_EQ(vec.z, 24.0f);
	}

	TEST_F(Vec3Test, subtractAVec2)
	{
		math::vec3 vec(10.0f, 20.0f, 30.0f);
		vec.subtract(math::vec2(4.0f, 5.0f));

		EXPECT_EQ(vec.x, 6.0f);
		EXPECT_EQ(vec.y, 15.0f);
		EXPECT_EQ(vec.z, 30.0f);
	}

}
