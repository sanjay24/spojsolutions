#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> getDigits(int n) {
	vector<int> d;
	while(n>0) {
		int r = n%10;
		n = n/10;
		d.push_back(r);
	}
	return d;
}

long long sum(long long n) {
	//cout<<"checkinng "<<n<<endl;
	vector<int> digits = getDigits(n);
	long long sum = 0;
	for(int i=0; i<digits.size(); ++i) {
		sum +=  digits[i]*digits[i];
	}
	return sum;
}

int main() {
	long long n;
	scanf("%I64d", &n);
	int count = 1;
	bool found = false;
	map<long long, bool> mp;
	while(true) {
		long long s = sum(n);
		if(mp[s]) {
			break;
		}
		mp[s] = true;
		if(s==1){
			found = true;
			break;
		}
		n = s;
		count++;
	}
	if(!found) {
		printf("-1");
	}else{
		printf("%d", count);
	}
	return 0;
}
