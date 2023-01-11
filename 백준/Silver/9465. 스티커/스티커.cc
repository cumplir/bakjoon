#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int N;
int arr[2][100001];
int dp[2][100001];

void print() {
	for (int i = 0; i < N; i++) {
		cout << dp[0][i]<<" ";
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << dp[1][i] << " ";
	}
	cout << endl << endl;
}
void input() {
	cin >> N;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	dp[0][N - 1] = arr[0][N - 1];
	dp[1][N - 1] = arr[1][N - 1];
	//print();
	if (N > 1) {
		dp[0][N - 2] = dp[1][N - 1] + arr[0][N - 2];
		dp[1][N - 2] = dp[0][N - 1] + arr[1][N - 2];
		//print();
	}
	if (N > 2) {
		for (int i = N - 3; i >= 0; i--) {
			dp[0][i] = max(dp[0][i], dp[1][i + 1] + arr[0][i]);
			dp[0][i] = max(dp[0][i], dp[1][i + 2] + arr[0][i]);

			dp[1][i] = max(dp[1][i], dp[0][i + 1] + arr[1][i]);
			dp[1][i] = max(dp[1][i], dp[0][i + 2] + arr[1][i]);
			//print();
		}
	}
	cout << max(dp[0][0], dp[1][0])<<endl;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		memset(dp, 0, sizeof(dp));
		input();
	}
}