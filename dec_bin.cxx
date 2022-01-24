#include <iostream>

using namespace std;

int main() {
	int num;

	// number of bits
	int s = 32;
	
	cout << "Enter a number: ";
	cin >> num;

	while (s >= 0) {
		cout << ((num & (1 << s)) ? 1 : 0);
		s--;
	};
};
