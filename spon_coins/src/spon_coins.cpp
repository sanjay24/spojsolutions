#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>

using namespace std;
#define ll long long
map<int, int> memo;


ll val(ll n) {
	if(memo[n] != 0) return memo[n];
	if(n == 1) return 1;
	if(n==0) return 0;
	ll sum  = (ll)val(n/2)+(ll)val(n/3)+(ll)val(n/4);
	ll ans = max(sum, n);
	memo[n] = ans;
	return ans;
}
int main() {
	int n;
	while (cin>>n) {
		cout<<val(n)<<"\n";
	}
	return 0;
}
