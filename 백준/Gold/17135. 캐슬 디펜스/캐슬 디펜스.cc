#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#define MAX 1999999999

using namespace std;

int arr[16][16];
int N, M, D;
bool check[16][16];
int Dist(int archorPos, int y, int x) {
	if (archorPos - x > 0)
		return y + archorPos - x;
	else
		return y + x - archorPos;
}
int Attack(int a, int b, int c) {
	int y = N+1;
	int sum = 0;
	while (y > 1) {
		int da = MAX, db = MAX, dc = MAX;
		pair<int, int> p1, p2, p3;
		for (int i = y - 1; i > 0; i--) {
			for (int j = 0; j < M; j++) {
				if (!check[i][j]&&arr[i][j] == 1) {
					int d1 = Dist(a, y - i, j);
					int d2 = Dist(b, y - i, j);
					int d3 = Dist(c, y - i, j);
					if (d1<=D&&d1 <=da) {
						if (d1 < da || (j < p1.second)) {
							da = d1;
							p1 = { i,j };
						}
					}
					if (d2 <= D && d2 <=db) {
						if (d2 < db || (j < p2.second)) {
							db = d2;
							p2 = { i,j };
						}
					}
					if (d3 <= D && d3 <=dc) {
						if (d3<dc||(j<p3.second)) {		
							dc = d3;
							p3 = {i,j};
						}
					}
				}
			}
		}

		if (p1.first!=0&&!check[p1.first][p1.second]) {
			check[p1.first][p1.second] = true;
			sum += 1;
		}
		if (p2.first != 0 && !check[p2.first][p2.second]) {
			check[p2.first][p2.second] = true;
			sum += 1;
		}
		if (p3.first != 0 && !check[p3.first][p3.second]) {
			check[p3.first][p3.second] = true;
			sum += 1;
		}
		y--;
	}

	return sum;
}

int ArchorPos() {
	int answer = 0;

	for (int i = 0; i < M; i++) {
		for (int j = i + 1; j < M; j++) {
			for (int k = j + 1; k < M; k++) {
				memset(check, 0, sizeof(check));
				answer = max(answer, Attack(i, j, k));
			}
		}
	}
	return answer;
}



int main() {
	cin >> N >> M >> D;
	for (int i = 1; i <=N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	cout << ArchorPos();
}