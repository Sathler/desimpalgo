		#include <iostream>
		#include <stdio.h>
		#include <string.h>
		#include <algorithm>

		using namespace std;

		int n, m, TM[10001][10001], A[10001], B[10001], C[10001];

		void SMC(){
			for( int i=1; i<=n; i++ ) TM[i][0]=0;
			for( int j=1; j<=m; j++ ) TM[0][j]=0;    
			for( int i=1; i<=n; i++ ) {
				for( int j=1; j<=m; j++ ) {
					if( A[i-1] == B[j-1] )
						TM[i][j] = TM[i-1][j-1]+1;
					else
						TM[i][j] = max(TM[i-1][j], TM[i][j-1]);
				}
			}
		}

		void GeraSMC(int i, int j, int k){
			if( k > 0 ) {
				if( A[i-1] == B[j-1] ) {
					 k--; i--; j--;
					 C[k] = A[i];
				}
				else if( TM[i-1][j] == k )
					i--;
				else
					j--;
				GeraSMC(i, j, k);
			}
		}

		int main(){
			int count = 1;
			while(cin >> n >> m, n != 0){
				for(int i=0; i<n; i++) cin >> A[i];
				for(int i=0; i<m; i++) cin >> B[i];
				SMC();
				GeraSMC(n, m, TM[n][m]);
				cout << "Twin Towers #" << count++ << endl;
				cout << "Number of Tiles : " << TM[n][m] << endl << endl;
			}
		}
