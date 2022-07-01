#include<iostream>
#include<algorithm>
#define INF 199999999
using namespace std;

int dp[10001];
int coin[100];
int n, k;
int func();
int input() {
	cin >> n >> k;
	fill(dp, dp + 10001, INF);
	for (int i = 0; i < n; i++) {
		cin>>coin[i];
		if(coin[i]<10001)
			dp[coin[i]] = 1;
	}
	dp[0] = 0;
	int answer = func();
	if (answer == INF)
		return -1;
	else
		return answer;
}

int func() {
	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <=k; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}
	return dp[k];
}

int main() {
	cout<<input()<<endl;
}