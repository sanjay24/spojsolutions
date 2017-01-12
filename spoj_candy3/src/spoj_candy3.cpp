
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for(int i=0;i<t;++i) {
		long long n;
		cin>>n;
		long long sum=0;
		for(long long i=0;i<n;++i) {
			long long d;
			cin>>d;
			sum += d;
			sum %= n;
		}
		if(sum) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}
	}
	return 0;
}
