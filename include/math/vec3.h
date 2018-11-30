#pragma once

#include <math/vec2.h>

namespace math {

	struct vec3 {
		float x, y, z;

		vec3() : x(0.0f), y(0.0f), z(0.0f) {}
		vec3(float x, float y, float z) : x(x), y(y), z(z) {}
		vec3(const vec3& v) : x(v.x), y(v.y), z(v.z) {}
		vec3(const vec2& v, float z) : x(v.x), y(v.y), z(z) {}

		vec3& add(const vec3& v)
		{
			x += v.x;
			y += v.y;
			z += v.z;

			return *this;
		}

		vec3& add(const vec2& v)
		{
			x += v.x;
			y += v.y;

			return *this;
		}

		vec3& subtract(const vec3& v)
		{
			x -= v.x;
			y -= v.y;
			z -= v.z;

			return *this;
		}

		vec3& subtract(const vec2& v)
		{
			x -= v.x;
			y -= v.y;

			return *this;
		}
	};

}
