#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<algorithm>
#include <iomanip>

using namespace std;

typedef struct {int x, y;}Ponto;
typedef struct {Ponto p, q;}Segmento;

Ponto pol[100000], ch[100000];

double DistPontos(Ponto p1,Ponto p2){
    return (sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)));
};

int SentidoPercurso(Ponto p1, Ponto p2, Ponto p3)
{  long long a, b, c, d;
   a= p2.x - p1.x;  b= p3.y - p1.y;  c=p3.x - p1.x;  d=p2.y - p1.y;
   a = a*b-c*d;
   if (a > 0) return 1;
   else if (a < 0) return -1;
   else return 0;
}

void Quicksort(Ponto *pol, int e, int d)
{  int i,j,k;  Ponto t,r;  long long d0, d1, d2;
   if (d > e)
   {  i=e;  j=d;  t=pol[(e+d)/2];
      d1= pol[0].x-t.x;  d2= pol[0].y-t.y;  d0=d1*d1+d2*d2;
      while(i<=j)
      {  while(1)
         {  k=SentidoPercurso(pol[0],pol[i],t);
            if (k==1) i++;
            else if (k==0)
            {  d1= pol[0].x-pol[i].x;  d2= pol[0].y-pol[i].y;  d1= d1*d1+d2*d2;
               if (d1 < d0) i++;
               else break;
            }   
            else break;
         }
         while(1)
         {  k=SentidoPercurso(pol[0],t,pol[j]);
            if (k==1) j--;
            else if (k==0)
            {  d1= pol[0].x-pol[j].x;  d2= pol[0].y-pol[j].y;  d1= d1*d1+d2*d2;
               if (d0 < d1) j--;
               else break;
            }
            else break;
         }  
         if (i<=j) {r=pol[i];  pol[i]=pol[j];  pol[j]=r;  i++; j--;}
      }
      Quicksort(pol, e,j);  Quicksort(pol, i,d);
   }
}  

void OrdenaPontosy(Ponto *pol, int tp)
{  int i,m;  Ponto p;
   m=0;
   for (i=1;i<tp;i++) 
      if ((pol[i].y < pol[m].y)||(pol[i].y==pol[m].y)&&(pol[i].x<pol[m].x)) m=i;
   p=pol[0];  pol[0]=pol[m];  pol[m]=p;
   Quicksort(pol, 1,tp-1);
}    

int ConvexHull(Ponto *pol, int tp, Ponto *ch, int &tc)
{   int i,j,topo;
    OrdenaPontosy(pol, tp);
    ch[0]= pol[0]; pol[tp]= pol[0];
    j= 1;
    while (SentidoPercurso(ch[0],pol[j],pol[j+1])==0) j++;
    ch[1]= pol[j];  ch[2]= pol[j+1];
    topo= 2;
    for (i= j+2; i<= tp; i++)
    {   while (SentidoPercurso(ch[topo-1], ch[topo], pol[i]) <= 0) topo--;
        topo++;  ch[topo]= pol[i];
    }
    tc = topo;
    return (topo);
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

int PontoInterior(Ponto *pol, int n, Ponto q){
	int i, maxx = pol[0].x, cont; Segmento s1, s2;
	pol[n] = pol[0];
	for (i=1; i<=n; i++){
		s1.p = pol[i-1];  s1.q = pol[i];  s2.p=s2.q=q;
		if (Intercepta(s1, s2))
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

bool comparax(Ponto p1, Ponto p2){
    if (p1.x == p2.x)
    	return p1.y < p2.y;
    return p1.x < p2.x;
}

void OrdenaPontosPorx(Ponto *pol, int np){
	sort(pol, pol+np, comparax);
}


int main(){
	Ponto aluno;
	int nr;
	for(int i=0; i<4 ;i++){
		cin >> pol[i].x >> pol[i].y;
	}
	
	cin >> aluno.x >> aluno.y;
	OrdenaPontosPorx(pol, 4);
	
	if(SentidoPercurso(pol[0], pol[1], pol[2]) == 0 &&  SentidoPercurso(pol[1], pol[2], pol[3]) == 0){
		cout << " O>\n<| \n/ >" << endl;
		return 0;
	}
	
	nr = ConvexHull(pol, 4, ch, nr);
	if(PontoInterior(ch, nr, aluno) == 1){
		cout << "\\O/\n | \n/ \\" << endl;
	}
	else{
		cout << " O>\n<| \n/ >" << endl;
	}
}

