#include <iostream>

using namespace std;

void display(short num) {
	static bool A = num & 0b1000;
	static bool B = num & 0b0100;
	static bool C = num & 0b0010;
	static bool D = num & 0b0001;
	static bool a = A + C + (B & D) + (!B & !D);
	static bool b = A + !B + (!A & !C & !D) + (!A & C & D);
	static bool c = A + B + (!A & !C) + (!A & D);
	static bool d = A + (C & !D) + (!B & C) + (!B & !D) + (B & !C & D);
	static bool e = (C & !D) + (!B & !D);
	static bool f = A + (B & !C) + (B & !D) + (!B & !C & !D);
	static bool g = A + (B & !D) + (B & !C) + (!B & C);
	static bool map[7][4] = {
		0,a,a,0,
		f,0,0,b,
		f,0,0,b,
		0,g,g,0,
		e,0,0,c,
		e,0,0,c,
		0,d,d,0
	};
	int x, y;
	cout << "Input: " << A << B << C << D << endl;
	cout << "Output: " << a << b <<c << d << e << f << g << endl;
	for (y=0; y<7; y++) {
		for (x=0; x<4; x++) {
			cout << (map[y][x] ? 'x' : ' ');
		};
		cout << endl;
	};
};

int main() {
	short num;
	cout << "Enter a number (0-9): ";
	cin >> num;
	display(num);
	return 0;
};
