#include <iostream>
#include <math.h>
#include <stdlib.h>

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

bool TestaPrimo (int q)
{    int rq;   bool primo=true;
     rq = sqrt(q);
     for (int i=2; i<=rq; i++)
         if ((q % i) == 0)
         {   primo = false;
             break;
         }    
     return (primo);
}

bool Fermat(int n, int a){
	if(PotMod(a,n,n) != a){
		return false;
	}
	else{
		return true;
	}
	
}

int main(){
	int p, a;
	while(cin >> p >> a){
		if(p == 0 || a == 0){
			break;
		}
		else{
			if(TestaPrimo(p)){
				cout << "no" << endl;
			}
			else if(Fermat(p, a)){
				cout << "yes" << endl;
			}
			else{
				cout << "no" << endl;
			}
		}
	}
	return 0;
}
