#include <cstdio>
#include <string.h>
#include <sstream>
#include <iostream>
using namespace std;
typedef long long ll;
enum Optype{
	MINUS,
	PLUS
};

void oper(int& n, Optype op) {
	if(op == MINUS) --n;
	else if(op == PLUS) ++n;
}

string getTerm(int n) {
	int col = 2;
	int row = 1;
	char ans[16];
	string pre[4] = {"", "1/1", "1/2", "2/1"};
	if(n>3) {
		ll count=2;
		Optype cop =  MINUS;
		Optype rop = PLUS;
		while(count<n){
			oper(row, rop);
			oper(col, cop);
			sprintf(ans, "%d/%d", row,col);
			count++;

			if(col==1 && count<n) {
				row++;
				count++;

				cop = PLUS;
				rop = MINUS;
				sprintf(ans, "%d/%d", row,col);

				continue;
			}

			if(row==1 && count<n){
				count++;

				col++;
				cop = MINUS;
				rop = PLUS;
				sprintf(ans, "%d/%d", row,col);

				continue;
			}
		}
	} else {
		strcpy(ans, pre[n].c_str());
	}


	return string(ans);
}



int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		printf("TERM %d IS %s\n", n, getTerm(n).c_str());
	}
	return 0;
}
