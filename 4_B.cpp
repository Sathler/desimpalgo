#include <iostream>
#include <string>

using namespace std;

int letras[26];
string entrada;

void zerar(){
	int i;
	for(i=0;i<26;i++){
		letras[i] = 0;
	}
}

int main(){
	long long i, j, n, r, p, l;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> entrada;
		zerar();
		r = 1;
		l = entrada.size();
		for(j=0;j<l;j++){
			p = ++letras[(int)entrada[j]-65];
			r = (r*(j+1))/p;
		}
		cout << "Data set " << (i+1) << ": " << r << endl;
	}
}
