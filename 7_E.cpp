#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define PI acos(-1)

double cvtrad(double r){
	return (r*PI)/180;
}

int main(){
	double l;
	cout << fixed << setprecision(10);
	while(cin >> l){
		cout << sin(cvtrad(108))*l/sin(cvtrad(63)) << endl;
	}
}
