#pragma once

namespace math {

	struct vec2 {
		float x, y;

		vec2() : x(0), y(0) {}
		vec2(const float x, const float y) : x(x), y(y) {}
		vec2(const vec2& v) : x(v.x), y(v.y) {}

		vec2& add(const vec2& v)
		{
			x += v.x;
			y += v.y;

			return *this;
		}

		vec2& subtract(const vec2& v)
		{
			x -= v.x;
			y -= v.y;

			return *this;
		}

		vec2& multiply(const vec2& v)
		{
			x *= v.x;
			y *= v.y;

			return *this;
		}

		vec2& divide(const vec2& v)
		{
			x /= v.x;
			y /= v.y;

			return *this;
		}

		friend vec2 operator+(vec2 left, const vec2& right)
		{
			return left.add(right);
		}

		friend vec2 operator-(vec2 left, const vec2& right)
		{
			return left.subtract(right);
		}

		friend vec2 operator*(vec2 left, const vec2& right)
		{
			return left.multiply(right);
		}

		friend vec2 operator/(vec2 left, const vec2& right)
		{
			return left.divide(right);
		}

		vec2& operator+=(const vec2& v)
		{
			return add(v);
		}

		vec2& operator-=(const vec2& v)
		{
			return subtract(v);
		}

		vec2& operator*=(const vec2& v)
		{
			return multiply(v);
		}

		vec2 operator/=(const vec2& v)
		{
			return divide(v);
		}
	};

}
