#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

typedef struct { double x, y; }ponto;

double DistPontos(ponto p1,ponto p2){
    return (sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)));
};

int main(){
	cout << fixed << setprecision(1);
	ponto casa, escola, canto_sup_esq, canto_sup_dir, canto_inf_dir, canto_inf_esq;
	int v;
	while(cin >> casa.x >> casa.y >> escola.x >> escola.y >> v >> canto_inf_esq.x >> canto_inf_esq.y >> canto_sup_dir.x >> canto_sup_dir.y){
		canto_sup_esq.x = canto_inf_esq.x;
		canto_sup_esq.y = canto_sup_dir.y;
		canto_inf_dir.x = canto_sup_dir.x;
		canto_inf_dir.y = canto_inf_esq.y;
		cout << (min(DistPontos(casa, canto_sup_esq)+DistPontos(canto_sup_esq, canto_sup_dir)+DistPontos(canto_sup_dir, escola),DistPontos(casa, canto_inf_esq)+DistPontos(canto_inf_esq, canto_inf_dir)+DistPontos(canto_inf_dir, escola)))/v << endl;
	}
}
