#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

typedef struct { double x, y; }ponto;

double DistPontos(ponto p1,ponto p2){
    return (sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)));
};

int main(){
	int l, c, r1, r2;
	ponto circ1, circ2;
	
	while(true){
		cin >> l >> c >> r1 >> r2;
		if(l == 0 && c == 0 && r1 == 0 && r2 == 0){
			break;
		}
		circ1.x = r1; circ1.y = r1;
		circ2.x = c-r2; circ2.y = l-r2;
		if(DistPontos(circ1, circ2) >= r1+r2 && min(l,c) >= 2*max(r1,r2)){
			cout << "S" << endl;
		}
		else{
			cout << "N" << endl;
		}
	}
}
