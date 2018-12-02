#pragma once

#include <math.h>
#include <sstream>
#include <string>

namespace math {

	struct vec3 {
		float x, y, z;

		vec3() : x(0.0f), y(0.0f), z(0.0f) {}
		vec3(float scalar) : x(scalar), y(scalar), z(scalar) {}
		vec3(float x, float y, float z) : x(x), y(y), z(z) {}
		vec3(const vec3& vector) : x(vector.x), y(vector.y), z(vector.z) {}

		vec3& add(const vec3& vector)
		{
			x += vector.x;
			y += vector.y;
			z += vector.z;

			return *this;
		}

		vec3& subtract(const vec3& vector)
		{
			x -= vector.x;
			y -= vector.y;
			z -= vector.z;

			return *this;
		}

		vec3& multiply(const vec3& vector)
		{
			x *= vector.x;
			y *= vector.y;
			z *= vector.z;

			return *this;
		}

		vec3& divide(const vec3& vector)
		{
			x /= vector.x;
			y /= vector.y;
			z /= vector.z;

			return *this;
		}

		vec3& add(float scalar)
		{
			x += scalar;
			y += scalar;
			z += scalar;

			return *this;
		}

		vec3& subtract(float scalar)
		{
			x -= scalar;
			y -= scalar;
			z -= scalar;

			return *this;
		}

		vec3& multiply(float scalar)
		{
			x *= scalar;
			y *= scalar;
			z *= scalar;

			return *this;
		}

		vec3& divide(float scalar)
		{
			x /= scalar;
			y /= scalar;
			z /= scalar;

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

		friend vec3 operator+(vec3 left, float scalar)
		{
			return vec3(left.x + scalar, left.y + scalar, left.z + scalar);
		}

		friend vec3 operator-(vec3 left, float scalar)
		{
			return vec3(left.x - scalar, left.y - scalar, left.z - scalar);
		}

		friend vec3 operator*(vec3 left, float scalar)
		{
			return vec3(left.x * scalar, left.y * scalar, left.z * scalar);
		}

		friend vec3 operator/(vec3 left, float scalar)
		{
			return vec3(left.x / scalar, left.y / scalar, left.z / scalar);
		}

		vec3& operator+=(const vec3& vector)
		{
			return add(vector);
		}

		vec3& operator-=(const vec3& vector)
		{
			return subtract(vector);
		}

		vec3& operator*=(const vec3& vector)
		{
			return multiply(vector);
		}

		vec3& operator/=(const vec3& vector)
		{
			return divide(vector);
		}

		vec3& operator+=(float scalar)
		{
			return add(scalar);
		}

		vec3& operator-=(float scalar)
		{
			return subtract(scalar);
		}

		vec3& operator*=(float scalar)
		{
			return multiply(scalar);
		}

		vec3& operator/=(float scalar)
		{
			return divide(scalar);
		}

		bool operator==(const vec3& vector)
		{
			return x == vector.x && y == vector.y && z == vector.z;
		}

		bool operator!=(const vec3& vector)
		{
			return x != vector.x && y != vector.y && z != vector.z;
		}

		bool operator<(const vec3& vector) const
		{
			return x < vector.x && y < vector.y && z < vector.z;
		}

		bool operator<=(const vec3& vector) const
		{
			return x <= vector.x && y <= vector.y && z <= vector.z;
		}

		bool operator>(const vec3& vector) const
		{
			return x > vector.x && y > vector.y && z > vector.z;
		}

		bool operator>=(const vec3& vector) const
		{
			return x >= vector.x && y >= vector.y && z >= vector.z;
		}

		friend vec3 operator-(const vec3& vector)
		{
			return vec3(-vector.x, -vector.y, -vector.z);
		}

		float dot(const vec3& vector) const
		{
			return x * vector.x + y * vector.y + z * vector.z;
		}

		vec3 cross(const vec3& vector) const
		{
			return vec3(y * vector.z - z * vector.y, z * vector.x - x * vector.z, x * vector.y - y * vector.x);
		}

		float length() const
		{
			return std::sqrt(x * x + y * y + z * z);
		}

		float distance(const vec3& vector) const
		{
			float a = x - vector.x;
			float b = y - vector.y;
			float c = z - vector.z;

			return std::sqrt(a * a + b * b + c * c);
		}

		vec3 normalize() const
		{
			float magnitude = length();
			return vec3(x / magnitude, y / magnitude, z / magnitude);
		}

		std::string toString() const
		{
			std::stringstream result;
			result << "vec3:(" << x << ", " << y << ", " << z << ")";
			return result.str();
		}

		friend std::ostream& operator<<(std::ostream& stream, const vec3& vector)
		{
			stream << vector.toString();
			return stream;
		}
	};

}
