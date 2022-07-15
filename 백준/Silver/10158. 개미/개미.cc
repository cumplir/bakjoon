#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#define MAX 1999999999

using namespace std;

int N, M,x,y,t;

void Move() {
	int t1 = (((2 * M) + t) % (2 * M));
	int t2 = (((2 * N) + t) % (2 * N));

	if (M - x < t1) {
		t1 -= (M - x);
		if (t1 > M) {
			t1 -= M;
			x = t1;
		}
		else {
			x = M - t1;
		}
	}
	else {
		x += t1;
	}



	if (N - y < t2) {
		t2 -= (N - y);
		if (t2 > N) {
			t2 -= N;
			y = t2;
		}
		else {
			y = N - t2;
		}
	}
	else {
		y += t2;
	}
	
	cout << x <<" "<< y;
}
void input() {
	cin >> M >> N >> x >> y >> t;
	Move();
}
int main() {
	input();
}