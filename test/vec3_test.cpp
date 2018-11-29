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
		EXPECT_EQ(position.r, 0.0f);
		EXPECT_EQ(position.g, 0.0f);
		EXPECT_EQ(position.b, 0.0f);
	}

}
