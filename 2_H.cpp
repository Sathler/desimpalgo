#include <iostream>
#include <math.h>

using namespace std;

int n, l, c, maximus, r;

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
    int i, mmcx = 1, k;
    cin >> n >> l;
    for(i=0;i<n;i++){
        cin >> c;
        mmcx = mmc(mmcx, c);
    }
    maximus = mmcx;
    for(i=1;i<l/2;i++){
        k = mmc(mmcx, i);
        if(k > maximus && k < l){
            maximus = k;
            r = i;
        }
    }
    cout << r;
}
