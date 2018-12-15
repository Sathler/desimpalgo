#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<algorithm>
using namespace std;
typedef struct {int x, y;}Ponto;
typedef struct {Ponto p, q;}Segmento;
Ponto pol[100000], ch[100000];

int SentidoPercurso(Ponto p1, Ponto p2, Ponto p3)
{  long long a, b, c, d;
   a= p2.x - p1.x;  b= p3.y - p1.y;  c=p3.x - p1.x;  d=p2.y - p1.y;
   a = a*b-c*d;
   if (a > 0) return 1;
   else if (a < 0) return -1;
   else return 0;
}
int Intercepta(Segmento s1, Segmento s2)
{  if ((max(s1.p.x,s1.q.x)>=min(s2.p.x,s2.q.x))&&
       (max(s2.p.x,s2.q.x)>=min(s1.p.x,s1.q.x))&&
       (max(s1.p.y,s1.q.y)>=min(s2.p.y,s2.q.y))&&
       (max(s2.p.y,s2.q.y)>=min(s1.p.y,s1.q.y))&&
       (SentidoPercurso(s1.p,s1.q,s2.p)*SentidoPercurso(s1.p,s1.q,s2.q)<=0)&&
       (SentidoPercurso(s2.p,s2.q,s1.p)*SentidoPercurso(s2.p,s2.q,s1.q)<=0))
       return 1;
    else return 0;     
}

int PontoNoSegmento(Ponto p0, Ponto p1, Ponto p2){
    return SentidoPercurso(p0, p1, p2) == 0 &&
           p0.x >= min(p1.x, p2.x) && p0.x <= max(p1.x, p2.x) &&
           p0.y >= min(p1.y, p2.y) && p0.y <= max(p1.y, p2.y);
}

int PontoInterior(Ponto *pol, int n, Ponto q){
	int i, maxx = pol[0].x, cont; Segmento s1, s2;
	pol[n] = pol[0];
	for (i=1; i<=n; i++){
		if (PontoNoSegmento(q, pol[i-1], pol[i]))
			return 1;
		if (pol[i].x > maxx) maxx = pol[i].x;
	}
	s2.p = q;  s2.q.x = maxx+1;  s2.q.y = q.y;
	cont=0;
	for (i=1; i<=n; i++){
		s1.p = pol[i-1];  s1.q = pol[i];  
		if ((pol[i].y > q.y && pol[i-1].y <= q.y || pol[i-1].y > q.y && pol[i].y <= q.y)
			 && (Intercepta(s1, s2)))
			cont++;
	}	
	return cont%2;
}

int main(){
	Ponto teste;
	int n;
	while(cin >> n, n > 0){
		for(int i =0; i<n; i++){
			cin>>pol[i].x>>pol[i].y;
		}
		cin>>teste.x>>teste.y;
		if(PontoInterior(pol, n, teste)){
			cout << "T" << endl;
		}
		else{
			cout << "F" << endl;
		}
	}
}
