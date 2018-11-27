#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stdio.h>

using namespace std;

const double QZERO = 0.000000001;

typedef struct { double x, y; }ponto;
typedef struct { double a,b,c; }reta;
typedef struct { bool ret; ponto p; }boolponto;

bool Paralelas(reta r1, reta r2){
    return ((fabs(r1.a-r2.a)<=QZERO) && (fabs(r1.b-r2.b)<=QZERO));
};

bool MesmaReta(reta r1,reta r2){
    return (Paralelas(r1,r2) && (abs(r1.c-r2.c)<=QZERO));
};

reta PontoTangenteParaReta(ponto p, double tang){
    reta r;
    r.a=-tang;  r.b=1;  r.c=-(r.a*p.x + r.b*p.y);
    return r;
};

boolponto PontoIntersecao(reta r1,reta r2){
    boolponto bp;
    bp.ret = true;
    if (Paralelas(r1,r2) || MesmaReta(r1,r2)) bp.ret = false;
    else{
        bp.p.x = (r2.b*r1.c-r1.b*r2.c)/(r2.a*r1.b-r1.a*r2.b);
        if (fabs(r1.b)>QZERO)
            bp.p.y = -(r1.a*bp.p.x + r1.c)/r1.b;
        else
            bp.p.y = -(r2.a*bp.p.x + r2.c)/r2.b;
    }
    return bp;
};

reta PontosParaReta(ponto p1,ponto p2){
    reta r;
    if (p1.x==p2.x){ r.a=1; r.b =0; r.c=-p1.x;}
    else{ r.b=1; r.a=-(p1.y-p2.y)/(p1.x-p2.x);
          r.c=-(r.a*p1.x)-(r.b*p1.y);
    }
    return r;
};

reta RetaPerpendicular(ponto p1, reta r1){
    ponto p2; reta r2;
    if (fabs(r1.b)<= QZERO){
        r2.a = 0;  r2.b = 1;  r2.c = -p1.y;
    }
    else if (fabs(r1.a)<= QZERO){
        r2.a = 1;  r2.b = 0;  r2.c = -p1.x;
    }
    else r2 = PontoTangenteParaReta(p1,1/r1.a);
    return r2;
};

int main(){
	cout << fixed << setprecision(2);
	int t;
	ponto star1bef, star1aft, star2bef, star2aft, inter1, inter2;
	reta retaint1, retaint2, reta1, reta2;
	boolponto darkhole;
	cin >> t;
	for(int i=0; i<t; i++){
		cin >> star1bef.x >> star1bef.y;
		cin >> star2bef.x >> star2bef.y;
		cin >> star1aft.x >> star1aft.y;
		cin >> star2aft.x >> star2aft.y;
		inter1.x = (star1bef.x+star1aft.x)/2;
		inter1.y = (star1bef.y+star1aft.y)/2;
		inter2.x = (star2bef.x+star2aft.x)/2;
		inter2.y = (star2bef.y+star2aft.y)/2;
		retaint1 = PontosParaReta(star1bef, star1aft);
		retaint2 = PontosParaReta(star2bef, star2aft);
		reta1 = RetaPerpendicular(inter1, retaint1);
		reta2 = RetaPerpendicular(inter2, retaint2);
		darkhole = PontoIntersecao(reta1, reta2);
		if(fabs(darkhole.p.x) < QZERO){
			darkhole.p.x = 0;
		}
		if(fabs(darkhole.p.y) < QZERO){
			darkhole.p.y = 0;
		}
		cout << "Caso #" << i+1 << ": " << darkhole.p.x << " " << darkhole.p.y << endl;
	}
}
