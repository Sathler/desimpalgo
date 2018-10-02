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

bool Fermat(int n){
	int i = 0, k;
	while(i<10){
		k = rand()%(n-2) +1;
		i++;
		if(PotMod(k,n,n) != k){
			return false;
		}
	}
	return true;
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

int main(){
	int n;
	while(cin >> n){
		if(n == 0){
			break;
		}
		else{
			if(Fermat(n) && !(TestaPrimo(n))){
				cout << "The number " << n << " is a Carmichael number."<< endl;
			}
			else{
				cout << n << " is normal." << endl;
			}
		}
	}
	return 0;
}
