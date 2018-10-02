#include <iostream>

using namespace std;

int n, i, j, c, grey;
char r;

int main(){
	while(1){
		cin >> n;
		if(n < 1){
			break;
		}
		else{
			for(i=0;i<n;i++){
				c = 0;
				for(j=0;j<5;j++){
					cin >> grey;
					if(grey <= 127){
						c++;
						r = (char)(j+65);
					}
				}
				if(c == 1){
					cout << r << endl;
				}
				else{
					cout << '*' << endl;
				}
			}
		}
	}
}