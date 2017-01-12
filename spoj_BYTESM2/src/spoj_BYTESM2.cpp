#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;
#define H 100
#define W 100
int matrix[H][W];
int memo[H][W];

int mymax(int i, int j, int k) {
	return max(i, max(j, k));
}
int count(int i, int j, int h, int w) {
	if(i>=h || j>=w || j<0) return 0;
	if(memo[i][j] != -1) return memo[i][j];

	int c = matrix[i][j] + mymax(count(i+1, j, h, w), count(i+1, j-1, h, w), count(i+1, j+1, h, w));
	memo[i][j] = c;
	return c;
}
void initMemo() {
	for(int i=0;i<100;++i) {
		for(int j=0;j<100; ++j) {
			memo[i][j] = -1;
		}
	}
}
void genTest() {
	std::srand(std::time(0)); // use current time as seed for random generator
	for(int i=0;i<100;++i) {
		for(int j=0;j<100; ++j) {
			cout<<rand()%101<<" ";
		}
		cout<<endl;
	}
}
int main() {
	int t;
	//genTest();
	//return 0;
	scanf("%d", &t);

	while(t--) {
		initMemo();
		int h, w;
		scanf("%d %d", &h, &w);
		for(int i=0;i<h;++i) {
			for(int j=0;j<w;++j) {
				scanf("%d", &matrix[i][j]);
			}
		}
		int max = 0;
		for(int i=0;i<w; ++i) {
			int c = count(0, i, h, w);
			if(max<c) {
				max = c;
			}
		}
		printf("%d\n", max);
	}
	return 0;
}
