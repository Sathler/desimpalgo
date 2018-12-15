#include <iostream>
#include <string>

using namespace std;

string entrada, subs[10000];
int n, ns, array[10000], trys, index;

bool existe(string sub){
	for(int i=0; i<ns; i++){
		if(sub.compare(subs[i]) == 0){
			index = i;
			return true;
		}
	}
	return false;
}

string MaisRecorrente(){
	int max=0, indexmax=-1;
	for(int i=0; i<ns; i++){
		if(array[i] > max){
			max = array[i];
			indexmax = i;
		}
	}
	return subs[indexmax];
}

int main(){
	string sub;
	while(cin >> n >> entrada){
		ns = 0;
		trys = entrada.length() - n + 1;
		for(int i = 0; i<trys; i++){
			sub = entrada.substr(i,n);
			if(existe(sub)){
				array[index]++;
			}
			else{
				subs[ns] = sub;
				array[ns] = 1;
				ns++;
			}
		}
		cout << MaisRecorrente() <<  endl;
	}
}
