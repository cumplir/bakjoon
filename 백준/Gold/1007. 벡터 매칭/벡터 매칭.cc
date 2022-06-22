#include<iostream>
#include<vector>
#include<utility>
#include<cstring>
#include<cmath>

#define min(A,B) A<B?A:B
#define INF 1999999999
using namespace std;

int N;
void bruteforce(int st, int n);
double calc();
double answer = INF;
vector<pair<int, int>> v;
int* arr;
void input() {
	cin >> N;
	arr = new int[N];
	for (int i = 0; i < N; i++) {
		arr[i] = 0;
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}
	bruteforce(0,0);
}

double calc() {
	int curx = 0, cury = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] == 0) {
			curx -= v[i].first;
			cury -= v[i].second;
		}
		else {
			curx += v[i].first;
			cury += v[i].second;
		}
	}
	return sqrt(pow(curx, 2) + pow(cury, 2));
}

void bruteforce(int st,int n){
	if (n == N / 2) {
		answer = min(calc(), answer);
	}
	else {
		for (int i = st; i < N; i++) {
			arr[i] = 1;
			bruteforce(i + 1, n + 1);
			arr[i] = 0;
		}
	}
}
void init() {
	answer = INF;
	v.clear();
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		init();
		input();
		printf("%.7lf\n", answer);
	}
}