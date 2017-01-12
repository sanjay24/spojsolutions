#include <cstdio>
#include <iostream>
using namespace std;
int main() {
	while(true) {
		float c;
		scanf("%f", &c);
		if(c==0) break;
		float sum=0;
		int count=0;
		int d = 2;
		while(sum<=c) {
			count++;
			sum += 1/(float)d;
			d++;
			//cout<<sum<<endl;
		}
		printf("%d card(s)\n", count);
	}
	return 0;
}
