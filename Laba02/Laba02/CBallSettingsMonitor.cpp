
#include "CBallSettingsMonitor.h"
#include <math.h>


CBallSettingsMonitor::CBallSettingsMonitor(void)
{
	this->angle = 45;
	this->speed = 50;
	this->r = 255;
	this->g = 255;
	this->b = 255;
}

CBallSettingsMonitor::~CBallSettingsMonitor(void)
{
}


void CBallSettingsMonitor::Draw(HDC dc)
{
	HBRUSH oldBrush = SelectBrush(dc, CreateSolidBrush(RGB(r, g, b)));

	double halfspeed = ((this->speed / 120) * 30) / 2;
	double rad_angle = (this->angle / 180) * 3.1415;

	double x = halfspeed * cos(rad_angle);
	double y = halfspeed * sin(rad_angle);

	Rectangle(dc, 0, 0, 30, 30);

	MoveToEx(dc, (15 - x), (15 - y), NULL);
	LineTo(dc, (15 + x), (15 + y));

	Ellipse(dc, (15 + x - 2), (15 + y - 2), (15 + x + 2), (15 + y + 2));
	SelectBrush(dc, oldBrush);
}

void CBallSettingsMonitor::SpeedUp()
{
	if (this->speed < 120)
		speed++;
}


void CBallSettingsMonitor::SpeedDown()
{
	if (this->speed > 10)
		speed--;
}

void CBallSettingsMonitor::AngleUp()
{
	angle++;

	if (this->angle >= 360)
		angle = 0;
}

void CBallSettingsMonitor::AngleDown()
{
	angle--;

	if (this->angle <= 0)
		angle = 360;
}


void CBallSettingsMonitor::GetVxVy(double& vx, double& vy)
{
	double rad_angle = (this->angle / 180) * 3.1415;

	vx = this->speed * cos(rad_angle);
	vy = this->speed * sin(rad_angle);
}

int CBallSettingsMonitor::GetR()
{
	return r;
}

int CBallSettingsMonitor::GetG()
{
	return g;
}

int CBallSettingsMonitor::GetB()
{
	return b;
}

void CBallSettingsMonitor::SetColor(int r, int g, int b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}

void CBallSettingsMonitor::UpR()
{
	if (r == 255)
	{
		r = 0;
	}
	else
	{
		r = r + 5;
	}
	SetColor(r, g, b);
}
void CBallSettingsMonitor::DownR()
{
	if (r == 0)
	{
		r = 255;
	}
	else
	{
		r = r - 5;
	}
	SetColor(r, g, b);
}
void CBallSettingsMonitor::UpG()
{
	if (g == 255)
	{
		g = 0;
	}
	else
	{
		g = g + 5;
	}
	SetColor(r, g, b);
}
void CBallSettingsMonitor::DownG()
{
	if (g == 0)
	{
		g = 255;
	}
	else
	{
		g = g - 5;
	}
	SetColor(r, g, b);
}
void CBallSettingsMonitor::UpB()
{
	if (b == 255)
	{
		b = 0;
	}
	else
	{
		b = b + 5;
	}
	SetColor(r, g, b);
}
void CBallSettingsMonitor::DownB()
{
	if (b == 0)
	{
		b = 255;
	}
	else
	{
		b = b - 5;
	}
	SetColor(r, g, b);
}