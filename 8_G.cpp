#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
	cout << fixed << setprecision(4);
	int n, h, c, l;
	double hip, area;
	while(cin >> n >> h >> c >> l){
		hip = sqrt(h*h + c*c);
		area = (n*hip*l)/10000;
		cout << area << endl;
	}
}
