#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;
int N, M, K,max_num;
vector<int> v;
int func() {
	int m, l = 1, r = max_num;
	int total = 0;
	while (l < r) {
		total = 0;
		//cout << l << r << endl;
		m = (l + r) / 2;
		for (int i = 0; i < N; i++) {
			total += min(m, v[i]);
		}
		if (total > M) {
			r = m;
		}
		else {
			l = m + 1;
		}
	}
	total = 0;
	for (int i = 0; i < N; i++) {
		total += min(r, v[i]);
	}
	if (total > M)
		return r - 1;
	else return r;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		max_num = max(max_num,n);
		v.push_back(n);
	}
	cin >> M;
	cout << func() << endl;
}