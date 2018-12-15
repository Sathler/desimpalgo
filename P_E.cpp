#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	string entrada1, entrada2;
	int k1, k2, size, maxsize;
	while(getline(cin,entrada1), entrada1.compare("#") != 0){
		maxsize = 0;
		getline(cin,entrada2);
		for(int i=0; i<entrada1.size();i++){
			k1 = i; k2 = 0; size = 0;
			while(k1 < entrada1.size() && k2 <entrada2.size()){
				if(entrada1[k1] != entrada2[k2]){
					k2++;
				}
				else{
					size++;
					k1++;
					k2++;
				}
			}
			if(k1 < entrada1.size()){
				size += entrada1.size()-k1; 
			}
			else{
				size += entrada2.size()-k2;
			}
			maxsize = max(maxsize, size);
		}
		for(int i=0; i<entrada2.size();i++){
			k2 = i; k1 = 0; size = 0;
			while(k1 < entrada1.size() && k2 <entrada2.size()){
				if(entrada1[k1] != entrada2[k2]){
					k1++;
				}
				else{
					size++;
					k1++;
					k2++;
				}
			}
			if(k2 < entrada2.size()){
				size += entrada2.size()-k2; 
			}
			else{
				size += entrada1.size()-k1;
			}
			maxsize = max(maxsize, size);
		}
		cout << maxsize << endl;
	}

}
