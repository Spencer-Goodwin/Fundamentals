#include <iostream>
#include <string>
#include <stack>
using namespace std;

int getWeight(char myChar) {
	switch (myChar) {
	case '/':
	case '*': return 2;
	case '+':
	case '-': return 1;
	default: return 0;
	}
}
void inpostchange(char inchange[], char postchange[], int size) {
	stack<char> s;
	int weight;
	int i = 0;
	int k = 0;
	char myChar; 
	while (i < size) {
		myChar = inchange[i];
		if (myChar == '(') {
			s.push(myChar);
			i++;
			continue;
		}
		if (myChar == ')') {
			while (!s.empty() && s.top() != '(') {
				postchange[k++] = s.top();
				s.pop();
			}
			if (!s.empty()) {
				s.pop();
			}
			i++;
			continue;
		}
		weight = getWeight(myChar);
		if (weight == 0) {
			postchange[k++] = myChar;
		}
		else {
			if (s.empty()) {
				s.push(myChar);
			}
			else {
				while (!s.empty() && s.top() != '(' &&
					weight <= getWeight(s.top())) {
					postchange[k++] = s.top();
					s.pop();
				}
				s.push(myChar);
			}
		}
		i++;
	} 
	while (!s.empty()) {
		postchange[k++] = s.top();
		s.pop();
	}
	postchange[k] = 0;  
}

int main() {
	char inchange[] = "8 * (1 + 4)";
	int size = strlen(inchange);
	char postchange[1000];
	inpostchange(inchange, postchange, size);
	cout << "\nInchange Expression : " << inchange;
	cout << "\nPostchange Expression : " << postchange;
	cout << endl;
	return 0;
}
