#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

typedef struct ret { int d; int x; int y;};
typedef struct result {int x; int y;};
int a, b, soma; ret r;
result resultado;

int MDC(int a, int b)
{   if (b == 0) return a;
    else return MDC(b, a % b);
}
ret MDCE(int a, int b, ret ra)
{   int xx;
    if (b == 0)
    {   ra.d = a;  ra.x = 1;  ra.y = 0;
    }
    else
    {   ra = MDCE(b, a % b, ra);
        xx = ra.x;  ra.x = ra.y;  ra.y = xx - (a / b)*ra.y;
    }
    if(abs(ra.x) + abs(ra.y) < soma){
		resultado.x = ra.x;
		resultado.y = ra.y;
	}
	else if((abs(ra.x) + abs(ra.y) == soma) && ra.x < resultado.x){
		resultado.x = ra.x;
		resultado.y = ra.y;
	}
    return ra;          
}

int main(){
	while(cin >> a >> b){
		resultado.x = a;
		resultado.y = b;
		soma = a + b;
		r.d = MDC(a, b);
		r = MDCE(a, b, r);
		cout << resultado.x << " " << resultado.y << " " << r.d << endl;
		
	}
}
