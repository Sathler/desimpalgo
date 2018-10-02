#include <iostream>

using namespace std;

long long n, comp[3], alt[3], area[3], i, j, cp, h;



int main(){
	cin >> n;
	area[0] = 0; area[1] = 0; area[2] = 0;
	alt[0] = 0; alt[1] = 0; alt[2] = 0;
	comp[0] = 0; comp[1] = 0; comp[2] = 0;
	for(i=0;i<n;i++){
		cin >> cp;
		comp[i%3] += cp;
	}
	for(i=0;i<n;i++){
		cin >> h;
		alt[i%3] += h;
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			area[(i*n+j)%3] += comp[j]*alt[i];
		}
	}
	cout << area[1] << " " << area[2] << " " << area[0];
}