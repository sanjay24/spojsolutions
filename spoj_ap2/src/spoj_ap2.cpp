#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		ll third, third_last, sum;
		cin>>third>>third_last>>sum;
		ll n = (sum * 2)/(third + third_last);
		ll d = (third_last - third)/(n-5);
		ll a = third - 2*d;
		cout<<n<<"\n";
		for(int i=0;i<n;++i) {
			cout<<a+i*d<<" ";
		}
		printf("\n");
	}
	return 0;
}
