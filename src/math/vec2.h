#ifndef VEC2_H
#define VEC2_H

#include <iostream>
#include <cmath>

class vec2
{

public:
	vec2();
	vec2(float, float);

	float length();

	float x, y;

	vec2 operator+(const vec2&);
	vec2 operator-(const vec2&);
	vec2 operator*(float);
	vec2 operator/(float);

	vec2& operator+=(const vec2&);
	vec2& operator-=(const vec2&);
	vec2& operator*=(float);
	vec2& operator/=(float);

	bool operator==(const vec2&);
	bool operator!=(const vec2&);

	friend std::ostream& operator<<(std::ostream&, vec2&);

};

#endif
