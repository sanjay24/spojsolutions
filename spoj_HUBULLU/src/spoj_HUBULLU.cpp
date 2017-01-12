#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
int check(int n, int user) {
	if(n==1) return user;
	vector<bool> sieve(n+1, false);
	int ans = user? 0: 1; // flipping to get the first user
	for(int i=2; i<=n; ++i) {
		if(sieve[i]) continue;
		ans=ans^1;

		for(int j=i; j<=n; j+=i) {
			sieve[j] = true;
		}
	}
	return ans;
}
int check2(int n, int user) {
	if(n==1) return user;
	int ans = user? 0: 1;
	for(int i=2; i<=n; ++i) {
		if(n/i){
			ans = ans^1;
		}
	}
	return ans;
}
int main() {
	int t;
	int u=0;
	//scanf("%d", &t);
	t=1;
	while(t--) {
		for(int n=1; n<=1000; ++n) {
			cout<<"checking for "<<n<<"    =>  ";
			//int n;
			//scanf("%d %d", &n, &u);
			int ans = check(n, u);
			//int ans2 = check2(n, u);
			//if(ans!=ans2) {
		//		printf("DIFFERENT\n");
		//		return 0;
		//	}

			if(ans) {
				printf("Pagfloyd wins.\n");

			} else {
				printf("Airborne wins.\n");

			}
		}
	}
	return 0;
}
