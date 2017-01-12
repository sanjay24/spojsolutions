#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
map<int, int> inputs;
map<int, int> newlist;

int main() {
	while(true) {
		int n;
		scanf("%d", &n);
		if(n==0) break;
		int x;
		for(int i=1;i<=n;++i) {
			scanf("%d", &x);
			inputs[i] = x;
		}
		bool isAmb = true;
		for(int i=1;i<=n;++i) {
			newlist[inputs[i]] = i;
		}
		for(int i=1;i<=n;++i) {
			if(newlist[i] != inputs[i]) {
				isAmb = false;
			}
		}
		if(isAmb) {
			printf("ambiguous\n");
		} else {
			printf("not ambiguous\n");
		}
	}
	return 0;
}
