#include <vector>
#include  <cstdio>
#include <iostream>
using namespace std;

enum Player{NIKI, TROF};

vector<int> getDigits(int n) {
	vector<int> digits;
	while(n>0) {
		digits.push_back(n%10);
		n/=10;
	}
	return digits;
}
int move;
bool check(int num_on_desk, Player next_player) {
	if (num_on_desk/10 == 0 && next_player == NIKI) {
		return true;
	}
	if (num_on_desk/10 == 0 && next_player == TROF) {
		return false;
	}

	vector<int> digits = getDigits(num_on_desk);
	int sz = digits.size();
	for(int i=0;i<sz;++i) {
		if(digits[i] == 0) continue;
		Player np = next_player == NIKI? TROF: NIKI;
		if(check(num_on_desk-digits[i], np)) {
			return true;
		}
	}
	return false;
}
int getmax(vector<int>& v) {
	int sz = v.size();
	int mx = -1;
	for(int i=0;i<sz;++i) {
		if(v[i] > mx) mx = v[i];
	}
	return mx;
}
int main() {
	int t;
	scanf("%d", &t);
#if 0
	vector<int> digits = getDigits(t);
	bool ans = false;
	for(int i=0;i<digits.size(); ++i) {
		if(digits[i] == 0) continue;
		if(check(t-digits[i], TROF)) {
			ans = true;
			move = digits[i];
			break;
		}
	}
#endif
	int count = 0;
	int move;
	while(t>0){
		vector<int> digits = getDigits(t);
		int mx = getmax(digits);
		cout<<"t = "<<t<<endl;
		if(count==0) move = mx;
		t = t - mx;
		count +=1;
	}
	if(count%2==1) {
		printf("1\n%d", move);
	} else {
		printf("2\n");
	}
	return 0;
}
