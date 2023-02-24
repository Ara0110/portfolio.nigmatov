#include <windows.h>

#include <windowsx.h>

#include "CHLimiter.h"

class CBALL

{

	HBRUSH hBrush;

	HBRUSH hBrush2;

	DWORD prev_ticks;

	RECT bounds;

	double x, y;

	double vx, vy;

	double r;

	CHLimiter* limit1;

public:

	CBALL(double x, double y, double vx, double vy, double r);

	~CBALL();

	void Draw(HDC dc);

	void Move(DWORD ticks);

	void SetBounds(RECT bnds);

	void SetCHLimiter(CHLimiter* l);
	void speedup(double g);
	void speeddown(double g);

};



