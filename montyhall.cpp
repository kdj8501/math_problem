#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int montyhall(int n, int pass) {
	int sel = n;
	// cout << "Your first selection is door " << sel << endl;
	// cout << "Pass is door " << pass << endl;
	for (int i = 0; i < 3; i++)
		if (i != n && i != pass) {
			// cout << "door " << i << " open" << endl;
			for (int j = 0; j < 3; j++)
				if (j != i && j != n) {
					// cout << "You change selection to door " << j << endl;
					sel = j;
				}
			break;
		}
	if (sel == pass) {
		// cout << "You win !" << endl;
		return 0;
	}
	else{
		// cout << "You lose !" << endl;
		return 1;
	}
}

int main(void) {
	srand(time(NULL));
	/* int pass = rand() % 3;
	int input;
	do {
		cout << "Select a door (0 ~ 2) >> ";
		cin >> input;
	} while (input < 0 || input > 2);
	montyhall(input, pass); */
	int events = 1000000;
	int win = 0;
	int lose = 0;
	int pass, sel, result;
	for (int i = 0; i < events; i++) {
		pass = rand() % 3;
		sel = rand() % 3;
		result = montyhall(sel, pass);
		if (result == 0)
			win++;
		else
			lose++;
	}
	cout << "events: " << events << " time(s)" << endl;
	cout << "win: " << win << ", lose: " << lose << endl;
	cout << "win rate: " << (double)win / (win + lose) << endl;
	return 0;
}
