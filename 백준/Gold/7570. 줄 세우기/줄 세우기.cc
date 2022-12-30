#include<iostream>
#include<vector>
using namespace std;

vector<int> v;

int arr[1000001];
int dp[1000001];
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int N;
	int answer = 1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp[arr[i]] = dp[arr[i] - 1] + 1;
		answer=max(dp[arr[i]], answer);
	}
	cout << N - answer << endl;
}