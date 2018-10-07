#include <iostream>

using namespace std;

long long mem[1000000];

void func(){
	long long k = 1, i, m1=1, m2=2;
	for(i=5;i<=1000000; i++){
		k += m1*m2;
		if(i%2 == 0){
			m2++;
		}
		else{
			m1++;
		}
		mem[i] = k;
	}
	mem[4] = 1;
	mem[3] = 0;
}

int main(){
	int n;
	func();
	while(cin >> n){
		if(n < 3){
			break;
		}
		else{
			cout << mem[n] << endl;
		}
		
	}
}
