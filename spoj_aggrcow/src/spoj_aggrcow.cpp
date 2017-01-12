#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 100001
int x[MAX];
typedef long long ll;

int checkX(int sz, int ncows, int gap) {
	ll prevx = x[0];
	int cows = 1;
	bool ans = false;
	for(int i=1;i<sz;++i) {
		if(x[i]-prevx>=gap) {
			cows++;
			if(cows == ncows) {
				// all the cows can be accomodated with
				// min distance between all barns as 'gap'
				return true;
			}
			prevx = x[i];
		}
	}
	return ans;
}

int search(int sz, int c) {
	int start = x[0];
	int end = x[sz-1];
	while(start<end) {
		int mid =  (end+start)/2;
		if(checkX(sz, c, mid)) {
			start = mid +1;
		} else {
			end = mid;
		}
	}
	return start-1;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, c;
		scanf("%d %d", &n, &c);
		for(int i=0;i<n;++i) {
			scanf("%d", &x[i]);
		}
		sort(x, x+n);

		printf("%d\n", search(n, c));
	}
	return 0;
}
