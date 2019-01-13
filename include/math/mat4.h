#pragma once

#include "./vec4.h"

namespace math {

	struct mat4
	{
		union
		{
			float elements[4 * 4];
			math::vec4 columns[4];
		};

		mat4()
		{
			for (int i = 0; i < 4 * 4; i++)
			{
				elements[i] = 0.0f;
			}
		}
	};

}
