#include "CBALL.h"

CBALL::CBALL(double x, double y, double vx, double vy, double r)

{

	hBrush = CreateSolidBrush(RGB(0, 255, 0));

	this->x = x;

	this->y = y;

	this->vx = vx;

	this->vy = vy;

	this->r = r;

	this->prev_ticks = GetTickCount();

}

CBALL::~CBALL()

{

	DeleteObject(hBrush);

}

void CBALL::Draw(HDC dc)

{

	HBRUSH hOldBrush;

	hOldBrush = SelectBrush(dc, hBrush);

	Ellipse(dc, x - r, y - r, x + r, y + r);

	SelectBrush(dc, hOldBrush);

}

void CBALL::SetCHLimiter(CHLimiter* l)

{

	this->limit1 = l;

}
void CBALL::speedup(double g)
{
	this->vx += g;
	this->vy += g;
}
void CBALL::speeddown(double g)
{
	this->vx -= g;
	this->vy -= g;
}

void CBALL::Move(DWORD ticks)

{

	double s_delta = ((double)(ticks - this->prev_ticks)) / 500.0;

	if ((this->x >= bounds.right - r) && (this->vx > 0))

		this->vx = -(this->vx);

	if ((this->x <= r) && (this->vx < 0))

		this->vx = -(this->vx);

	if ((this->y >= bounds.bottom - r) && (this->vy > 0))

		this->vy = -(this->vy);

	if ((this->y <= r) && (this->vy < 0))

		this->vy = -(this->vy);

	if (((this->x + r) >= limit1->GetMinX()) && ((this->x - r) <= limit1->GetMaxX()))

	{

		if (this->vy > 0)

		{

			if (((limit1->GetY() - this->y) < this->r) && ((limit1->GetY() - this->y) > 0))

				this->vy = -(this->vy);

		}

		else

		{

			if (((this->y - limit1->GetY()) < this->r) && ((this->y - limit1->GetY()) > 0))

				this->vy = -(this->vy);

		}

	}

	this->prev_ticks = ticks;

	double dx = vx * s_delta;

	double dy = vy * s_delta;

	this->x += dx;

	this->y += dy;

}

void CBALL::SetBounds(RECT bnds)

{

	this->bounds = bnds;

}
