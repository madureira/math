#pragma once

#include <string>
#include "vec3.h"
#include "vec4.h"

namespace math {

	struct mat4
	{
		union
		{
			float elements[4 * 4];
			vec4 rows[4];
		};

		mat4() : elements{
			0.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f
		} {}

		mat4(float diagonal) : elements{
			diagonal, 0.0f, 0.0f, 0.0f,
			0.0f, diagonal, 0.0f, 0.0f,
			0.0f, 0.0f, diagonal, 0.0f,
			0.0f, 0.0f, 0.0f, diagonal
		} {}

		mat4(const mat4& matrix) {
			memcpy(elements, matrix.elements, 4 * 4 * sizeof(float));
		}

		mat4(const vec4& row0, const vec4& row1, const vec4& row2, const vec4& row3)
		{
			rows[0] = row0;
			rows[1] = row1;
			rows[2] = row2;
			rows[3] = row3;
		}

		static mat4 identity()
		{
			return mat4(1.0f);
		}

		mat4& multiply(const mat4& matrix)
		{
			float data[16];

			for (int row = 0; row < 4; row++)
			{
				for (int col = 0; col < 4; col++)
				{
					float sum = 0.0f;
					for (int cell = 0; cell < 4; cell++)
					{
						sum += elements[cell + row * 4] * matrix.elements[col + cell * 4];
					}
					data[col + row * 4] = sum;
				}
			}

			memcpy(elements, data, 4 * 4 * sizeof(float));

			return *this;
		}

		friend mat4 operator*(mat4 left, const mat4& right)
		{
			return left.multiply(right);
		}

		mat4& operator*=(const mat4& matrix)
		{
			return multiply(matrix);
		}

		bool invert()
		{
			float temp[16];

			temp[0] = elements[5] * elements[10] * elements[15] -
				elements[5] * elements[11] * elements[14] -
				elements[9] * elements[6] * elements[15] +
				elements[9] * elements[7] * elements[14] +
				elements[13] * elements[6] * elements[11] -
				elements[13] * elements[7] * elements[10];

			temp[4] = -elements[4] * elements[10] * elements[15] +
				elements[4] * elements[11] * elements[14] +
				elements[8] * elements[6] * elements[15] -
				elements[8] * elements[7] * elements[14] -
				elements[12] * elements[6] * elements[11] +
				elements[12] * elements[7] * elements[10];

			temp[8] = elements[4] * elements[9] * elements[15] -
				elements[4] * elements[11] * elements[13] -
				elements[8] * elements[5] * elements[15] +
				elements[8] * elements[7] * elements[13] +
				elements[12] * elements[5] * elements[11] -
				elements[12] * elements[7] * elements[9];

			temp[12] = -elements[4] * elements[9] * elements[14] +
				elements[4] * elements[10] * elements[13] +
				elements[8] * elements[5] * elements[14] -
				elements[8] * elements[6] * elements[13] -
				elements[12] * elements[5] * elements[10] +
				elements[12] * elements[6] * elements[9];

			temp[1] = -elements[1] * elements[10] * elements[15] +
				elements[1] * elements[11] * elements[14] +
				elements[9] * elements[2] * elements[15] -
				elements[9] * elements[3] * elements[14] -
				elements[13] * elements[2] * elements[11] +
				elements[13] * elements[3] * elements[10];

			temp[5] = elements[0] * elements[10] * elements[15] -
				elements[0] * elements[11] * elements[14] -
				elements[8] * elements[2] * elements[15] +
				elements[8] * elements[3] * elements[14] +
				elements[12] * elements[2] * elements[11] -
				elements[12] * elements[3] * elements[10];

			temp[9] = -elements[0] * elements[9] * elements[15] +
				elements[0] * elements[11] * elements[13] +
				elements[8] * elements[1] * elements[15] -
				elements[8] * elements[3] * elements[13] -
				elements[12] * elements[1] * elements[11] +
				elements[12] * elements[3] * elements[9];

			temp[13] = elements[0] * elements[9] * elements[14] -
				elements[0] * elements[10] * elements[13] -
				elements[8] * elements[1] * elements[14] +
				elements[8] * elements[2] * elements[13] +
				elements[12] * elements[1] * elements[10] -
				elements[12] * elements[2] * elements[9];

			temp[2] = elements[1] * elements[6] * elements[15] -
				elements[1] * elements[7] * elements[14] -
				elements[5] * elements[2] * elements[15] +
				elements[5] * elements[3] * elements[14] +
				elements[13] * elements[2] * elements[7] -
				elements[13] * elements[3] * elements[6];

			temp[6] = -elements[0] * elements[6] * elements[15] +
				elements[0] * elements[7] * elements[14] +
				elements[4] * elements[2] * elements[15] -
				elements[4] * elements[3] * elements[14] -
				elements[12] * elements[2] * elements[7] +
				elements[12] * elements[3] * elements[6];

			temp[10] = elements[0] * elements[5] * elements[15] -
				elements[0] * elements[7] * elements[13] -
				elements[4] * elements[1] * elements[15] +
				elements[4] * elements[3] * elements[13] +
				elements[12] * elements[1] * elements[7] -
				elements[12] * elements[3] * elements[5];

			temp[14] = -elements[0] * elements[5] * elements[14] +
				elements[0] * elements[6] * elements[13] +
				elements[4] * elements[1] * elements[14] -
				elements[4] * elements[2] * elements[13] -
				elements[12] * elements[1] * elements[6] +
				elements[12] * elements[2] * elements[5];

			temp[3] = -elements[1] * elements[6] * elements[11] +
				elements[1] * elements[7] * elements[10] +
				elements[5] * elements[2] * elements[11] -
				elements[5] * elements[3] * elements[10] -
				elements[9] * elements[2] * elements[7] +
				elements[9] * elements[3] * elements[6];

			temp[7] = elements[0] * elements[6] * elements[11] -
				elements[0] * elements[7] * elements[10] -
				elements[4] * elements[2] * elements[11] +
				elements[4] * elements[3] * elements[10] +
				elements[8] * elements[2] * elements[7] -
				elements[8] * elements[3] * elements[6];

			temp[11] = -elements[0] * elements[5] * elements[11] +
				elements[0] * elements[7] * elements[9] +
				elements[4] * elements[1] * elements[11] -
				elements[4] * elements[3] * elements[9] -
				elements[8] * elements[1] * elements[7] +
				elements[8] * elements[3] * elements[5];

			temp[15] = elements[0] * elements[5] * elements[10] -
				elements[0] * elements[6] * elements[9] -
				elements[4] * elements[1] * elements[10] +
				elements[4] * elements[2] * elements[9] +
				elements[8] * elements[1] * elements[6] -
				elements[8] * elements[2] * elements[5];

			float determinant = elements[0] * temp[0] + elements[1] * temp[4] + elements[2] * temp[8] + elements[3] * temp[12];

			if (determinant == 0.0f)
			{
				return false;
			}

			determinant = 1.0f / determinant;

			for (int i = 0; i < 16; i++)
			{
				elements[i] = temp[i] * determinant;
			}

			return true;
		}

