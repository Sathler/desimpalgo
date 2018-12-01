#include <iostream>

using namespace std;

int main(){
	long long fp, fh, v, a, f, i=1;
	while(cin >> fp >> fh){
		f = fp + fh;
		a = (5*fp + 6*fh)/2;
		v = a + 2 - f;
		
		cout << "Molecula #" << i << ".:.\nPossui " << v << " atomos e " << a << " ligacoes\n" << endl;
		i++;
	}
}
