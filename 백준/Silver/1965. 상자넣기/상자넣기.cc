#include<iostream>
#include<algorithm>
using namespace std;

int N;
int arr[1001];
int dp[1001];

void input() {
	int answer = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int maxNum = 0;
		cin >> arr[i];
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				maxNum = max(maxNum, dp[j]);
			}
		}
		dp[i] = maxNum + 1;
		answer = max(answer, dp[i]);
	}
	cout << answer << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
}