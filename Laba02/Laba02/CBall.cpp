#include "CBall.h"

CBall::CBall()
{
}


void CBall::SetParams(double x, double y, double vx, double vy, double r,double m, RECT rect)
{
	this->bounds = rect;
	this->x = x;
	this->y = y;
	this->vx = vx;
	this->vy = vy;
	this->r = r;
	this->m = m;
}


CBall::~CBall(void)
{

}

void CBall::Draw(HDC dc)
{
	Ellipse(dc, (x - r), (y - r), (x + r), (y + r));
}

void CBall::Move(DWORD ticks)
{
	double s_delta = ((double)ticks) / 1000.0;
	if ((this->x >= (bounds.right - r)) && (this->vx > 0))
		this->vx = -(this->vx);
	if ((this->x <= r) && (this->vx < 0))
		this->vx = -(this->vx);

	if ((this->y >= (bounds.bottom - r)) && (this->vy > 0))
		this->vy = -(this->vy);
	if ((this->y <= r) && (this->vy < 0))
		this->vy = -(this->vy);

	double dx = vx * s_delta;
	double dy = vy * s_delta;

	this->x += dx;
	this->y += dy;
}

void CBall::SetBounds(RECT bnds)
{
	this->bounds = bnds;
}


double CBall::GetX()
{
	return this->x;
}


double CBall::GetY()
{
	return this->y;
}


double CBall::GetVx()
{
	return this->vx;
}


double CBall::GetVy()
{
	return this->vy;
}


double CBall::GetR()
{
	return this->r;
}

double CBall::GetM()
{
	return this->m;
}


void CBall::SetVx(double vx)
{
	this->vx = vx;
}


void CBall::SetVy(double vy)
{
	this->vy = vy;
}

void CBall::SetColor(unsigned char r, unsigned char g, unsigned char b)
{
}