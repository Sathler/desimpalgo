#include <iostream>
#include <iomanip>
#include <cmath>

#define PI acos(-1)

using namespace std;

typedef struct { double x, y; }ponto;
typedef struct { double a,b,c; }reta;
typedef struct {ponto pc; double raio; }circulo;
typedef struct { bool ret; ponto p; }boolponto;

const double QZERO = 0.000000001;

double DistPontos(ponto p1,ponto p2){
    return (sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)));
};

reta PontosParaReta(ponto p1,ponto p2){
    reta r;
    if (p1.x==p2.x){ r.a=1; r.b =0; r.c=-p1.x;}
    else{ r.b=1; r.a=-(p1.y-p2.y)/(p1.x-p2.x);
          r.c=-(r.a*p1.x)-(r.b*p1.y);
    }
    return r;
};

reta PontoTangenteParaReta(ponto p, double tang){
    reta r;
    r.a=-tang;  r.b=1;  r.c=-(r.a*p.x + r.b*p.y);
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

bool Paralelas(reta r1, reta r2){
    return ((fabs(r1.a-r2.a)<=QZERO) && (fabs(r1.b-r2.b)<=QZERO));
};

bool MesmaReta(reta r1,reta r2){
    return (Paralelas(r1,r2) && (abs(r1.c-r2.c)<=QZERO));
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
        if (fabs(bp.p.x) < QZERO) bp.p.x = 0;   // Para evitar -0.00
        if (fabs(bp.p.y) < QZERO) bp.p.y = 0;   // Para evitar -0.00   
    }
    return bp;
};

int main(){
	cout << fixed << setprecision(3);
	double h, k, r, cd, d, e;
	boolponto centro;
	circulo circ;
	ponto a, b, c, ab, bc;
	reta r_ab, r_bc, m_ab, m_bc;
	while(cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y){
		ab.x = (a.x+b.x)/2;
		ab.y = (a.y+b.y)/2;
		bc.x = (b.x+c.x)/2;
		bc.y = (b.y+c.y)/2;
		r_ab = PontosParaReta(a,b);
		r_bc = PontosParaReta(b,c);
		m_ab = RetaPerpendicular(ab, r_ab);
		m_bc = RetaPerpendicular(bc, r_bc);
		centro = PontoIntersecao(m_ab, m_bc);
		circ.pc = centro.p;
		circ.raio = DistPontos(centro.p, a);
		h = circ.pc.x;
		k = circ.pc.y;
		r = circ.raio;
		cd = 2*h;
		d = 2*k;
		e = pow(h,2) + pow(k, 2) - pow(r, 2);
		if(abs(h) < QZERO){
			h = 0;
		}
		if(abs(k) < QZERO){
			k = 0;
		}
		if(abs(cd) < QZERO){
			cd = 0;
		}
		if(abs(d) < QZERO){
			d = 0;
		}
		if(abs(e) < QZERO){
			e = 0;
		}
		if(h < 0){
			cout << "(x + " << abs(h) <<")^2";
		}
		else if(h == 0){
			cout << "x^2";
		}
		else if(h > 0){
			cout << "(x - " << abs(h) <<")^2";
		} 
		cout << " + ";
		if(k < 0){
			cout << "(y + " << abs(k) << ")^2";
		}
		else if(k > 0){
			cout << "(y - " << abs(k) << ")^2";
		}
		else{
			cout << "y^2";
		}
		cout << " = " << r << "^2" << endl;
		cout << "x^2 + y^2";
		if(cd > 0){
			cout << " - " << cd << "x";
		}
		else if(cd < 0){
			cout << " + " << abs(cd) << "x";
		}
		if(d > 0){
			cout << " - " << d << "y";
		}
		else if(d < 0){
			cout << " + " << abs(d) << "y";
		}
		if(e < 0){
			cout << " - " << abs(e);
		}
		else if(e > 0){
			cout << " + " << e;
		}
		cout << " = 0" << endl << endl;
		
		//cout << cd << d << e;
	}
}
