#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;
int visited[1001][1001];
char graph[1001][1001];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
typedef struct pair<pair<int,int>, pair<int,int>> PPII;
queue<PPII> q;
void print();
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}
}

int func() {
	int ans = 199999999;
	q.push({ {0,0},{1,1} });
	while (!q.empty()) {
		int y = q.front().first.first, x = q.front().first.second,
			id = q.front().second.first, d = q.front().second.second;
		q.pop();
		if (y == N - 1 && x == M - 1) {
			ans = min(d, ans);
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M && visited[ny][nx]!=1) {
				if (id == 1) {
					if (graph[ny][nx] == '1')
						q.push({ {ny,nx},{2,d + 1} });
					else
						q.push({ {ny,nx},{1,d + 1} });
				}
				else if(graph[ny][nx]=='0'&&visited[ny][nx]!=2) {
					q.push({ { ny,nx }, { id,d + 1 }});
				}
				visited[ny][nx] = id;
			}
		}
	}
	if (ans == 199999999) return -1;
	return ans;
}

int main() {
	input();
	cout << func() << endl;
}