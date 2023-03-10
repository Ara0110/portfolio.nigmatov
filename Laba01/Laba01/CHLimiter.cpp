#include "CHLimiter.h"

CHLimiter::CHLimiter(int xmax, int xmin, int y)

{

	this->xmax = xmax;

	this->xmin = xmin;

	this->y = y;

}

CHLimiter::~CHLimiter()

{

}

void CHLimiter::Draw(HDC dc)

{

	::MoveToEx(dc, this->xmin, this->y, NULL);

	::LineTo(dc, this->xmax, this->y);

}

int CHLimiter::GetMaxX()

{

	return this->xmax;

}

int CHLimiter::GetMinX()

{

	return this->xmin;

}

int CHLimiter::GetY()

{

	return this->y;

}

void CHLimiter::MoveX(int inc)

{

	this->xmax -= inc;

	this->xmin -= inc;

}

void CHLimiter::MoveY(int inc)

{

	this->y -= inc;

}



