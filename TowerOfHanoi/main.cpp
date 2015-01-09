/* 2014-09-05 */
/* ººÅµËþ */
#include<iostream>
using namespace std;

void moveDISKs(int n, char fromTower, char toTower, char auxTower) {
	if (n == 1)
		cout << "Move disk " << n << " from [" << fromTower << "] to [" << toTower << "]" << endl;
	else {
		moveDISKs(n - 1, fromTower, auxTower, toTower);
		cout << "Move disk " << n << " from [" << fromTower << "] to [" << toTower << "]" << endl;
		moveDISKs(n - 1, auxTower, toTower, fromTower);
	}

}

int main(int argc, char* argv[]) {
	moveDISKs(5, 'A', 'B', 'C');
}