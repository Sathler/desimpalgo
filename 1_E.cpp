#include <iostream>
#include <string>

using namespace std;

int i, j;
string linha;

int main(){
    int n;
    cin >> n;
    int **minas = new int*[n];
    for(i=0;i<n;i++){
        minas[i] = new int[n];
    }
    int **campo = new int*[n];
    for(i=0;i<n;i++){
        campo[i] = new int[n];
    }
    for(i=0;i<n;i++){
        cin >> linha;
        for(j=0;j<n;j++){
            minas[i][j] = linha[j];
        }
    }
    for(i=0;i<n;i++){
        cin >> linha;
        for(j=0;j<n;j++){
                if(linha[j] == 88){
                    campo[i][j] = 48;
                }
                else{
                    campo[i][j] = 46;
                }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(minas[i][j] == 42){
                if(i == 0){

                }
                else if(i == n-1){

                }
                else
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout << (char)campo[i][j] << endl;
        }
    }
}
