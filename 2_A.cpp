#include <iostream>
#include <math.h>

using namespace std;

int c[10000], p[10000], np=0, k;

void GeraCrivo(int n){
	int i, t, d, rq;
	for(i=1;i<=n;i++){
		c[i] = i;
	}
	for(i=1;i<=(n/2);i++){
		c[2*i] = 2;
	}
	rq = (int)(sqrt(n));
	for(i=3;i<=rq;i++){
		if(c[i] == i){
			t = i*i; d = i+i;
			while(t <= n){
				if(c[t] == t){
					c[t] = i;
				}
				t += d;
			}
		}
	}
}

void GeraPrimos(int n){
	int i;
	GeraCrivo(n);
	for(i=2;i<=n;i++){
		if(c[i] == i){
			np++; p[np] = i;
		}
	}

}

int TestePrimo(int q){
	int primo = 1, i;
	for(i=1;i<=np;i++){
		if(q%p[i] == 0){
			if(q != p[i]){
				primo = 0;
				break;
			}
		}
	}
	return primo;
}

int main(){
	int i, n;
	cin >> n;
	GeraPrimos(10000);
	for(i=0;i<n;i++){
		cin >> k;
		if(TestePrimo(k)){
			cout << "Prime" << endl;
		}
		else{
			cout << "Not Prime" << endl;
		}
	}
}
