#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

typedef pair<int, int> PII;
vector<pair<PII, PII>> v;
int N;
int p[3001];
int cnt[3001];

int ccw(PII p1, PII p2, PII p3) {
	int cross_product = (p2.first - p1.first) * (p3.second - p1.second) - (p3.first - p1.first) * (p2.second - p1.second);
	if (cross_product > 0) {
		return 1;
	}
	else if (cross_product < 0) {
		return -1;
	}
	else {
		return 0;
	}
}

int getp(int i) {
	if (i == p[i]) return i;
	return p[i] = getp(p[i]);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		v.push_back({ {x1,y1},{x2,y2} });
	}

	for (int i = 0; i < N; i++)
		p[i] = i;

	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			PII p1 = v[i].first, p2 = v[i].second, p3 = v[j].first, p4 = v[j].second;
			if ((ccw(p1, p2, p3) * ccw(p1, p2, p4) <=0) && (ccw(p3, p4, p1) * ccw(p3, p4, p2) <=0)) {
				if ((p1.first > p3.first && p1.first > p4.first && p2.first > p3.first && p2.first > p4.first) ||
					(p1.first < p3.first && p1.first < p4.first && p2.first < p3.first && p2.first < p4.first)) continue;
				else if ((p1.second > p3.second && p1.second > p4.second && p2.second > p3.second && p2.second > p4.second)
					|| (p1.second < p3.second && p1.second < p4.second && p2.second < v[j].first.second && p2.second < p4.second)) continue;
				else {
					int a = getp(i);
					int b = getp(j);
					if (a < b) p[b] = a;
					else p[a] = b;
				}
			}
		}
	}

	int MaxG = 0, groupcnt = 0;
	for (int i = 0; i < N; i++) {
		cnt[getp(i)]++;
	}
	for (int i = 0; i < N; i++) {
		if (cnt[i] != 0)
			groupcnt++;
		MaxG = max(cnt[i], MaxG);
	}
	cout << groupcnt << endl<<MaxG<<endl;
}
