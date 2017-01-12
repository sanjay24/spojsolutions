#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
string add(string a, string b) {
	int i=a.length()-1;
	int j = b.length()-1;
	string ans;
	int carry = 0;
	while(i>=0 && j>=0) {
		int r = (a[i]-'0' + b[j]-'0' + carry)%10;
		carry  = (a[i]-'0' + b[j]-'0' + carry)/10;
		char str[] = {r+'0', '\0'};
		ans = string(str) + ans;
		--i;
		--j;
	}
	while(i>=0) {
		int r = (a[i]-'0' + carry)%10;
		carry = (a[i]-'0' + carry)/10;
		char str[] = {r+'0', '\0'};
		ans = string(str) + ans;
		--i;
	}
	while(j>=0) {
		carry = (b[j]-'0' + carry)/10;
		int r = (b[j]-'0' + carry)%10;
		char str[] = {r+'0', '\0'};
		ans = string(str) + ans;
		--j;
	}
	if(carry) {
		char str[] = {carry+'0', '\0'};
		ans = string(str) + ans;
	}
	return ans;
}

inline int intval(char c) {
	return c-'0';
}

void sub(string& a) {
	int i = a.length()-1;
	string ans;
	int c=0;
	if(a[i]<'2'){
		a[i] = '0' + 8 + intval(a[i]);
		c=1;
		i--;
	} else {
		a[i] = '0' + intval(a[i]) - 2;
	}
	while(c>0 && i>=0) {
		if(intval(a[i])<1) {
			c=1;
			a[i] = '9';
		} else {
			a[i] = '0' + intval(a[i]) - 1;
			c=0;
		}
		--i;
	}
}

string stripzero(string& ans) {
	string str;
	int i=0;
	while(ans[i] == '0') {
		++i;
	}
	str = ans.substr(i);
	return str;
}
int main() {
#if 0
	string n;

	for(int i=2; i<100000000; ++i) {
		int ans = 2*i-2;
		char str[256];
		itoa(ans, str, 10);
		char s1[256];
		itoa(i, s1, 10);
		string st1(s1);
		string ds = add(s1, s1);
		string t = ds;
		sub(t);
		string stans = stripzero(t);
		if(strcmp(str, stans.c_str())) {
			cout<<"mismatch found for i = "<<i<<endl;
			cout<<"from num = "<<ans<<endl;
			cout<<"from str = "<<stans<<endl;
			cout<<"double = "<<ds<<endl;
			cout<<"sub 2 = "<<t<<endl;
			return 0;
		}
	}
#endif
	string n;
	while(cin>>n) {
		if(n == "1") {
			cout<<"1\n";
		} else {
			string ans = add(n, n);
			sub(ans);
			cout<<stripzero(ans)<<"\n";
		}
	}
	return 0;
}
