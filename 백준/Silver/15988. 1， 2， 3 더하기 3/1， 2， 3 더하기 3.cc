#include<iostream>

using namespace std;
int T;
int dp[1000004];

void solve() {
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 1; i <= 1000000; i++) {
		dp[i + 1] = (dp[i + 1] + dp[i]) % 1000000009;
		dp[i + 2] = (dp[i + 2] + dp[i]) % 1000000009;
		dp[i + 3] = (dp[i + 3] + dp[i]) % 1000000009;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	cin >> T;
	while (T--) {
		int num;
		cin >> num;
		cout << dp[num] << "\n";
	}
}