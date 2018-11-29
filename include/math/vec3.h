#pragma once

namespace math {

	struct vec3 {
		float x, y, z;
		float r, g, b;

		vec3() : x(0.0f), y(0.0f), z(0.0f), r(0.0f), g(0.0f), b(0.0f) {}
		vec3(float x, float y, float z) : x(x), y(y), z(z), r(x), g(y), b(z) {}
	};

}
