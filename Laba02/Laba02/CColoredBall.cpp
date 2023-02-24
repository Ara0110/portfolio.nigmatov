#include "CColoredBall.h"

CColoredBall::CColoredBall(void)
{
	this->brush = CreateSolidBrush(RGB(0, 0, 0));
}

CColoredBall::~CColoredBall(void)
{
	DeleteBrush(this->brush);
}

void CColoredBall::SetColor(unsigned char r, unsigned char g, unsigned char b)
{
	DeleteBrush(this->brush);

	this->brush = CreateSolidBrush(RGB(r, g, b));
}
void CColoredBall::Draw(HDC dc)
{

	HBRUSH oldBrush = SelectBrush(dc, this->brush);

	Ellipse(dc, (this->GetX() - this->GetR()), (this->GetY() - this->GetR()), (this->GetX() + this->GetR()), (this->GetY() + this->GetR()));

	SelectBrush(dc, oldBrush);
}