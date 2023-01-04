#include<iostream>

using namespace std;

int N, M;
int arr[2001];
bool dp[2001][2001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	for (int i = 1; i <= N; i++) {
		dp[i][i] = true;
		if (arr[i] == arr[i - 1]) {
			dp[i - 1][i] = true;
		}
	}
	for (int i = 2; i < N; i++) {
		for (int j = 1; j <= N - i; j++) {
			if (arr[j] == arr[j + i] && dp[j + 1][j + i - 1])
				dp[j][j + i] = true;
		}
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		cout << dp[s][e] << "\n";
	}
}