#include "pch.h"
#include <math/mat4.h>

namespace {

	class Mat4Test : public ::testing::Test {};

	TEST_F(Mat4Test, initByDefaultValues)
	{
		math::mat4 matrix;

		for (auto element : matrix.elements) {
			EXPECT_EQ(element, 0.0f);
		}
	}

}
