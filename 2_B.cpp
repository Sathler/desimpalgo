#include <iostream>
#include <string>
#include <math.h>

using namespace std;

long long c[100000000], p[100000000], nc = 0, np = 0;

void GeraCrivo(long long n){
	long long i, t, d, rq;
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

void GeraPrimos(long long n){
	long long i;
	double k = (double)n/2;
	GeraCrivo(n);
	for(i=2;i<n;i++){
		if(c[i] == i && (n%c[i] != 0)){
            if(i>=k){
                if((c[n-i] == i)){
                    np++; p[np] = i;
                }
            }
            else{
                np++; p[np] = i;
            }
		}
	}
}

int main(){
    long long n, i;
    while(cin >> n){
        GeraPrimos(n);
        cout << np+1;
    }
}
