#pragma once

#include <math.h>
#include <sstream>
#include <string>

namespace math {

	struct vec4 {
		float x, y, z, w;

		vec4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
		vec4(float scalar) : x(scalar), y(scalar), z(scalar), w(scalar) {}
		vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
		vec4(const vec4& vector) : x(vector.x), y(vector.y), z(vector.z), w(vector.w) {}

		vec4& add(const vec4& vector)
		{
			x += vector.x;
			y += vector.y;
			z += vector.z;
			w += vector.w;

			return *this;
		}

		vec4& subtract(const vec4& vector)
		{
			x -= vector.x;
			y -= vector.y;
			z -= vector.z;
			w -= vector.w;

			return *this;
		}

		vec4& multiply(const vec4& vector)
		{
			x *= vector.x;
			y *= vector.y;
			z *= vector.z;
			w *= vector.w;

			return *this;
		}

		vec4& divide(const vec4& vector)
		{
			x /= vector.x;
			y /= vector.y;
			z /= vector.z;
			w /= vector.w;

			return *this;
		}

		vec4& add(float scalar) {
			x += scalar;
			y += scalar;
			z += scalar;
			w += scalar;

			return *this;
		}

		vec4& subtract(float scalar) {
			x -= scalar;
			y -= scalar;
			z -= scalar;
			w -= scalar;

			return *this;
		}

		vec4& multiply(float scalar)
		{
			x *= scalar;
			y *= scalar;
			z *= scalar;
			w *= scalar;

			return *this;
		}

		vec4& divide(float scalar)
		{
			x /= scalar;
			y /= scalar;
			z /= scalar;
			w /= scalar;

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

		friend vec4 operator+(vec4 left, float scalar)
		{
			return vec4(left.x + scalar, left.y + scalar, left.z + scalar, left.w + scalar);
		}

		friend vec4 operator-(vec4 left, float scalar)
		{
			return vec4(left.x - scalar, left.y - scalar, left.z - scalar, left.w - scalar);
		}

		friend vec4 operator*(vec4 left, float scalar)
		{
			return vec4(left.x * scalar, left.y * scalar, left.z * scalar, left.w * scalar);
		}

		friend vec4 operator/(vec4 left, float scalar)
		{
			return vec4(left.x / scalar, left.y / scalar, left.z / scalar, left.w / scalar);
		}

		vec4& operator+=(const vec4& vector)
		{
			return add(vector);
		}

		vec4& operator-=(const vec4& vector)
		{
			return subtract(vector);
		}

		vec4& operator*=(const vec4& vector)
		{
			return multiply(vector);
		}

		vec4& operator/=(const vec4& vector)
		{
			return divide(vector);
		}

		vec4& operator+=(float scalar)
		{
			return add(scalar);
		}

		vec4& operator-=(float scalar)
		{
			return subtract(scalar);
		}

		vec4& operator*=(float scalar)
		{
			return multiply(scalar);
		}

		vec4& operator/=(float scalar)
		{
			return divide(scalar);
		}

		bool operator<(const vec4& vector) const
		{
			return x < vector.x && y < vector.y && z < vector.z && w < vector.w;
		}

		bool operator<=(const vec4& vector) const
		{
			return x <= vector.x && y <= vector.y && z <= vector.z && w <= vector.w;
		}

		bool operator>(const vec4& vector) const
		{
			return x > vector.x && y > vector.y && z > vector.z && w > vector.w;
		}

		bool operator>=(const vec4& vector) const
		{
			return x >= vector.x && y >= vector.y && z >= vector.z && w >= vector.w;
		}

		friend vec4 operator-(const vec4& vector)
		{
			return vec4(-vector.x, -vector.y, -vector.z, -vector.w);
		}

		bool operator==(const vec4& vector)
		{
			return (x == vector.x && y == vector.y && z == vector.z && w == vector.w);
		}

		bool operator!=(const vec4& vector)
		{
			return (x != vector.x && y != vector.y && z != vector.z && w != vector.w);
		}

		float length() const
		{
			return std::sqrt(x * x + y * y + z * z + w * w);
		}

		float distance(const vec4& vector) const
		{
			float a = x - vector.x;
			float b = y - vector.y;
			float c = z - vector.z;
			float d = w - vector.w;

			return std::sqrt(a * a + b * b + c * c + d * d);
		}

		std::string toString() const
		{
			std::stringstream result;
			result << "vec4:(" << x << ", " << y << ", " << z  << ", " << w << ")";
			return result.str();
		}

		friend std::ostream& operator<<(std::ostream& stream, const vec4& vector)
		{
			stream << vector.toString();
			return stream;
		}
	};

}
