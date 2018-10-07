#include <iostream>
#include <math.h>

using namespace std;

int PotMod(int a, int b, int n){
    long long int m, c, d, rb[101];  int i, j;
    m= b;   i= 101;
    while (m > 0){
        rb[--i]= m % 2;   m= m /2;
    }
    c= 0; d= 1;
    for(j=i; j<= 100; j++){
        d= (d*d) % n;    c= 2*c;
        if (rb[j] == 1){
            d= (d*a) % n;   c++;
        }
        //cout << rb[j] << " " << c << " " << d <<endl;
    }
    return (int) d;
}

int main(){
	long long i, n, m, k;
	m = 1000000007;
	cin >> k;
	for(i=0;i<k;i++){
		cin >> n;
		cout << "Case #" << i+1 << ": " << ((n%m)*(PotMod(2, n-1, m)))%m << endl;
	}
}
