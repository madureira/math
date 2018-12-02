#pragma once

#include <math.h>
#include <sstream>
#include <string>

namespace math {

	struct vec2 {
		float x, y;

		vec2() : x(0), y(0) {}
		vec2(float scalar) : x(scalar), y(scalar) {}
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

		vec2& add(float scalar)
		{
			x += scalar;
			y += scalar;

			return *this;
		}

		vec2& subtract(float scalar)
		{
			x -= scalar;
			y -= scalar;

			return *this;
		}

		vec2& multiply(float scalar)
		{
			x *= scalar;
			y *= scalar;

			return *this;
		}

		vec2& divide(float scalar)
		{
			x /= scalar;
			y /= scalar;

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

		friend vec2 operator+(vec2 left, float scalar)
		{
			return vec2(left.x + scalar, left.y + scalar);
		}

		friend vec2 operator-(vec2 left, float scalar)
		{
			return vec2(left.x - scalar, left.y - scalar);
		}

		friend vec2 operator*(vec2 left, float scalar)
		{
			return vec2(left.x * scalar, left.y * scalar);
		}

		friend vec2 operator/(vec2 left, float scalar)
		{
			return vec2(left.x / scalar, left.y / scalar);
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

		vec2& operator+=(float scalar)
		{
			return add(scalar);
		}

		vec2& operator-=(float scalar)
		{
			return subtract(scalar);
		}

		vec2& operator*=(float scalar)
		{
			return multiply(scalar);
		}

		vec2& operator/=(float scalar)
		{
			return divide(scalar);
		}

		bool operator==(const vec2& v) const
		{
			return (x == v.x && y == v.y);
		}

		bool operator!=(const vec2& v) const
		{
			return (x != v.x && y != v.y);
		}

		bool operator<(const vec2& v) const
		{
			return x < v.x && y < v.y;
		}

		bool operator<=(const vec2& v) const
		{
			return x <= v.x && y <= v.y;
		}

		bool operator>(const vec2& v) const
		{
			return x > v.x && y > v.y;
		}

		bool operator>=(const vec2& v) const
		{
			return x >= v.x && y >= v.y;
		}

		float dot(const vec2& v) const
		{
			return x * v.x + y * v.y;
		}

		float magnitude() const
		{
			return std::sqrt(x * x + y * y);
		}

		float distance(const vec2& v) const
		{
			float a = x - v.x;
			float b = y - v.y;

			return std::sqrt(a * a + b * b);
		}

		vec2 normalize() const
		{
			float lenght = magnitude();
			return vec2(x / lenght, y / lenght);
		}

		std::string toString() const
		{
			std::stringstream result;
			result << "vec2:(" << x << ", " << y << ")";
			return result.str();
		}

		friend std::ostream& operator<<(std::ostream& stream, const vec2& vector)
		{
			stream << vector.toString();
			return stream;
		}
	};

}
