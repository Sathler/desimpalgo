#include <iostream>

using namespace std;

int main(){
	int *viz, i, k, c, n;
	while(cin >> c >> n){
		if(c == 0 || n == 0){
			break;
		}
		else{
			viz = new int[n];
			for(i=0;i<n;i++){
				cin >> k;
				if(i == 0){
					viz[i] = k%c;
				}
				else{
					viz[i] = (k+viz[i-1])%c;
				}
			}
		}
		for(i=0;i<n;i++){
			cout << viz[i] << " ";
		}
	}
	return 0;
}
