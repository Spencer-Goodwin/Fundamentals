/*Part one*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void BubbleSort(vector<int> &r) {
for (int i = 1; i < r.size(); i++) {
for (int k = 0; k < r.size() - 1; k++) {
if (r[k] > r[i]) swap(r[k], r[i]);
}
}
}
int main() {
vector<int> r = { 34, 12, 1, 20, 4, 6, 78 };
BubbleSort(r);
for (int i = 0; i < r.size(); i++) {
cout << r[i] << '\n';
}
system("pause");
return 0;

/*Part two*/
int main() {
	string Array[5];
	int i, j, num;
	cout << "\nHow many times would you like to sort?: ";
	cin >> num;
	for (i = 0; i <= 4; i++) {
		cout << "\nEnter the name: ";
		cin >> Array[i];
	}
	for (i = 0; i <= 3; i++) {
		for (j = i + 1; j <= 5; j++) {
			string temp;
			if (Array[i] > Array[j]) {
				temp = Array[i];
				Array[i] = Array[j];
				Array[j] = temp;
			}
		}
	}
	for (i = 0; i <= 4; i++) {
		cout << '\n' << Array << '\n';
	}
	system("pause");
	return 0;
}
