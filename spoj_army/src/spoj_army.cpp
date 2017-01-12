#include <cstdio>
#include <algorithm>
#include <iostream>
#include <deque>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		deque<int> gz;
		deque<int> mgz;
		int ngz, nmgz;
		scanf("%d %d", &ngz, &nmgz);
		for(int i=0;i<ngz; ++i) {
			int s;
			scanf("%d", &s);
			gz.push_back(s);
		}
		for(int i=0;i<nmgz; ++i) {
			int s;
			scanf("%d", &s);
			mgz.push_back(s);
		}
		sort(gz.begin(), gz.end());
		sort(mgz.begin(), mgz.end());
		while(!gz.empty() && !mgz.empty()) {
			if(gz.front() == mgz.front()) {
				mgz.pop_front();
			} else if (gz.front() < mgz.front()) {
				gz.pop_front();
			} else {
				mgz.pop_front();
			}
		}
		if(gz.size() == mgz.size()) {
			printf("uncertain\n");
		} else if (gz.size() > mgz.size()) {
			printf("Godzilla\n");
		} else if (mgz.size() > gz.size()) {
			printf("MechaGodzilla\n");
		}
	}
	return 0;
}
