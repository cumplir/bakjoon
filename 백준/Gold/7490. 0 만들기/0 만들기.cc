#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>

#define INF 1e17
using namespace std;
int N;
vector<string> v;

void func(int t,int cnt, string st) {
	
	if (cnt == N + 1) {
		int tmp = 0, sum = 0;
		char arith = '*';
		for (int i = 0; i < t; i++) {
			if (st[i] == '+') {
				arith = '+';
			}
			else if (st[i] == '-') {
				arith = '-';
			}
			else if (st[i] == ' ') {
				tmp *= 10;
			}
			else{
				tmp += (st[i]-48);
				if (i + 1 == t || st[i + 1] == '-' || st[i + 1] == '+') {
					if (arith == '+') {
						sum += tmp;
						tmp = 0;
					}
					else if (arith == '-') {
						sum -= tmp;
						tmp = 0;
					}
					else {
						sum += tmp;
						tmp = 0;
					}
				}
			}
		}
		if (sum == 0) {
			v.push_back(st);
		}
		return;
	}

	if (t % 2==1) {
		func(t + 1, cnt, st + ' ');
		func(t + 1, cnt, st + '+');
		func(t + 1, cnt, st + '-');
	}
	else {
		func(t + 1, cnt + 1, st+char(cnt + 48));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		func(0, 1, "");
		v.push_back("");
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}