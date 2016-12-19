// grains of rice on chessboard problem

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

inline void keep_window_open() { char ch; cin >> ch; }

inline void simple_error(string s)	// write ``error: s and exit program
{
	cerr << "error: " << s << '\n';
	keep_window_open();		// for some Windows environments
	exit(1);
}

int main() {
	int square{ 1 };
	unsigned long long int rice_sq{ 1 };
	unsigned long long int total_rice{ 0 };
	bool thousand_flag{ false };
	bool million_flag{ false };
	bool billion_flag{ false };

	cout << "On square 1  there is 1 grain of rice.  Total is 1 \n";

	for (int i = 2; i <= 64;i++) {
		square = i;
		rice_sq *= 2;
		total_rice += rice_sq;

		if (!thousand_flag && total_rice >= 1000) {
			thousand_flag = true;
			cout << "BINGO: Need " << square << "square to have at least 1000 grains! \n\n";
		}
		if (!million_flag && total_rice >= 1000000) {
			million_flag = true;
			cout << "BINGO: Need " << square << "square to have at least a million grains! \n\n";
		}
		if (!billion_flag && total_rice >= 1000000000) {
			billion_flag = true;
			cout << "BINGO: Need " << square << "square to have at least a billion grains! \n\n";
		}
		cout << "On square " << i << " there are " << rice_sq << " grains.  Total is " << total_rice << "\n";
	}
	keep_window_open();
}
