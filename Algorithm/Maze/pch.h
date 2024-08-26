#pragma once
#include "Types.h"
#include <windows.h>
#include <iostream>
#include <vector>

using namespace std;

struct POS
{
	bool operator==(POS& other)
	{
		return y == other.y && x == other.x;
	}

	bool operator!=(POS& other)
	{
		return !(*this == other);
	}

	POS operator+(POS* other)
	{
		POS ret;
		ret.y = y + other->y;
		ret.x = x + other->x;
		return ret;
	}

	POS operator+=(POS& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	int32 y = 0;
	int32 x = 0;
};

enum Dir
{
	DIR_UP = 0,
	DIR_LEFT = 1,
	DIR_DOWN = 2,
	DIR_RIGHT = 3,

	DIR_COUNT = 4
};