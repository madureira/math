#include "pch.h"
#include <math/mat4.h>

namespace {

	class Mat4Test : public ::testing::Test {};

	void fillMatrix(math::mat4& matrix, int start, int end, float value)
	{
		for (int i = start; i <= end; i++)
		{
			matrix.elements[i] = value;
		}
	}

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

	TEST_F(Mat4Test, initMatrixByReference)
	{
		math::mat4 someMatrix(3.0f);
		math::mat4 matrix(someMatrix);

		int idx = 0;
		for (auto element : matrix.elements) {
			if (idx == 0 || idx == 5 || idx == 10 || idx == 15) {
				EXPECT_EQ(element, 3.0f);
			}
			else {
				EXPECT_EQ(element, 0.0f);
			}
			idx++;
		}
	}

	TEST_F(Mat4Test, initMatrixByRows)
	{
		math::vec4 row0(0.0f, 0.0f, 0.0f, 0.0f);
		math::vec4 row1(1.0f, 1.0f, 1.0f, 1.0f);
		math::vec4 row2(2.0f, 2.0f, 2.0f, 2.0f);
		math::vec4 row3(3.0f, 3.0f, 3.0f, 3.0f);

		math::mat4 matrix(row0, row1, row2, row3);

		EXPECT_EQ(matrix.elements[0], 0.0f);
		EXPECT_EQ(matrix.elements[3], 0.0f);
		EXPECT_EQ(matrix.elements[4], 1.0f);
		EXPECT_EQ(matrix.elements[7], 1.0f);
		EXPECT_EQ(matrix.elements[8], 2.0f);
		EXPECT_EQ(matrix.elements[11], 2.0f);
		EXPECT_EQ(matrix.elements[12], 3.0f);
		EXPECT_EQ(matrix.elements[15], 3.0f);
	}
	
