#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	long long n, a, b, c, maxi;
	cin >> n;
	for(int i=0; i<n;i++){
		cin >> a >> b >> c;
		maxi = max(max(a,b),c);
		if(maxi >= a+b+c-maxi){
			cout << "Case " << i+1 << ": Invalid" << endl;
		}
		else if(a == b && a == c){
			cout << "Case " << i+1 << ": Equilateral" << endl;
		}
		else if(a == b || a == c || b == c){
			cout << "Case " << i+1 << ": Isosceles" << endl;
		}
		else{
			cout << "Case " << i+1 << ": Scalene" << endl;
		}
	}
}
