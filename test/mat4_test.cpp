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

	TEST_F(Mat4Test, initAnIdentityMatrixByDiagonal)
	{
		math::mat4 matrix(1.0f);

		int idx = 0;
		for (auto element : matrix.elements) {
			if (idx == 0 || idx == 5 || idx == 10 || idx == 15) {
				EXPECT_EQ(element, 1.0f);
			}
			else {
				EXPECT_EQ(element, 0.0f);
			}
			idx++;
		}
	}
	
	TEST_F(Mat4Test, initAnIdentityMatrix)
	{
		const math::mat4& identityMatrix = math::mat4::identity();

		int idx = 0;
		for (auto element : identityMatrix.elements) {
			if (idx == 0 || idx == 5 || idx == 10 || idx == 15) {
				EXPECT_EQ(element, 1.0f);
			}
			else {
				EXPECT_EQ(element, 0.0f);
			}
			idx++;
		}
	}
	
	TEST_F(Mat4Test, multiplyTwoMatrices)
	{
		math::mat4 matrixOne;

		matrixOne.elements[0] = 1.0f;
		matrixOne.elements[1] = 1.0f;
		matrixOne.elements[2] = 1.0f;
		matrixOne.elements[3] = 1.0f;

		matrixOne.elements[4] = 2.0f;
		matrixOne.elements[5] = 2.0f;
		matrixOne.elements[6] = 2.0f;
		matrixOne.elements[7] = 2.0f;

		matrixOne.elements[8] = 3.0f;
		matrixOne.elements[9] = 3.0f;
		matrixOne.elements[10] = 3.0f;
		matrixOne.elements[11] = 3.0f;

		matrixOne.elements[12] = 4.0f;
		matrixOne.elements[13] = 4.0f;
		matrixOne.elements[14] = 4.0f;
		matrixOne.elements[15] = 4.0f;

		math::mat4 matrixTwo;

		matrixTwo.elements[0] = 5.0f;
		matrixTwo.elements[1] = 5.0f;
		matrixTwo.elements[2] = 5.0f;
		matrixTwo.elements[3] = 5.0f;

		matrixTwo.elements[4] = 6.0f;
		matrixTwo.elements[5] = 6.0f;
		matrixTwo.elements[6] = 6.0f;
		matrixTwo.elements[7] = 6.0f;

		matrixTwo.elements[8] = 7.0f;
		matrixTwo.elements[9] = 7.0f;
		matrixTwo.elements[10] = 7.0f;
		matrixTwo.elements[11] = 7.0f;

		matrixTwo.elements[12] = 8.0f;
		matrixTwo.elements[13] = 8.0f;
		matrixTwo.elements[14] = 8.0f;
		matrixTwo.elements[15] = 8.0f;

		math::mat4& result = matrixOne.multiply(matrixTwo);

		EXPECT_FLOAT_EQ(result.elements[0], 26.0f);
		EXPECT_FLOAT_EQ(result.elements[1], 26.0f);
		EXPECT_FLOAT_EQ(result.elements[2], 26.0f);
		EXPECT_FLOAT_EQ(result.elements[3], 26.0f);
		EXPECT_FLOAT_EQ(result.elements[4], 52.0f);
		EXPECT_FLOAT_EQ(result.elements[5], 52.0f);
		EXPECT_FLOAT_EQ(result.elements[6], 52.0f);
		EXPECT_FLOAT_EQ(result.elements[7], 52.0f);
		EXPECT_FLOAT_EQ(result.elements[8], 78.0f);
		EXPECT_FLOAT_EQ(result.elements[9], 78.0f);
		EXPECT_FLOAT_EQ(result.elements[10], 78.0f);
		EXPECT_FLOAT_EQ(result.elements[11], 78.0f);
		EXPECT_FLOAT_EQ(result.elements[12], 104.0f);
		EXPECT_FLOAT_EQ(result.elements[13], 104.0f);
		EXPECT_FLOAT_EQ(result.elements[14], 104.0f);
		EXPECT_FLOAT_EQ(result.elements[15], 104.0f);
	}

}
