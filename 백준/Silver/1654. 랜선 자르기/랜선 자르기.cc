#include <iostream>
using namespace std;

int N, K,max_val;
int* arr;
void input() {
	cin >> N >> K;
	arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		max_val = max(max_val, arr[i]);
	}
}

long long BS() {
	long long l = 1, r = max_val,m;
	while (l <= r) {
		m = (l + r) / 2;
		long long sum = 0;
		for (int i = 0; i < N; i++) {
			sum += (arr[i] / m);
		}

		if (sum >= K) l = m + 1;
		else r = m-1;
	}
	return r;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	cout << BS() << endl;
}