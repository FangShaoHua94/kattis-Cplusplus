#include <iostream>

using namespace std;

int main() {

	string g[11][7] = { { "+---+", "|   |", "|   |", "+   +", "|   |", "|   |",
			"+---+" }, { "    +", "    |", "    |", "    +", "    |", "    |",
			"    +" }, { "+---+", "    |", "    |", "+---+", "|    ", "|    ",
			"+---+" }, { "+---+", "    |", "    |", "+---+", "    |", "    |",
			"+---+" }, { "+   +", "|   |", "|   |", "+---+", "    |", "    |",
			"    +" }, { "+---+", "|    ", "|    ", "+---+", "    |", "    |",
			"+---+" }, { "+---+", "|    ", "|    ", "+---+", "|   |", "|   |",
			"+---+" }, { "+---+", "    |", "    |", "    +", "    |", "    |",
			"    +" }, { "+---+", "|   |", "|   |", "+---+", "|   |", "|   |",
			"+---+" }, { "+---+", "|   |", "|   |", "+---+", "    |", "    |",
			"+---+" }, { " ", " ", "o", " ", "o", " ", " " } };

	string x;
	while (cin >> x) {
		if (x == "end") {
			cout << "end" << endl;
			break;
		}
		int num[5];
		for (int i = 0; i < 5; i++) {
			if (isdigit(x[i])) {
				num[i] = (int) (x[i] - '0');
			} else {
				num[i] = 10;
			}
		}
		//1 6 10 4 7

		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 5; j++) {
				if (j == 4) {
					cout << g[num[j]][i];
				} else {
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

