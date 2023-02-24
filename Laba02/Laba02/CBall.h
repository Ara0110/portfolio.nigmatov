#pragma once
#include <Windows.h>
#include <WindowsX.h>


class CBall
{
	double x, y;
	double vx, vy;
	double r;
	double m;
	RECT bounds;
public:
	CBall();
	void SetParams(double x, double y, double vx, double vy, double r,double m, RECT rect);
	~CBall(void);
	virtual void SetColor(unsigned char r, unsigned char g, unsigned char b);
	virtual void Draw(HDC dc);
	void Move(DWORD ticks);
	void SetBounds(RECT bnds);
	double GetX();
	double GetY();
	double GetVx();
	double GetVy();
	double GetR();
	virtual double GetM();
	void SetVx(double vx);
	void SetVy(double vy);
};
