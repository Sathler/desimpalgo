#include <iostream>
#include <algorithm>

using namespace std;

int gols[3];

void zerar(){
	gols[0] = 0; gols[1] = 0; gols[2] = 0;
}

int main(){
	int t, g, maxg, champ;
	char atk, def;
	bool cond, emp;
	cin >> t;
	for(int i=0;i<t;i++){
		zerar();
		cin >> g;
		for(int j=0;j<g;j++){
			cin >> atk >> def;
			if(atk == 'G'){
				if(def == 'R'){
					gols[0]++;
				}
				else if(def == 'B'){
					gols[0] += 2;
				}
			}
			else if(atk == 'B'){
				if(def == 'G'){
					gols[1]++;
				}
				else if(def == 'R'){
					gols[1] += 2;
				}
			}
			else if(atk == 'R'){
				if(def == 'B'){
					gols[2]++;
				}
				else if(def == 'G'){
					gols[2] += 2;
				}
			}
		}
		if(gols[0] == gols[1] && gols[1] == gols[2]){
			cout << "trempate" << endl;
		}
		else{
			maxg =0;
			cond = true;
			emp = false;
			for(int j=0; j<3; j++){
				maxg = max(maxg,gols[j]);
			}
			for(int j=0; j<3; j++){
				if(gols[j] == maxg && cond){
					champ = j;
					cond = false;
				}
				else if(gols[j] == maxg && !cond){
					cout << "empate" << endl;
					emp = true;
				}
			}
			if(!emp){
				switch(champ){
					case 0:
						cout << "green" << endl;
						break;
					case 1:
						cout << "blue" << endl;
						break;
					case 2:
						cout << "red" << endl;
						break;
				}
			}
		}
	}

	
}
