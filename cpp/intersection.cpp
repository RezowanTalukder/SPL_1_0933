#include <bita/stdc++.h>

using namespace std;
 
#define CASES int t;cin>>t;while(t--)
#define REP(i, val, b) for (int i = val; i < b; ++i)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
 
int main() {
	fastio
	int n;
	cin >> n;
	list<long long> A;
	long long x;
	list<long long> L;
	REP(i,0,n) {
		cin >> x;
		A.push_back(x);
	}
	L.push_back(A.back());
	A.pop_back();
	while(L.size() != n) {
		// cout << L.size() << " ";
		for(list<long long>::iterator it = A.begin(); it!=A.end(); it++) {
			long long val = *it;
			if (val == L.back()*2) {
				L.push_back(val);
				A.erase(it);
				// cout << val << ' ';
				break;
			} else if(L.back()%3 == 0 && val == L.back()/3) {
				L.push_back(val);
				A.erase(it);
				// cout << val << ' ';
				break;
			} else if(L.front()%2 == 0 && val == L.front()/2) {
				L.push_front(val);
				A.erase(it);
				break;
			} else if(val == 3*L.front()) {
				L.push_front(val);
				A.erase(it);
				break;
			}
		}
	}
	for(list<long long>::iterator it = L.begin(); it!=L.end(); it++) {
		cout << *it << ' ';
	}
	return 0;
}