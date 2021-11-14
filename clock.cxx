/*	CLOCK by pythonbrad
 * 	This is a clock in c++ programing ins using boolean algebra
 * 
 * 
*/
#include <iostream>
#include <ctime>
#include <unistd.h>

using namespace std;

void seven_segment_decoder(short num, bool *output) {
	bool A = num & 0b1000;
	bool B = num & 0b0100;
	bool C = num & 0b0010;
	bool D = num & 0b0001;
	output[0] = A + C + (B & D) + !(B + D);
	output[1] = A + !B + !(A + C + D) + (!A & C & D);
	output[2] = A + B + !(A + C) + (!A & D);
	output[3] = A + (C & !D) + (!B & C) + !(B + D) + (B & !C & D);
	output[4] = (C & !D) + !(B + D);
	output[5] = A + (B & !C) + (B & !D) + !(B + C + D);
	output[6] = A + (B & !D) + (B & !C) + (!B & C);
};

void display(short num1, short num2, short num3, short num4, short num5, short num6) {
	bool output1[7];
	seven_segment_decoder(num1, output1);
	bool a1 = output1[0];
	bool b1 = output1[1];
	bool c1 = output1[2];
	bool d1 = output1[3];
	bool e1 = output1[4];
	bool f1 = output1[5];
	bool g1 = output1[6];
	bool output2[7];
	seven_segment_decoder(num2, output2);
	bool a2 = output2[0];
	bool b2 = output2[1];
	bool c2 = output2[2];
	bool d2 = output2[3];
	bool e2 = output2[4];
	bool f2 = output2[5];
	bool g2 = output2[6];
	bool output3[7];
	seven_segment_decoder(num3, output3);
	bool a3 = output3[0];
	bool b3 = output3[1];
	bool c3 = output3[2];
	bool d3 = output3[3];
	bool e3 = output3[4];
	bool f3 = output3[5];
	bool g3 = output3[6];
	bool output4[7];
	seven_segment_decoder(num4, output4);
	bool a4 = output4[0];
	bool b4 = output4[1];
	bool c4 = output4[2];
	bool d4 = output4[3];
	bool e4 = output4[4];
	bool f4 = output4[5];
	bool g4 = output4[6];
	bool output5[7];
	seven_segment_decoder(num5, output5);
	bool a5 = output5[0];
	bool b5 = output5[1];
	bool c5 = output5[2];
	bool d5 = output5[3];
	bool e5 = output5[4];
	bool f5 = output5[5];
	bool g5 = output5[6];
	bool output6[7];
	seven_segment_decoder(num6, output6);
	bool a6 = output6[0];
	bool b6 = output6[1];
	bool c6 = output6[2];
	bool d6 = output6[3];
	bool e6 = output6[4];
	bool f6 = output6[5];
	bool g6 = output6[6];
	bool map[7][33] = {
		00,a1,a1,00,00,00,a2,a2,00,00,00,00,00,a3,a3,00,00,00,a4,a4,00,00,00,00,00,a5,a5,00,00,00,a6,a6,00,
		f1,00,00,b1,00,f2,00,00,b2,00,00,00,f3,00,00,b3,00,f4,00,00,b4,00,00,00,f5,00,00,b5,00,f6,00,00,b6,
		f1,00,00,b1,00,f2,00,00,b2,00,00,00,f3,00,00,b3,00,f4,00,00,b4,00,00,00,f5,00,00,b5,00,f6,00,00,b6,
		00,g1,g1,00,00,00,g2,g2,00,00,00,00,00,g3,g3,00,00,00,g4,g4,00,00,00,00,00,g5,g5,00,00,00,g6,g6,00,
		e1,00,00,c1,00,e2,00,00,c2,00,00,00,e3,00,00,c3,00,e4,00,00,c4,00,00,00,e5,00,00,c5,00,e6,00,00,c6,
		e1,00,00,c1,00,e2,00,00,c2,00,00,00,e3,00,00,c3,00,e4,00,00,c4,00,00,00,e5,00,00,c5,00,e6,00,00,c6,
		00,d1,d1,00,00,00,d2,d2,00,00,00,00,00,d3,d3,00,00,00,d4,d4,00,00,00,00,00,d5,d5,00,00,00,d6,d6,00,
	};
	int x, y;
	for (y=0; y<7; y++) {
		for (x=0; x<33; x++) {
			cout << (map[y][x] ? 'x' : ' ');
		};
		cout << endl;
	};
};

int main() {
	time_t r;
	struct tm * timeinfo;
	while (1) {
		// We clean the console
		system("clear");
		// We refresh the time
		time(&r);
		timeinfo = localtime(&r);
		display(timeinfo->tm_hour/10, timeinfo->tm_hour%10, timeinfo->tm_min/10, timeinfo->tm_min%10, timeinfo->tm_sec/10, timeinfo->tm_sec%10);
		sleep(1);
	};
	return 0;
};
