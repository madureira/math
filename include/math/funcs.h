#pragma once

constexpr auto MATH_PI = 3.14159265358f;

namespace math {

	struct funcs
	{
		static float toRadians(float degrees)
		{
			return (float)(degrees * (MATH_PI / 180.0f));
		}

		static float toDegrees(float radians)
		{
			return (float)(radians * (180.0f / MATH_PI));
		}
	};

}
