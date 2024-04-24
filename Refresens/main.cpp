#include <iostream>

using namespace std;

void main()
{
	setlocale(0, "");
	int a = 2;
	int& ra = a;
	ra += 3;
	cout << a << "\n" << &a << "\n" << &ra;
}