#include<iostream>
#include<string>
#include<utility>
#include<vector>
using namespace std;

vector<pair<string, float>> v;

float grade(string st){
	for (int i = 0; i < 9; i++) {
		if (st.compare(v[i].first) == 0)
			return v[i].second;
	}
}
void input()
{
	v.push_back({ "A+",4.5 });
	v.push_back({ "A0",4.0 });
	v.push_back({ "B+",3.5 });
	v.push_back({ "B0",3.0 });
	v.push_back({ "C+",2.5 });
	v.push_back({ "C0",2.0 });
	v.push_back({ "D+",1.5 });
	v.push_back({ "D0",1.0 });
	v.push_back({ "F",0.0 });
	string str;
	string grd;
	float Num,result=0.0,sum=0.0;
	for(int i=0;i<20;i++)
	{
		cin >> str >> Num >> grd;
		if(grd.compare("P")==0)
			continue;
		result+=Num* grade(grd);
		sum += Num;
	}
	cout << result / sum;
}

int main() {
	input();
}