#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long ll;
ll N;
ll counting(ll num) {
	ll sum = 0;
	for (ll i = 1; i <= N; i++) {
		if (i * N <= num) sum += N;
		else {
			sum += num / i;
		}
		if (i > num) return sum;
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll K;
	cin >> N>>K;
	ll l=1, r=N*N;
	while (l <=r) {
		ll mid = (l + r) / 2;
		if (counting(mid) <K) {
			l = mid + 1;
		}
		else {
			r = mid-1;
		}
	}
	cout << l << endl;
}