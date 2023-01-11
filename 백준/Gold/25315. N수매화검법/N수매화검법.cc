#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;


typedef pair<long, long> PII;
int N;
vector<pair<long long,pair<PII, PII>>> v;
int ccw(PII p1, PII p2, PII p3) {
	long long cross_product = (p2.first - p1.first) * (p3.second - p1.second) - (p3.first - p1.first) * (p2.second - p1.second);

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

int main() {
	long long x1, x2, y1, y2, w;
	long long sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x1 >> y1 >> x2 >> y2 >> w;
		v.push_back({w,{{x1,y1},{x2,y2}}});
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		long long m = 1;
		for (int j = i + 1; j < N; j++) {
			PII p1 = v[i].second.first, p2 = v[i].second.second, p3 = v[j].second.first, p4 = v[j].second.second;
			if ((ccw(p1, p2, p3) * ccw(p1, p2, p4) < 0) && (ccw(p3, p4, p1) * ccw(p3, p4, p2) < 0)) {
				m++;
			}
		}
		sum +=( m*v[i].first);
	}
	cout << sum << endl;
}
