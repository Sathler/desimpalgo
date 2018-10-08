#include <iostream>

using namespace std;

const int TB = 1000;
typedef int bignum[TB+1];
bignum entrada;

void Convpnbn(int a, bignum B){
	if(a < 0){ B[0]=-1;  a=-a; }
	else B[0]=1;
	for(int i=TB; i>=1; i--){
		B[i]=a%10; a /= 10;
	}
}

void Somabn(bignum B1, bignum B2, bignum B3){//B3 = B1+B2
	int i,v1,k;
	v1=0;; B3[0]=1;
    for (i=TB; i>0; i--){
        k= B1[i]+B2[i]+v1;
        B3[i]= k % 10;
        v1= k / 10;
    }
}

void Multpnbn(int n, bignum B1, bignum B2){//B2 = n*B1
	int i,v1,k;
	v1=0;; B2[0]=1;
    for (i=TB; i>0; i--){
        k= B1[i]*n+v1;
        B2[i]= k % 10;
        v1= k / 10;
    }
}

void Imprimebn(bignum B){
	int i,k=1;
	if(B[0]==-1) cout<<"-";
	while( (k < TB) && (!B[k])) k++;
	for(i=k; i<=TB; i++) cout<<B[i];  cout<<endl;
}

int main(){
	int n, i;
	bignum aux1, aux2, soma, saida;
	while(cin >> n && n>= 0){
        if(n == 1){
            cout << 0 << endl;
        }
        else if(n == 2){
            cout << 1 << endl;
        }
        else{
            //Convpnbn(0, soma);
            //Convpnbn(0, saida);
            Convpnbn(0, aux1);
            Convpnbn(1, aux2);
            for(i=3;i<=n;i++){
                Somabn(aux1, aux2, soma);
                Multpnbn(i-1,soma,saida);
                Multpnbn(1, aux2, aux1);
                Multpnbn(1, saida, aux2);
            }
            Imprimebn(saida);
        }
	}
}
