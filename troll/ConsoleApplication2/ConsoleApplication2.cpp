#include <iostream>

using namespace std;

int main()
{
	string zero[7] = { "+---+",
					"|   |",
					"|   |",
					"+   +",
					"|   |",
					"|   |",
					"+---+" };
	string one[7] = { "    +",
				   "    |",
				   "    |",
				   "    +",
				   "    |",
				   "    |",
				   "    +" };
	string two[7] = { "+---+",
				   "    |",
				   "    |",
				   "+---+",
				   "|    ",
				   "|    ",
				   "+---+" };
	string three[7] = { "+---+",
					 "    |",
					 "    |",
					 "+---+",
					 "    |",
					 "    |",
					 "+---+" };
	string four[7] = { "+   +",
					"|   |",
					"|   |",
					"+---+",
					"    |",
					"    |",
					"    +" };
	string five[7] = { "+---+",
					"|    ",
					"|    ",
					"+---+",
					"    |",
					"    |",
					"+---+" };
	string six[7] = { "+---+",
				   "|    ",
				   "|    ",
				   "+---+",
				   "|   |",
				   "|   |",
				   "+---+" };
	string seven[7] = { "+---+",
					 "    |",
					 "    |",
					 "    +",
					 "    |",
					 "    |",
					 "    +" };
	string eight[7] = { "+---+",
					 "|   |",
					 "|   |",
					 "+---+",
					 "|   |",
					 "|   |",
					 "+---+" };
	string nine[7] = { "+---+",
					"|   |",
					"|   |",
					"+---+",
					"    |",
					"    |",
					"+---+" };
	string dot[7] = { " ",
				   " ",
				   "o",
				   " ",
				   "o",
				   " ",
				   " " };

	string g[11][7] = { zero,one,two,three,four,five,six,seven,eight,nine,dot };

	string x;
	while (cin >> x) {
		if (x == "end") {
			cout << "end" << endl;
			break;
		}
		int num[5];
		for (int i = 0; i < 5; i++) {
			if (isdigit(x[i])) {
				num[i] = (int)(x[i] - '0');
			}
			else {
				num[i] = 10;
			}
		}
		//1 6 10 4 7

		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 5; j++) {
				if (j == 4) {
					cout << g[num[j]][i];
				}
				else {
					cout << g[num[j]][i] << "  ";
				}
			}
			cout << endl;
		}
		cout << endl;
		cout << endl;
	}
	return 0;
}


