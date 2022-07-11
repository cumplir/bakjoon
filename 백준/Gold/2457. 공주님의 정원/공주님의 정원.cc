#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
#define INF 19999999
using namespace std;

typedef pair<int, int> PII;
typedef pair<PII, PII> PPII;

priority_queue<PPII,vector<PPII>,greater<PPII>> pq;



int solve() {
	int lm=3, ld=1,n=0;
	while (lm < 12) {
		priority_queue<PPII> ppq;
		while (!pq.empty()) {
			int edm = pq.top().second.first, edd = pq.top().second.second, stm = pq.top().first.first, std = pq.top().first.second;
			if (stm > lm) {
				break;
			}
			else if (stm < lm)
			{
				ppq.push({ {edm,edd},{stm,std} });
				pq.pop();
			}
			else {
				if (std <= ld) {
					ppq.push({ {edm,edd},{stm,std} });
					pq.pop();
				}
				
				else {
					break;
				}
			}
		}

		if (ppq.empty()) return 0;
		lm = ppq.top().first.first, ld = ppq.top().first.second;
		ppq.pop();
		n++;
	}
	return n;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, stm, std, edm, edd;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> stm >> std >> edm >> edd;
		pq.push({ {stm,std},{edm,edd} });
	}
	cout << solve() << endl;
}