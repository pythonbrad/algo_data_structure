#include <iostream>
#include <unistd.h>

using namespace std;

void display(short num) {
	bool A = num & 0b1000;
	bool B = num & 0b0100;
	bool C = num & 0b0010;
	bool D = num & 0b0001;
	bool a = A + C + (B & D) + (!B & !D);
	bool b = A + !B + (!A & !C & !D) + (!A & C & D);
	bool c = A + B + (!A & !C) + (!A & D);
	bool d = A + (C & !D) + (!B & C) + (!B & !D) + (B & !C & D);
	bool e = (C & !D) + (!B & !D);
	bool f = A + (B & !C) + (B & !D) + (!B & !C & !D);
	bool g = A + (B & !D) + (B & !C) + (!B & C);
	bool map[7][4] = {
		0,a,a,0,
		f,0,0,b,
		f,0,0,b,
		0,g,g,0,
		e,0,0,c,
		e,0,0,c,
		0,d,d,0
	};
	int x, y;
	for (y=0; y<7; y++) {
		for (x=0; x<4; x++) {
			cout << (map[y][x] ? 'x' : ' ');
		};
		cout << endl;
	};
};

int main() {
	short num=0;
	while (1) {
		for(num=0; num<10;num++){
			system("clear");
			display(num);
			sleep(1);
		};
	};
	return 0;
};
