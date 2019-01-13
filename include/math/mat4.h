#pragma once

#include "./vec4.h"

namespace math {

	struct mat4
	{
		union
		{
			float elements[4 * 4];
			vec4 columns[4];
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

		static const mat4& identity()
		{
			static const mat4 identityMatrix(1.0f);
			return identityMatrix;
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
	};

}
