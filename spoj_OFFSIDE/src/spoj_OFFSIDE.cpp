#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int a,d;
	while(true) {
		cin>>a>>d;
		if(a==0 && d==0) break;
		vector<int> ai;
		vector<int> di;
		for(int i=0;i<a;++i) {
			int x;
			cin>>x;
			ai.push_back(x);
		}
		for(int i=0;i<d;++i) {
			int x;
			cin>>x;
			di.push_back(x);
		}
		sort(ai.begin(), ai.end());
		sort(di.begin(), di.end());
		if(ai[0] < di[1]) {
			cout<<"Y\n";
		}else {
			cout<<"N\n";
		}
	}
	return 0;
}
