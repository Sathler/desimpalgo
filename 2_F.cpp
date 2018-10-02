#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int mmc(int a, int b){
	int r, c, d;
	c = a;
	d = b;
	do{
		r = c%d;
		c = d;
		d = r;
	}
	while(r != 0);
	return (a*b)/c;
}

int main(){
	int n, a, b, c, m;
	while(cin >> n){
		cin >> a >> b >> c;
		m = mmc(mmc(a, b), c);
		cout <<  -n+m << endl;
	}
}
