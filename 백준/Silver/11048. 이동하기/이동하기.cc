#include<iostream>
#include<queue>
using namespace std;

queue <pair<int, int>> q;
int N, M;
int dx[3] = { -1,0,-1 };
int dy[3] = { 0,-1,-1 };
int dp[1001][1001];
int arr[1001][1001];
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
}

void func() {
	q.push({N - 1,M - 1});
	dp[N - 1][M - 1] = arr[N - 1][M - 1];
	while (!q.empty()) {
		int y = q.front().first, x = q.front().second;
		q.pop();
		for (int i = 0; i < 3; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny < N && ny >= 0 && nx<M && nx >= 0 && dp[y][x] + arr[ny][nx]>dp[ny][nx]) {
				dp[ny][nx] = dp[y][x] + arr[ny][nx];
				q.push({ ny,nx });
			}
		}
	}
	cout << dp[0][0];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	func();
}