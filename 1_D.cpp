#include <iostream>
#include <algorithm>

using namespace std;

int m, w, i,j, n, cont, sum;

void DesceHeap(int * vet, int m, int i){
    int e, d, maior;
    e = 2*i;
    d = 2*i + 1;
    if(e <= m && vet[e] > vet[i]){
        maior = e;
    }
    else{
        maior = i;
    }
    if(d <= m && vet[d] > vet[maior]){
        maior = d;
    }
    if(maior != i){
        swap(vet[i],vet[maior]);
        DesceHeap(vet, m, maior);
    }

}

int main(){
    cin >> n;
    for(i=0;i<n;i++){
        cont = 0;
        sum = 0;
        cin >> m >> w;
        int * elep = new int[m+1];
        for (j=1;j<=m;j++){
            cin >> elep[j];
        }
        for(j=((int)m/2);j>=1;j--){
            DesceHeap(elep, m, j);
        }
        for(j=m;j>=2;j--){
            swap(elep[1],elep[j]);
            DesceHeap(elep, j-1, 1);
        }
        for(j=1;j<=m;j++){
            sum += elep[j];
            if(sum > w){
                break;
            }
            else{
                cont++;
            }
        }
        cout << cont << endl;
        delete elep;
    }

}
