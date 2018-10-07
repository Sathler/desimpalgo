#include <iostream>

using namespace std;

long long comb(int n, int p){
	if(n ==p){
		return 1;
	}
	else{
		return (comb(n -1,p)*n)/(n-p);
	}
}

int main(){
	int n, p;
	while(cin>>n>>p){
		if(n==0 && p == 0){
			break;
		}
		else{
			cout << n << " things taken " << p << " at a time is " << comb(n,p) << " exactly." << endl;
		}	
	}
}
