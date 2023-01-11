#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<char> stk;

void reducePPAP() {
	while (1) {
		if (stk.size() < 4) return;
		int cur = stk.size()-1;
		if (stk[cur - 3] == 'P' && stk[cur - 2] == 'P' && stk[cur - 1] == 'A' && stk[cur] == 'P') {
			stk.pop_back(); stk.pop_back(); stk.pop_back();
		}
		else
			return;
	}
}

void print() {
	for (int i = 0; i < stk.size(); i++) {
		cout << stk[i];
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string st;
	cin >> st;
	for (int i = 0; i < st.size(); i++) {
		stk.push_back(st[i]);
		reducePPAP();
		//print();
	}
	if (stk.size() == 1 && stk[0] == 'P')
		cout << "PPAP" << endl;
	else
		cout << "NP" << endl;
}