#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
char arr[501][501];
bool arr2[501][501][6];
queue<pair<pair<int, int>,pair<int,int>>> q;
int dice[6];
int stx, sty, edx, edy;
int change_dice(int d,int b){
	if (b == 0) {
		if (d == 0) {
			return 4;
		}
		if (d == 1) {
			return 2;
		}
		if (d == 2) {
			return 1;
		}
		if (d == 3) {
			return 3;
		}
	}
	if (b == 1) {
		if (d == 0) {
			return 1;
		}
		if (d == 1) {
			return 1;
		}
		if (d == 2) {
			return 5;
		}
		if (d == 3) {
			return 0;
		}
	}
	if (b == 2) {
		if (d == 0) {
			return 0;
		}
		if (d == 1) {
			return 5;
		}
		if (d == 2) {
			return 2;
		}
		if (d == 3) {
			return 2;
		}
	}
	if (b == 3) {
		if (d == 0) {
			return 3;
		}
		if (d == 1) {
			return 3;
		}
		if (d == 2) {
			return 0;
		}
		if (d == 3) {
			return 5;
		}
	}
	if (b == 4) {
		if (d == 0) {
			return 5;
		}
		if (d == 1) {
			return 0;
		}
		if (d == 2) {
			return 4;
		}
		if (d == 3) {
			return 4;
		}
	}
	if (b == 5) {
		if (d == 0) {
			return 2;
		}
		if (d == 1) {
			return 4;
		}
		if (d == 2) {
			return 3;
		}
		if (d == 3) {
			return 1;
		}
	}
}

void input() {
	int N, M;
	memset(arr2, false, sizeof(arr2));
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'D') {
				stx = j, sty = i;
			}
			if (arr[i][j] == 'R') {
				edx = j; edy = i;
			}
		}
	}
}

int bfs(int y,int x,int d) {

	q.push({ {y,x},{0,0} });
	arr2[y][x][0] = true;
	while (!q.empty())
	{
		y = q.front().first.first;
		x = q.front().first.second;
		d = q.front().second.first;
		int t = q.front().second.second;
		q.pop();
		if (y == edy && x == edx && d == 0)
			return t;
		if (y == edy && x == edx) continue;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i],nd = change_dice(i, d);
			if (arr[ny][nx] != '#'&& !arr2[ny][nx][nd]){
				arr2[ny][nx][nd] = true;
				q.push({ {ny,nx},{nd,t+1}});
			}
		}
	}
	return -1;
}

int main() {
	input();
	cout<<bfs(sty, stx, 0)<<endl;
}