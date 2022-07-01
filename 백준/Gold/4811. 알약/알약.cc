#include<iostream>
#include<algorithm>
#define INF 199999999
using namespace std;

long long dp[31][31];
long long sum(int w, int h);
int n;
void input() {
	cin >> n;
	cout << dp[0][6];
}

long long sum(int w, int h) {
	if (w < 0 || h < 0) return 0;
	if (w == 0 && h == 0) return 1;
	if (dp[w][h] != 0) return dp[w][h];
	return dp[w][h] = sum(w - 1, h) + sum(w + 1, h - 1);
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	sum(0, 30);
	while (1) {
		cin >> n;
		if (n == 0) break;
		cout << dp[0][n]<<"\n";
	}
}