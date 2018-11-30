#include "pch.h"
#include <math/vec3.h>

namespace {

	class Vec3Test : public ::testing::Test {};

	TEST_F(Vec3Test, setDefaultValues)
	{
		math::vec3 position;

		EXPECT_EQ(position.x, 0.0f);
		EXPECT_EQ(position.y, 0.0f);
		EXPECT_EQ(position.z, 0.0f);
	}

	TEST_F(Vec3Test, setValuesByConstructor)
	{
		math::vec3 position(10.0, 20.0f, 30.0f);

		EXPECT_EQ(position.x, 10.0f);
		EXPECT_EQ(position.y, 20.0f);
		EXPECT_EQ(position.z, 30.0f);
	}

	TEST_F(Vec3Test, initiateANewVec3ByCopy)
	{
		math::vec3 position(10.0, 20.0f, 30.0f);

		math::vec3 color(position);

		EXPECT_EQ(color.x, 10.0f);
		EXPECT_EQ(color.y, 20.0f);
		EXPECT_EQ(color.z, 30.0f);
	}

	TEST_F(Vec3Test, initiateANewVec2ByCopy)
	{
		math::vec2 position(10.0, 20.0f);

		math::vec3 color(position, 30.0f);

		EXPECT_EQ(color.x, 10.0f);
		EXPECT_EQ(color.y, 20.0f);
		EXPECT_EQ(color.z, 30.0f);
	}

	TEST_F(Vec3Test, setX)
	{
		math::vec3 position;

		position.x = 30.0f;

		EXPECT_EQ(position.x, 30.0f);
	}

	TEST_F(Vec3Test, setY)
	{
		math::vec3 position;

		position.y = 20.0f;

		EXPECT_EQ(position.y, 20.0f);
	}

	TEST_F(Vec3Test, setZ)
	{
		math::vec3 position;

		position.z = 10.0f;

		EXPECT_EQ(position.z, 10.0f);
	}

	TEST_F(Vec3Test, addAVec3)
	{
		math::vec3 position(10.0f, 20.0f, 30.0f);

		math::vec3 coordinates(20.0f, 30.0f, 40.0f);

		position.add(coordinates);

		EXPECT_EQ(position.x, 30.0f);
		EXPECT_EQ(position.y, 50.0f);
		EXPECT_EQ(position.z, 70.0f);
	}

	TEST_F(Vec3Test, addAVec2)
	{
		math::vec3 position(10.0f, 20.0f, 30.0f);

		math::vec2 coordinates(20.0f, 30.0f);

		position.add(coordinates);

		EXPECT_EQ(position.x, 30.0f);
		EXPECT_EQ(position.y, 50.0f);
		EXPECT_EQ(position.z, 30.0f);
	}

	TEST_F(Vec3Test, subtractAVec3)
	{
		math::vec3 position(10.0f, 20.0f, 30.0f);

		math::vec3 coordinates(4.0f, 5.0f, 6.0f);

		position.subtract(coordinates);

		EXPECT_EQ(position.x, 6.0f);
		EXPECT_EQ(position.y, 15.0f);
		EXPECT_EQ(position.z, 24.0f);
	}

	TEST_F(Vec3Test, subtractAVec2)
	{
		math::vec3 position(10.0f, 20.0f, 30.0f);

		math::vec2 coordinates(4.0f, 5.0f);

		position.subtract(coordinates);

		EXPECT_EQ(position.x, 6.0f);
		EXPECT_EQ(position.y, 15.0f);
		EXPECT_EQ(position.z, 30.0f);
	}

}
