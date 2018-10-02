#include <iostream>

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
    }
    return (int) d;
}

int main(){
	int b, p, m;
	while(cin >> b >> p >> m){
		cout << PotMod(b, p, m) << endl;
	}
	return 0;
}
