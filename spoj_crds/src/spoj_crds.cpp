#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		ll total = (ll)n*(ll)(1+n)/2;
		//cout<<"total = "<<total<<endl;
		total = total*3-n;
		cout<<total%1000007<<"\n";
	}
	return 0;
}
