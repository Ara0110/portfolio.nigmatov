#include <iostream>
using namespace std;

void main()
{
	float km,
		Litres,
		Price;
	cout << "\n Way = ";
	cin >> km;
	cout << "\n Litres = ";
	cin >> Litres;
	cout << "\n Price = ";
	cin >> Price;
	cout << "\n Result = " << (km / 100) * Litres * Price << "\n";
}
