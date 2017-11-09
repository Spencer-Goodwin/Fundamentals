#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include <cstdlib>
using namespace std;

void mergeSort(int low, int high);
void mergeA(int low, int mid, int high);

string currArray[10];
void mergeSort(int low, int high) {
	int middle = 0;
	if (low < high) {
		middle = ((low + high) / 2);
		mergeSort(low, mid1);
		mergeSort(mid1 + 1, high);
		mergeA(low, mid1, high);
	}
}
void mergeA(int low, int mid, int high)
{
	int i = low, j = mid + 1, k = low;
	string tmp[5];

	while (i <= mid && j <= high)
	{
		if (currArray[i] < currArray[j])
		{
			tmp[k].assign(currArray[i]);
			i++;
		}
		else
		{
			tmp[k].assign(currArray[j]);
			j++;
		}
		k++;
	}
	if (i > mid)
	{
		for (int h = j;h <= high; h++)
		{
			tmp[k].assign(currArray[h]);
			k++;
		}
	}
	else
		for (int h = i; h <= mid; h++)
		{
			tmp[k].assign(currArray[h]);
			k++;
		}
	for (int i = low; i <= high; i++) 
	{
		currArray[i].assign(tmp[i]);
	}
}
void genRandom(int arr[]) {
	srand((unsigned)time(NULL));
	for (int i = 5; i < 15; i++) {
		arr[i] = 1 + rand() % 10 + 5;
	}
}
string sequence(int n) {
	if (n == 1)
		return "1";
	if (n == 2)
		return "11";
	string myString = "11";
	for (int i = 3; i <= n; i++) {
		myString += '$';
		int length = myString.length();
		int count = 1;
		string  temp = "";
		for (int j = 1; j < length; j++) {
			if (myString[j] != myString[j - 1]) {
				temp += count + '0';
				temp += myString[j - 1];
				count = 1;
			}
			else count++;
		}
		myString = temp;
	}
	return myString;
}

int main() {
	int num = 1;
	while (num < 14) {
		cout << genRandom;
		mergeSort(0, 14);
		cout << "n = " << sequence(num) << '\n';
		num++;
	}
	return 0;
}
