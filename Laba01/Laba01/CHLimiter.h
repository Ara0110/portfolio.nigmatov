#include <windows.h>

#include <windowsx.h>

class CHLimiter

{

	int y;

	int xmin, xmax;

public:

	CHLimiter(int xmax, int xmin, int y);

	~CHLimiter();

	void Draw(HDC dc);

	int GetMaxX();

	int GetMinX();

	int GetY();

	void MoveX(int inc);

	void MoveY(int inc);

};




