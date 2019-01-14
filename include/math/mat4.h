#pragma once

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
	};

}
