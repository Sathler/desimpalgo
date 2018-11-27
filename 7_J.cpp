#include <iostream>
#include <cmath>

#define PI 3.1415

using namespace std;

double volume(double r){
	return (4*PI*r*r*r)/3;
}

int main(){
	double r, gas; 
	int result;
	cin >> r >> gas;
	result = gas/volume(r);
	cout << result  << endl;
}
