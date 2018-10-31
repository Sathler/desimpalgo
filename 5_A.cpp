#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int T[10000000], S[10000000], O[10000000], n;

int SCM() {
    int j, k = 1;
	T[1] = S[1];   O[1] = 1; 	
	for( int i = 2; i <= n; i++ ) {
        if( S[i] > T[k] ) {
            T[++k] = S[i];    O[i] = k;
        } else {
			j = lower_bound( T+1, T + k, S[i] ) - T;           
            if( S[i] > T[j] )  j++;           
            T[j] = S[i];  O[i] = j;
        }
    }
    return k;
}

void ImprimeSCM( int i, int j, int m ) {
     if( j > 0 ) {
         if( ( O[i] == j ) && ( S[i] < m ) ) {
             ImprimeSCM( i-1, j-1, S[i] );
             cout << S[i] << endl;
         }
         else ImprimeSCM( i-1, j, m );
     }
}	

int main(){
	int k=1, size, e;
	while(cin >> e){
		S[k++] = e;
	}
	n = k-1;
	size = SCM();
	cout << size << endl << '-' << endl;
	ImprimeSCM( n, size, 2000000000 );
}
