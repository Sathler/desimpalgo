#include <iostream>
#include <math.h>
#include <string>

using namespace std;

string entrada;

int main(){
	int i, q, d;
	while(cin >> entrada){
		if(entrada != "0"){
			q = 0;
			for(i=0;i<entrada.size();i++){
				d = (int)(entrada[i] - '0');
				q = ((q*10 + d)+17)%17;
			}
			if(q == 0){
				cout << "1" << endl;
			}
			else{
				cout << "0" << endl;
			}
		}
		else{
			break;
		}
	}
	return 0;
}