		vec4 getColumn(int index)
		{
			return vec4(
				elements[index + 0 * 4],
				elements[index + 1 * 4],
				elements[index + 2 * 4],
				elements[index + 3 * 4]
			);
		}

		void setColumn(int index, const vec4& column)
		{
			elements[index + 0 * 4] = column.x;
			elements[index + 1 * 4] = column.y;
			elements[index + 2 * 4] = column.z;
			elements[index + 3 * 4] = column.w;
		}

		mat4 orthographic(float left, float right, float bottom, float top, float near, float far)
		{

		}

		mat4 perspective(float fov, float aspectRatio, float near, float far)
		{

		}

		mat4 lookAt(const vec3& camera, const vec3& object, const vec3& up)
		{

		}

		mat4 translate(const vec3& translation)
		{

		}

		mat4 rotate(float angle, const vec3& axis)
		{

		}

		mat4 scale(const vec3& scale)
		{
			mat4 matrix(1.0f);

			matrix.elements[0 + 0 * 4] = scale.x;
			matrix.elements[1 + 1 * 4] = scale.y;
			matrix.elements[2 + 2 * 4] = scale.z;

			return matrix;
		}

		mat4 transpose(const mat4& matrix)
		{
			return mat4(
				vec4(matrix.rows[0].x, matrix.rows[1].x, matrix.rows[2].x, matrix.rows[3].x),
				vec4(matrix.rows[0].y, matrix.rows[1].y, matrix.rows[2].y, matrix.rows[3].y),
				vec4(matrix.rows[0].z, matrix.rows[1].z, matrix.rows[2].z, matrix.rows[3].z),
				vec4(matrix.rows[0].w, matrix.rows[1].w, matrix.rows[2].w, matrix.rows[3].w)
			);
		}

		std::string toString() const
		{
			std::stringstream result;

			result << "mat4: [" << rows[0].x << ", " << rows[1].x << ", " << rows[2].x << ", " << rows[3].x << "] ";
			result << "[" << rows[0].y << ", " << rows[1].y << ", " << rows[2].y << ", " << rows[3].y << "] ";
			result << "[" << rows[0].z << ", " << rows[1].z << ", " << rows[2].z << ", " << rows[3].z << "] ";
			result << "[" << rows[0].w << ", " << rows[1].w << ", " << rows[2].w << ", " << rows[3].w << "]";

			return result.str();
		}

		friend std::ostream& operator<<(std::ostream& stream, const mat4& matrix)
		{
			stream << matrix.toString();
			return stream;
		}
	};

}
