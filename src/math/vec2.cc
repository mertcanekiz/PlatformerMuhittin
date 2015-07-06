#include "vec2.h"

vec2::vec2()
{
	x = y = 0;
}

vec2::vec2(float x, float y)
{
	this->x = x;
	this->y = y;
}

float vec2::length()
{
	return sqrt(x*x + y*y);
}

vec2 vec2::operator+(const vec2& v)
{
	return vec2(x + v.x, y + v.y);
}

vec2 vec2::operator-(const vec2& v)
{
	return vec2(x - v.x, y - v.y);
}

vec2 vec2::operator*(float a)
{
	return vec2(x * a, y * a);
}

vec2 vec2::operator/(float a)
{
	if(a == 0)
		return vec2();
	return vec2(x / a, y / a);
}

vec2& vec2::operator+=(const vec2& v)
{
	x += v.x;
	y += v.y;

	return *this;
}

vec2& vec2::operator-=(const vec2& v)
{
	x -= v.x;
	y -= v.y;

	return *this;
}

vec2& vec2::operator*=(float a)
{
	x *= a;
	y *= a;

	return *this;
}

vec2& vec2::operator/=(float a)
{
	if(a != 0)
	{
		x /= a;
		y /= a;
	}

	return *this;
}

bool vec2::operator==(const vec2& v)
{
	return (x == v.x && y == v.y);
}

bool vec2::operator!=(const vec2& v)
{
	return !(*this==v);
}

std::ostream& operator<<(std::ostream& out, vec2& v)
{
	out << v.x << ", " << v.y;
}
