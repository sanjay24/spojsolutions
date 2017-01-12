#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
#define MAX 1010
int inputs[MAX];

int main() {
	while(true) {
		int n;
		stack<int> stk;
		scanf("%d", &n);
		if(n==0) break;
		for(int i=0;i<n;++i) {
			scanf("%d", &inputs[i]);
		}
		int c=1;
		vector<int> qu;
		for(int i=0;i<n;++i) {
			if(inputs[i] == c) {
				qu.push_back(c);
				++c;
			} else {
				stk.push(inputs[i]);
			}
			while(!stk.empty() && stk.top() == c){
				qu.push_back(stk.top());
				stk.pop();
				c++;
			}
		}
		while(!stk.empty()) {
			qu.push_back(stk.top());
			stk.pop();
		}
		c=1;
		bool ans = true;
		for(int i=0;i<n;++i,++c) {
			//printf("%d\n", qu[i]);
			if(qu[i] != c) {
				ans = false;
				break;
			}
		}
		if(ans) {
			printf("yes\n");
		}else {
			printf("no\n");
		}
	}
	return 0;
}
