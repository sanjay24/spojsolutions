#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int s;
	scanf("%d", &s);
	for(int t=1;t<=s;++t){
		vector<int> inputs;
		int reqd, friends;
		scanf("%d %d", &reqd, &friends);
		for(int i=0;i<friends;++i) {
			int f;
			scanf("%d", &f);
			inputs.push_back(f);
		}
		long long total = 0;
		int ans = 0;
		bool found = false;
		sort(inputs.begin(), inputs.end(), std::greater<int>());

		for(int i=0; i<friends;++i) {
			total+=inputs[i];
			ans++;
			if(total >= reqd) {
				found = true;
				break;
			}
		}

		if(found) {
			printf("Scenario #%d:\n%d\n", t, ans);
		} else {
			printf("Scenario #%d:\nimpossible\n", t);
		}
		printf("\n");
	}
	return 0;
}
