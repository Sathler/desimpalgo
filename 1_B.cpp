#include <iostream>
#include <string>

using namespace std;

string dir, esq, comp;
int moedas[12], cond[12], i, j, n, k;

int main(){
    cin >> n;
    for(i=0;i<n;i++){
        for(j=0;j<12;j++){
            moedas[j] = 2;
            cond[j] = 0;
        }
        for(k=0;k<3;k++){
            cin >> esq >> dir >> comp;
            if(!(comp.compare("even"))){
                j=0;
                while(dir[j]){
                    moedas[((int)dir[j])-65] = 0;
                    j++;
                }
                j = 0;
                while(esq[j]){
                    moedas[((int)esq[j])-65] = 0;
                    j++;
                }
            }
            else if(!(comp.compare("up"))){
                j = 0;
                while(esq[j]){
                    cond[(int)esq[j] - 65] = 1;
                    if(moedas[((int)esq[j])-65] == 2){
                        moedas[((int)esq[j])-65] = 1;
                        j++;
                    }
                    else if(moedas[((int)esq[j])-65] == -1){
                        moedas[((int)esq[j])-65] = 0;
                        j++;
                    }
                    else{
                        j++;
                    }
                }
                j = 0;
                while(dir[j]){
                    cond[(int)dir[j] - 65] = 1;
                    if(moedas[((int)dir[j])-65] == 2){
                        moedas[((int)dir[j])-65] = -1;
                        j++;
                    }
                    else if(moedas[((int)dir[j])-65] == 1){
                        moedas[((int)dir[j])-65] = 0;
                        j++;
                    }
                    else{
                        j++;
                    }
                }
                for(j=0;j<12;j++){
                    if(moedas[j] == 2){
                        moedas[j] = 0;
                    }
                    if(cond[j] == 0){
                        moedas[j] = 0;
                    }else{
                        cond[j] = 0;
                    }
                }
            }
            else if(!(comp.compare("down"))){
                j = 0;
                while(esq[j]){
                    cond[(int)esq[j] - 65] = 1;
                    if(moedas[((int)esq[j])-65] == 2){
                        moedas[((int)esq[j])-65] = -1;
                        j++;
                    }
                    else if(moedas[((int)esq[j])-65] == 1){
                        moedas[((int)esq[j])-65] = 0;
                        j++;
                    }
                    else{
                        j++;
                    }
                }
                j = 0;
                while(dir[j]){
                    cond[(int)dir[j] - 65] = 1;
                    if(moedas[((int)dir[j])-65] == 2){
                        moedas[((int)dir[j])-65] = 1;
                        j++;
                    }
                    else if(moedas[((int)dir[j])-65] == -1){
                        moedas[((int)dir[j])-65] = 0;
                        j++;
                    }
                    else{
                        j++;
                    }
                }
                for(j=0;j<12;j++){
                    if(moedas[j] == 2){
                        moedas[j] = 0;
                    }
                    if(cond[j] == 0){
                        moedas[j] = 0;
                    }else{
                        cond[j] = 0;
                    }
                }
            }
        }
        for(j=0;j<12;j++){
            if(moedas[j] == 1){
                cout << (char)(j+65) << " is the counterfeit coin and it is heavy." << endl;
                break;
            }
            else if(moedas[j] == -1){
                cout << (char)(j+65) << " is the counterfeit coin and it is light."<< endl;
                break;
            }
        }
    }
}
