#include "vec2.h"
#include <cmath>
#include <iostream>

vec2::vec2() {}
vec2::vec2(float xin, float yin) :x(xin), y(yin) {}



bool vec2::operator ==(const vec2& rhs) const
{
	return (x == rhs.x && y == rhs.y);
}
bool vec2::operator != (const vec2& rhs) const
{
	return (x != rhs.x && y != rhs.y);
}



vec2 vec2::operator + (const vec2& rhs) const
{
	return vec2(x + rhs.x, y + rhs.y);
}
vec2 vec2::operator - (const vec2& rhs) const
{
	return vec2(x - rhs.x, y - rhs.y);
}
vec2 vec2::operator * (const float val) const
{
	return vec2(x * val, y * val);
}
vec2 vec2::operator / (const float val) const
{
	if (val == 0) // Avoid division by zero
	{
		std::cerr << "there's error, please check \"vec2\" class\nyou divide by Zero\n\"operator / (const float val)\" function\n";
		exit(-1);
	}
	return vec2(x / val, y / val);
}



void vec2::operator += (const vec2& rhs)
{
	x += rhs.x;
	y += rhs.y;
}
void vec2::operator -= (const vec2& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
}
void vec2::operator *= (const float val)
{

	x *= val;
	y *= val;
}
void vec2::operator /= (const float val)
{
	if (val == 0) // Avoid division by zero
	{
		std::cerr << "there's error, please check \"vec2\" class\nyou divide by Zero\n\"operator /= (const float val)\" function\n";
		exit(-1);
	}
	x /= val;
	y /= val;
}



float vec2::dist(const vec2& rhs) const
{
	return sqrt((x - rhs.x) * (x - rhs.x) + (y - rhs.y) * (y - rhs.y));
}

float vec2::length() const
{
	return sqrt(x * x + y * y);
}

vec2 vec2::normalization() const
{
	float len = length();
	if (len == 0) // Avoid division by zero
	{
		std::cerr << "there's error, please check \"vec2\" class\nyou divide by Zero\n\"normalization()\" function\n";
		exit(-1);
	}
	return vec2(x / len, y / len); // Normalize the vector
}

vec2 vec2::normalization(const float& length) const
{
	if (length == 0) // Avoid division by zero
	{
		std::cerr << "there's error, please check \"vec2\" class\nyou divide by Zero\n\"normalization(const float& length)\" function\n";
		exit(-1);
	}
	return vec2(x / length, y / length); // Normalize the vector
}

