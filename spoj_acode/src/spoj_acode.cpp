#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
inline int val(char c) {
	return c-'0';
}

map<string, ll> memo;

ll check(string str, int i) {
	if(i<0)return 0;

	string sub = str.substr(0, i);

	if(memo.find(sub) != memo.end()) {
		return memo[sub];
	}

	ll count=0;
	while(i>=0 && str[i]!='0') {
		int num = val(str[i])*10+val(str[i+1]);
		if(num > 0 && num<=26) {
			count += check(str, i-2)+1;
		}
		--i;
	}
	memo[sub] = count;
	return count;
}


int main() {
	string num;
	while(true) {
		cin>>num;
		if (num.compare("0") == 0) {
			break;
		}
		memo.clear();
		//cout<<count(num, 0, len-1)<<"\n";
		int ans=0;
		if(num.find('0') == string::npos) {
			ans+=1;
		}
		ans += check(num, num.length()-2);
		cout<<ans<<"\n";
	}
	return 0;
}
