#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

typedef struct { double x, y; }ponto;
typedef struct {ponto pc; double raio; }circulo;

double DistPontos(ponto p1,ponto p2){
    return (sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)));
};

int main(){
	circulo circ1, circ2;
	while(cin >> circ1.raio >> circ1.pc.x >> circ1.pc.y >> circ2.raio >> circ2.pc.x >> circ2.pc.y){
		if(circ1.raio >= DistPontos(circ1.pc, circ2.pc) + circ2.raio){
			cout << "RICO" << endl;
		}
		else{
			cout << "MORTO" << endl;
		}
	}
}
