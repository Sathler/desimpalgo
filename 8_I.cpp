#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

typedef struct {int x, y;}Ponto;


int main(){
	//FILE * arq;
	//arq = fopen("saida.txt", "w");
	bool pontox, areax, pontoy, areay;
	int intx, inty;
	Ponto r1a, r1b, r2a, r2b;
	while(cin >> r1a.x >> r1a.y >> r1b.x >> r1b.y >> r2a.x >> r2a.y >> r2b.x >> r2b.y){
		if(r1a.x > r1b.x){
			swap(r1a.x, r1b.x);
		}
		if(r1a.y > r1b.y){
			swap(r1a.x, r1b.x);
		}
		if(r2a.x > r2b.x){
			swap(r1a.x, r1b.x);
		}
		if(r2a.y > r2b.y){
			swap(r1a.x, r1b.x);
		}
		if(r1a.x < r2a.x){
			if(r2a.x < r1b.x){
				if(r2b.x > r1b.x){
					areax = true;
					pontox = false;
					intx = r1b.x-r2a.x;
				}
				else{
					areax = true;
					pontox = false;
					intx = r2b.x-r2a.x;
				}
			}
			else if(r2a.x == r1b.x){
				areax = false;
				pontox = true;
				intx = 0;
			}
			else{
				areax = false;
				pontox = false;
				intx = 0;
			}
		}
		else if(r1a.x > r2a.x){
			if(r1a.x < r2b.x){
				areax = true;
				pontox = false;
				intx = r1b.x-r2a.x;
			}
			else if(r1a.x == r2b.x){
				areax = false;
				pontox = true;
				intx = 0;
			}
			else{
				areax = false;
				pontox = false;
				intx = 0;
			}
		
		}
		else{
			areax = true;
			pontox = false;
			intx = min(r1b.x,r2b.x)-r1a.x;
		}
		if(r1a.y < r2a.y){
			if(r2a.y < r1b.y){
				if(r2b.y > r1b.y){
					areay = true;
					pontoy = false;
					inty = r1b.y-r2a.y;
				}
				else{
					areay = true;
					pontoy = false;
					inty = r2b.y-r2a.y;
				}
			}
			else if(r2a.y == r1b.y){
				areay = false;
				pontoy = true;
				inty = 0;
			}
			else{
				areay = false;
				pontoy = false;
				inty = 0;
			}
		}
		else if(r1a.y > r2a.y){
			if(r1a.y < r2b.y){
				areay = true;
				pontoy = false;
				inty = r1b.y-r2a.y;
			}
			else if(r1a.y == r2b.y){
				areay = false;
				pontoy = true;
				inty = 0;
			}
			else{
				areay = false;
				pontoy = false;
				inty = 0;
			}
		
		}
		else{
			areay = true;
			pontoy = false;
			inty = min(r1b.y,r2b.y)-r1a.y;
		}
		//cout << inty << " " << intx << endl;
		if(areay && areax){
			if(intx*inty > 10){
				//fprintf(arq, "grande\n");
				cout << "grande" << endl;
			}
			else{
				//fprintf(arq, "adequada\n");
				cout << "adequada" << endl;
			}
		}
		else if((areay && pontox) || (areax && pontoy)){
			//fprintf(arq, "linha\n");
			cout << "linha" << endl;
		}
		else if(pontox && pontoy){
			//fprintf(arq, "ponto\n");
			cout << "ponto" << endl;
		}
		else{
			//fprintf(arq, "inexistente\n");
			cout << "inexistente" << endl;
		}
	}
}
