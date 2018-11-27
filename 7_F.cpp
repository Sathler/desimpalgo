#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
	cout << fixed << setprecision(3);
	double p, m1, m2, m3, area;
	
	while(cin >> m1 >> m2 >> m3){
		p = (m1+m2+m3)/2;
		if(p <= m1 || p <= m2 || p <= m3){
			area = -1;
		}
		else{
			area = (4*sqrt(p*(p-m1)*(p-m2)*(p-m3)))/3;
		}
		cout << area << endl;
	}
	
}
