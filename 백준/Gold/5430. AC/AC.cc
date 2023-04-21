#include <iostream>
#include<cstring>
#include<string>
using namespace std;

int arr[100001];
int f[2];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		string cmd,st;
		cin >> cmd;
		int t;
		cin >> t;
		cin >> st;
		string str1 = "";
		int times = 0;
		for (int i = 1; i < st.length(); i++) {
			if (st[i] == ',' || st[i] == ']') {
				if(str1!=""){
					arr[times++] = stoi(str1);
					str1 = "";
				}
			}
			else
				str1 += st[i];
		}

		int cur = 0;
		f[1] = times - 1;
		f[0] = 0;
		for (int i = 0; i < cmd.length(); i++) {
			if (cmd[i] == 'R') {
				cur = (cur + 1) % 2;
			}
			else {
				if (cur == 0) {
					f[0]++;
				}
				if (cur == 1) {
					f[1]--;
				}
			}
		}
		if (f[0]-1 > f[1]) {
			cout << "error" << endl;
		}
		else if (cur == 0) {
			cout << "[";
			for (int i = f[0]; i <= f[1]; i++) {
				if (i == f[1])
					cout << arr[i];
				else
					cout << arr[i] << ",";
			}
			cout << "]"<<endl;
		}
		else if (cur == 1) {
			cout << "[";
			for (int i = f[1]; i >= f[0]; i--) {
				if (i == f[0])
					cout << arr[i];
				else
					cout << arr[i] << ",";
			}
			cout << "]"<<endl;
		}
	}
} 
