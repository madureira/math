#pragma once

namespace math {

	struct vec3 {
		float x, y, z;

		vec3() : x(0.0f), y(0.0f), z(0.0f) {}
		vec3(float x, float y, float z) : x(x), y(y), z(z) {}
		vec3(const vec3& v) : x(v.x), y(v.y), z(v.z) {}

		vec3& add(const vec3& v)
		{
			x += v.x;
			y += v.y;
			z += v.z;

			return *this;
		}

		vec3& subtract(const vec3& v)
		{
			x -= v.x;
			y -= v.y;
			z -= v.z;

			return *this;
		}

		vec3& multiply(const vec3& v)
		{
			x *= v.x;
			y *= v.y;
			z *= v.z;

			return *this;
		}

		vec3& divide(const vec3& v)
		{
			x /= v.x;
			y /= v.y;
			z /= v.z;

			return *this;
		}

		friend vec3 operator+(vec3 left, const vec3& right)
		{
			return left.add(right);
		}

		friend vec3 operator-(vec3 left, const vec3& right)
		{
			return left.subtract(right);
		}

		friend vec3 operator*(vec3 left, const vec3& right)
		{
			return left.multiply(right);
		}

		friend vec3 operator/(vec3 left, const vec3& right)
		{
			return left.divide(right);
		}

		vec3& operator+=(const vec3& v)
		{
			return add(v);
		}

		vec3& operator-=(const vec3& v)
		{
			return subtract(v);
		}

		vec3& operator*=(const vec3& v)
		{
			return multiply(v);
		}

		vec3& operator/=(const vec3& v)
		{
			return divide(v);
		}

		bool operator==(const vec3& v)
		{
			return (x == v.x && y == v.y && z == v.z);
		}

		bool operator!=(const vec3& v)
		{
			return (x != v.x && y != v.y && z != v.z);
		}
	};

}
