#include <iostream>
#include <map>

using namespace std;
typedef long long ll;

int main() {
	ll n;
	cin>>n;
	if(n&(n-1))
		cout<<"NIE"<<endl;
	else
		cout<<"TAK";
	return 0;
}