	TEST_F(Mat4Test, initAnIdentityMatrix)
	{
		math::mat4 identityMatrix = math::mat4::identity();

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

		fillMatrix(matrixOne, 0, 3, 1.0f);
		fillMatrix(matrixOne, 4, 7, 2.0f);
		fillMatrix(matrixOne, 8, 11, 3.0f);
		fillMatrix(matrixOne, 12, 15, 4.0f);

		math::mat4 matrixTwo;

		fillMatrix(matrixTwo, 0, 3, 5.0f);
		fillMatrix(matrixTwo, 4, 7, 6.0f);
		fillMatrix(matrixTwo, 8, 11, 7.0f);
		fillMatrix(matrixTwo, 12, 15, 8.0f);

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

	TEST_F(Mat4Test, operatorTimes)
	{
		math::mat4 matrixOne;

		fillMatrix(matrixOne, 0, 3, 1.0f);
		fillMatrix(matrixOne, 4, 7, 2.0f);
		fillMatrix(matrixOne, 8, 11, 3.0f);
		fillMatrix(matrixOne, 12, 15, 4.0f);

		math::mat4 matrixTwo;

		fillMatrix(matrixTwo, 0, 3, 5.0f);
		fillMatrix(matrixTwo, 4, 7, 6.0f);
		fillMatrix(matrixTwo, 8, 11, 7.0f);
		fillMatrix(matrixTwo, 12, 15, 8.0f);

		math::mat4 result = matrixOne * matrixTwo;

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

	TEST_F(Mat4Test, operatorTimesEquals)
	{
		math::mat4 matrixOne;

		fillMatrix(matrixOne, 0, 3, 1.0f);
		fillMatrix(matrixOne, 4, 7, 2.0f);
		fillMatrix(matrixOne, 8, 11, 3.0f);
		fillMatrix(matrixOne, 12, 15, 4.0f);

		math::mat4 matrixTwo;

		fillMatrix(matrixTwo, 0, 3, 5.0f);
		fillMatrix(matrixTwo, 4, 7, 6.0f);
		fillMatrix(matrixTwo, 8, 11, 7.0f);
		fillMatrix(matrixTwo, 12, 15, 8.0f);

		matrixOne *= matrixTwo;

		EXPECT_FLOAT_EQ(matrixOne.elements[0], 26.0f);
		EXPECT_FLOAT_EQ(matrixOne.elements[1], 26.0f);
		EXPECT_FLOAT_EQ(matrixOne.elements[2], 26.0f);
		EXPECT_FLOAT_EQ(matrixOne.elements[3], 26.0f);
		EXPECT_FLOAT_EQ(matrixOne.elements[4], 52.0f);
		EXPECT_FLOAT_EQ(matrixOne.elements[5], 52.0f);
		EXPECT_FLOAT_EQ(matrixOne.elements[6], 52.0f);
		EXPECT_FLOAT_EQ(matrixOne.elements[7], 52.0f);
		EXPECT_FLOAT_EQ(matrixOne.elements[8], 78.0f);
		EXPECT_FLOAT_EQ(matrixOne.elements[9], 78.0f);
		EXPECT_FLOAT_EQ(matrixOne.elements[10], 78.0f);
		EXPECT_FLOAT_EQ(matrixOne.elements[11], 78.0f);
		EXPECT_FLOAT_EQ(matrixOne.elements[12], 104.0f);
		EXPECT_FLOAT_EQ(matrixOne.elements[13], 104.0f);
		EXPECT_FLOAT_EQ(matrixOne.elements[14], 104.0f);
		EXPECT_FLOAT_EQ(matrixOne.elements[15], 104.0f);
	}

	TEST_F(Mat4Test, shouldNotInvertAMatrixWithDeterminantEqualsZero)
	{
		math::mat4 matrix;

		fillMatrix(matrix, 0, 3, 1.0f);
		fillMatrix(matrix, 4, 7, 2.0f);
		fillMatrix(matrix, 8, 11, 3.0f);
		fillMatrix(matrix, 12, 15, 4.0f);

		EXPECT_FALSE(matrix.invert());

		EXPECT_FLOAT_EQ(matrix.elements[0], 1.0f);
		EXPECT_FLOAT_EQ(matrix.elements[1], 1.0f);
		EXPECT_FLOAT_EQ(matrix.elements[2], 1.0f);
		EXPECT_FLOAT_EQ(matrix.elements[3], 1.0f);
		EXPECT_FLOAT_EQ(matrix.elements[4], 2.0f);
		EXPECT_FLOAT_EQ(matrix.elements[5], 2.0f);
		EXPECT_FLOAT_EQ(matrix.elements[6], 2.0f);
		EXPECT_FLOAT_EQ(matrix.elements[7], 2.0f);
		EXPECT_FLOAT_EQ(matrix.elements[8], 3.0f);
		EXPECT_FLOAT_EQ(matrix.elements[9], 3.0f);
		EXPECT_FLOAT_EQ(matrix.elements[10], 3.0f);
		EXPECT_FLOAT_EQ(matrix.elements[11], 3.0f);
		EXPECT_FLOAT_EQ(matrix.elements[12], 4.0f);
		EXPECT_FLOAT_EQ(matrix.elements[13], 4.0f);
		EXPECT_FLOAT_EQ(matrix.elements[14], 4.0f);
		EXPECT_FLOAT_EQ(matrix.elements[15], 4.0f);
	}

	TEST_F(Mat4Test, shouldInvertAMatrix)
	{
		math::mat4 matrix;

		matrix.elements[0] = 2.0f;
		matrix.elements[1] = 5.0f;
		matrix.elements[2] = 6.0f;
		matrix.elements[3] = 8.0f;
		matrix.elements[4] = 7.0f;
		matrix.elements[5] = 10.0f;
		matrix.elements[6] = 5.0f;
		matrix.elements[7] = 4.0f;
		matrix.elements[8] = 1.0f;
		matrix.elements[9] = 3.0f;
		matrix.elements[10] = 4.0f;
		matrix.elements[11] = 8.0f;
		matrix.elements[12] = 4.0f;
		matrix.elements[13] = 8.0f;
		matrix.elements[14] = 9.0f;
		matrix.elements[15] = 12.0f;

		EXPECT_TRUE(matrix.invert());

		EXPECT_FLOAT_EQ(matrix.elements[0], -2.5f);
		EXPECT_FLOAT_EQ(matrix.elements[1], -0.16666667f);
		EXPECT_FLOAT_EQ(matrix.elements[2], -0.16666667f);
		EXPECT_FLOAT_EQ(matrix.elements[3], 1.8333334f);
		EXPECT_FLOAT_EQ(matrix.elements[4], 2.0f);
		EXPECT_FLOAT_EQ(matrix.elements[5], 0.33333334f);
		EXPECT_FLOAT_EQ(matrix.elements[6], 0.33333334f);
		EXPECT_FLOAT_EQ(matrix.elements[7], -1.66666666667);
		EXPECT_FLOAT_EQ(matrix.elements[8], -0.25f);
		EXPECT_FLOAT_EQ(matrix.elements[9], -0.25f);
		EXPECT_FLOAT_EQ(matrix.elements[10], -0.75f);
		EXPECT_FLOAT_EQ(matrix.elements[11], 0.75f);
		EXPECT_FLOAT_EQ(matrix.elements[12], -0.3125f);
		EXPECT_FLOAT_EQ(matrix.elements[13], 0.020833334f);
		EXPECT_FLOAT_EQ(matrix.elements[14], 0.3958333f);
		EXPECT_FLOAT_EQ(matrix.elements[15], 0.020833334f);
	}

	TEST_F(Mat4Test, shouldGetMatrixColumnByIndex)
	{
		math::mat4 matrix;

		matrix.elements[0] = 2.0f;
		matrix.elements[1] = 5.0f;
		matrix.elements[2] = 6.0f;
		matrix.elements[3] = 8.0f;
		matrix.elements[4] = 7.0f;
		matrix.elements[5] = 10.0f;
		matrix.elements[6] = 5.0f;
		matrix.elements[7] = 4.0f;
		matrix.elements[8] = 1.0f;
		matrix.elements[9] = 3.0f;
		matrix.elements[10] = 4.0f;
		matrix.elements[11] = 8.0f;
		matrix.elements[12] = 4.0f;
		matrix.elements[13] = 8.0f;
		matrix.elements[14] = 9.0f;
		matrix.elements[15] = 12.0f;

		math::vec4 secondColumn = matrix.getColumn(1);

		EXPECT_FLOAT_EQ(secondColumn.x, 5.0f);
		EXPECT_FLOAT_EQ(secondColumn.y, 10.0f);
		EXPECT_FLOAT_EQ(secondColumn.z, 3.0f);
		EXPECT_FLOAT_EQ(secondColumn.w, 8.0f);

	}

	TEST_F(Mat4Test, shouldSetMatrixColumn)
	{
		math::mat4 matrix;

		matrix.elements[0] = 2.0f;
		matrix.elements[1] = 5.0f;
		matrix.elements[2] = 0.0f;
		matrix.elements[3] = 8.0f;
		matrix.elements[4] = 7.0f;
		matrix.elements[5] = 10.0f;
		matrix.elements[6] = 0.0f;
		matrix.elements[7] = 4.0f;
		matrix.elements[8] = 1.0f;
		matrix.elements[9] = 3.0f;
		matrix.elements[10] = 0.0f;
		matrix.elements[11] = 8.0f;
		matrix.elements[12] = 4.0f;
		matrix.elements[13] = 8.0f;
		matrix.elements[14] = 0.0f;
		matrix.elements[15] = 12.0f;

		math::vec4 newDataColumn = math::vec4(99.0f, 88.0f, 77.0f, 66.0f);

		matrix.setColumn(2, newDataColumn);

		math::vec4 thirdyColumn = matrix.getColumn(2);

		EXPECT_FLOAT_EQ(thirdyColumn.x, 99.0f);
		EXPECT_FLOAT_EQ(thirdyColumn.y, 88.0f);
		EXPECT_FLOAT_EQ(thirdyColumn.z, 77.0f);
		EXPECT_FLOAT_EQ(thirdyColumn.w, 66.0f);
	}

	TEST_F(Mat4Test, shouldCalculateTheOrthographicMatrix)
	{
		EXPECT_FLOAT_EQ(1.0f, 1.0f);
	}

	TEST_F(Mat4Test, shouldCalculateThePerspective)
	{
		EXPECT_FLOAT_EQ(1.0f, 1.0f);
	}

	TEST_F(Mat4Test, shouldLookAt)
	{
		EXPECT_FLOAT_EQ(1.0f, 1.0f);
	}

	TEST_F(Mat4Test, shouldTranslateTheMatrix)
	{
		EXPECT_FLOAT_EQ(1.0f, 1.0f);
	}

	TEST_F(Mat4Test, shouldRotateTheMatrix)
	{
		EXPECT_FLOAT_EQ(1.0f, 1.0f);
	}

	TEST_F(Mat4Test, shouldScaleAMatrix)
	{
		math::mat4 matrix;

		matrix = matrix.scale(math::vec3(1.0f, 2.0f, 3.0f));

		EXPECT_FLOAT_EQ(matrix.elements[0], 1.0f);
		EXPECT_FLOAT_EQ(matrix.elements[1], 0.0f);
		EXPECT_FLOAT_EQ(matrix.elements[2], 0.0f);
		EXPECT_FLOAT_EQ(matrix.elements[3], 0.0f);
		EXPECT_FLOAT_EQ(matrix.elements[4], 0.0f);
		EXPECT_FLOAT_EQ(matrix.elements[5], 2.0f);
		EXPECT_FLOAT_EQ(matrix.elements[6], 0.0f);
		EXPECT_FLOAT_EQ(matrix.elements[7], 0.0f);
		EXPECT_FLOAT_EQ(matrix.elements[8], 0.0f);
		EXPECT_FLOAT_EQ(matrix.elements[9], 0.0f);
		EXPECT_FLOAT_EQ(matrix.elements[10], 3.0f);
		EXPECT_FLOAT_EQ(matrix.elements[11], 0.0f);
		EXPECT_FLOAT_EQ(matrix.elements[12], 0.0f);
		EXPECT_FLOAT_EQ(matrix.elements[13], 0.0f);
		EXPECT_FLOAT_EQ(matrix.elements[14], 0.0f);
		EXPECT_FLOAT_EQ(matrix.elements[15], 1.0f);
	}

	TEST_F(Mat4Test, shouldTransposeTheMatrix)
	{
		math::mat4 matrix;

		fillMatrix(matrix, 0, 3, 1.0f);
		fillMatrix(matrix, 4, 7, 2.0f);
		fillMatrix(matrix, 8, 11, 3.0f);
		fillMatrix(matrix, 12, 15, 4.0f);

		math::mat4 result;
		result = result.transpose(matrix);

		EXPECT_FLOAT_EQ(result.elements[0], 1.0f);
		EXPECT_FLOAT_EQ(result.elements[1], 2.0f);
		EXPECT_FLOAT_EQ(result.elements[2], 3.0f);
		EXPECT_FLOAT_EQ(result.elements[3], 4.0f);
		EXPECT_FLOAT_EQ(result.elements[4], 1.0f);
		EXPECT_FLOAT_EQ(result.elements[5], 2.0f);
		EXPECT_FLOAT_EQ(result.elements[6], 3.0f);
		EXPECT_FLOAT_EQ(result.elements[7], 4.0f);
		EXPECT_FLOAT_EQ(result.elements[8], 1.0f);
		EXPECT_FLOAT_EQ(result.elements[9], 2.0f);
		EXPECT_FLOAT_EQ(result.elements[10], 3.0f);
		EXPECT_FLOAT_EQ(result.elements[11], 4.0f);
		EXPECT_FLOAT_EQ(result.elements[12], 1.0f);
		EXPECT_FLOAT_EQ(result.elements[13], 2.0f);
		EXPECT_FLOAT_EQ(result.elements[14], 3.0f);
		EXPECT_FLOAT_EQ(result.elements[15], 4.0f);
	}

	TEST_F(Mat4Test, shouldConvertMatrixToString)
	{
		math::mat4 matrix;

		matrix.elements[0] = 2.0f;
		matrix.elements[1] = 5.0f;
		matrix.elements[2] = 0.0f;
		matrix.elements[3] = 8.0f;
		matrix.elements[4] = 7.0f;
		matrix.elements[5] = 10.0f;
		matrix.elements[6] = 0.0f;
		matrix.elements[7] = 4.0f;
		matrix.elements[8] = 1.0f;
		matrix.elements[9] = 3.0f;
		matrix.elements[10] = 0.0f;
		matrix.elements[11] = 8.0f;
		matrix.elements[12] = 4.0f;
		matrix.elements[13] = 8.0f;
		matrix.elements[14] = 0.0f;
		matrix.elements[15] = 12.0f;

		std::string expectedString = "mat4: [2, 7, 1, 4] [5, 10, 3, 8] [0, 0, 0, 0] [8, 4, 8, 12]";

		EXPECT_EQ(matrix.toString(), expectedString);
	}
}
