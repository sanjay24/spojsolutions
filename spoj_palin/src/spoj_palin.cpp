#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
using namespace std;
#if 0
bool check(int t) {
	char str[256];
	itoa(t, str, 10);
	int len = strlen(str);
	//cout<<"str = "<<str<<endl;
	//cout<<"len = "<<len<<endl;

	int i=0;
	int j=len-1;
	bool ans = true;
	while(i<j) {
		if(str[i] != str[j]) {
			ans = false;
			break;
		}
		i++;
		--j;
	}
	//cout<<"ans = "<<ans<<endl;
	return ans;
}
#endif
inline int intval(char c) {
	return c-'0';
}
string getnext(string str) {
	int len = str.length();
	if(len%2) {
		int i = len/2-1;
		int j = len/2+1;
		bool incremented = false;
		bool decremented = false;
		while(i>=0) {
			if (intval(str[j]) < intval(str[i])){
				if (!decremented)
					incremented = true;
			} else if (intval(str[j]) > intval(str[i])) {
				decremented = true;
			}

			str[j] = str[i];

			i--;
			j++;
		}
		// increment the middle
		i = len/2;
		j = i+1;
		bool done =  incremented;
		if(!incremented && len>1) {
			str[i] = '0'+(intval(str[i]) + 1) % 10;
			if(str[i] != '0') done = true;
		}
		bool changed = false;
		if(!done) {
			i--;
			while(i>=0) {
				if(str[i]!='9') {
					str[i] = (int)str[i] + 1;
					str[j] = str[i];
					changed = true;
					break;
				} else {
					str[i] = '0';
					str[j] = '0';
				}
				--i; ++j;
			}

			if(!changed) {
				if(len > 1) {
					str[0] = '1';
					str.append("1");
				} else {
					if (intval(str[0]) < 9) {
						str[0] = (int)str[0] + 1;
					} else {
						str[0] = '1';
						str.append("1");
					}
				}
			}
		}

	} else { // even
		int i = len/2-1;
		int j = i+1;
		bool incremented = false;
		bool decremented = false;
		while(i>=0) {
			if(str[j] < str[i]) {
				if (!decremented)
					incremented = true;
			} else if(str[j] > str[i]) {
				decremented = true;
			}
			str[j] = str[i];
			i--;
			j++;
		}
		// increment the middle
		i = len/2-1;
		j = i+1;
		if(!incremented) {
			bool changed = false;
			while(i>=0) {
				if(str[i] != '9') {
					str[i] = (int)str[i] + 1;
					str[j] = str[i];
					changed = true;
					break;
				} else {
					str[i] = '0';
					str[j] = '0';
				}
				--i;
				++j;
			}
			if(!changed) {
				str[0] = '1';
				str.append("1");
			}
		}
	}
	return str;
}
int main() {
#if 0
	int t = 12;
	for(int i=1; i<10000000; ++i) {
		char st[256];
		itoa(i, st, 10);
		char ts[256];
		strcpy(ts, getnext(st).c_str());
		//cout<<"Next = >>>"<<ts<<"<<<<<<<"<<endl;
		t=i+1;
		//long t;
		//cin>>t;
		//for(int i=0;i<t;++i){
		cout<<"----------------------------------"<<endl;
		cout<<i<<endl;
		cout<<"----------------------------------"<<endl;
		for(;;++t){
			if(check(t)) {
				//cout<<">>>>"<<t<<"<< is palin."<<endl;
				char ns[256];
				itoa(t, ns, 10);
				cout<<"algo--- "<<ts<<endl;
				cout<<"brute---"<<ns<<endl;
				if(strcmp(ns, ts)) {
					cout<<"NO....................."<<strlen(ts)<<endl;
					exit(1);
				}
				break;
			}
			/*
			string str;
			cin>>str;
			cout<<getnext(str)<<"\n";
			*/
		}

		//if(i==1002) break;
	}
#endif
	long t;
	cin>>t;
	while(t--) {
		string s;
		cin>>s;
		cout<<getnext(s)<<"\n";
	}
	return 0;
}
