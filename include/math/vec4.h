#pragma once

namespace math {

	struct vec4 {
		float x, y, z, w;

		vec4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
		vec4(float scalar) : x(scalar), y(scalar), z(scalar), w(scalar) {}
		vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
		vec4(const vec4& v) : x(v.x), y(v.y), z(v.z), w(v.w) {}

		vec4& add(const vec4& v)
		{
			x += v.x;
			y += v.y;
			z += v.z;
			w += v.w;

			return *this;
		}

		vec4& subtract(const vec4& v)
		{
			x -= v.x;
			y -= v.y;
			z -= v.z;
			w -= v.w;

			return *this;
		}

		vec4& multiply(const vec4& v)
		{
			x *= v.x;
			y *= v.y;
			z *= v.z;
			w *= v.w;

			return *this;
		}

		vec4& divide(const vec4& v)
		{
			x /= v.x;
			y /= v.y;
			z /= v.z;
			w /= v.w;

			return *this;
		}

		friend vec4 operator+(vec4 left, const vec4& right)
		{
			return left.add(right);
		}

		friend vec4 operator-(vec4 left, const vec4& right)
		{
			return left.subtract(right);
		}

		friend vec4 operator*(vec4 left, const vec4& right)
		{
			return left.multiply(right);
		}

		friend vec4 operator/(vec4 left, const vec4& right)
		{
			return left.divide(right);
		}

		vec4& operator+=(const vec4& v)
		{
			return add(v);
		}

		vec4& operator-=(const vec4& v)
		{
			return subtract(v);
		}

		vec4& operator*=(const vec4& v)
		{
			return multiply(v);
		}

		vec4& operator/=(const vec4& v)
		{
			return divide(v);
		}

		bool operator==(const vec4& v)
		{
			return (x == v.x && y == v.y && z == v.z && w == v.w);
		}

		bool operator!=(const vec4& v)
		{
			return (x != v.x && y != v.y && z != v.z && w != v.w);
		}
	};

}
