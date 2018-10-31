#include <iostream>
#include <algorithm>

using namespace std;


int main(){
	int t, k, dif, m1, m2, maxm;
	cin >> t;
	for(int i=0; i<t;i++){
		cin >> k;
		cin >> m1 >> m2;
		dif = m1-m2;
		maxm = max(m1,m2);
		for(int j=2; j<k;j++){
			cin >> m1;
			if(maxm-m1 > dif){
				dif = maxm-m1;
			}
			if(maxm < m1){
				maxm = m1;
			}
		}
		cout << dif << endl;
	}
}
