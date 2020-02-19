#include "pch.h"
#include <math/funcs.h>

namespace UnitTests {
	class FuncsTest : public ::testing::Test{};

	TEST_F(FuncsTest, shouldConvertDegreesToRadians)
	{
		float radians = math::funcs::toRadians(30.0f);

		EXPECT_FLOAT_EQ(radians, 0.523599f);
	}

	TEST_F(FuncsTest, shouldConvertRadiansToDegrees)
	{
		float degrees = math::funcs::toDegrees(0.523599f);

		EXPECT_FLOAT_EQ(degrees, 30.000013f);
	}
}
