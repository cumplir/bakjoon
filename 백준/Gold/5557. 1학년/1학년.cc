#include<iostream>

using namespace std;

int arr[101];
long long dp[101][21];
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	dp[1][arr[1]] = 1;
	for (int i = 1; i < N - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i][j] == 0) continue;
			if (j + arr[i + 1] <= 20) {
				dp[i + 1][j + arr[i + 1]] += dp[i][j];
			}
			if (j - arr[i + 1] >= 0) {
				dp[i + 1][j - arr[i + 1]] += dp[i][j];
			}
		}
	}
	cout << dp[N - 1][arr[N]] << endl;
}