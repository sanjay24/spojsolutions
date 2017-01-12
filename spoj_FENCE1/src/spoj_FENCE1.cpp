#include <cmath>
#include <iostream>
#include <cstdio>
using namespace std;
const float pi = 3.1415926;
int main() {
	while(true) {
		int t;
		scanf("%d", &t);
		if(t==0) break;

		double ans = ((double)t*(double)t)/(2*pi);
		printf("%.2f\n", ans);
	}
	return 0;
}
