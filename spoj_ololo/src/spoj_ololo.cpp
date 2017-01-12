#include <cstdio>
#include <iostream>
#include <cmath>
#include <map>

using namespace std;
int main() {
	int t;
	scanf("%d", &t);

	int num = 0;
	for(int i=0;i<t;++i){
		int d;
		scanf("%d", &d);
		num ^= d;
	}
	printf("%d", num);

	return 0;
}
