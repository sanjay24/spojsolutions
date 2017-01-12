#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long

const char* str[] = { "192", "442", "692", "942"};
int main() {
	ll t;
	cin>>t;
	for(ll i=0;i<t;++i) {
		ll k;
		cin>>k;
		k=k-1;
		ll q = k/4;
		ll r = k%4;
		if (q) {
			cout<<q<<str[r];
		} else {
			cout<<str[r];
		}
		cout<<"\n";
	}
	return 0;
}
