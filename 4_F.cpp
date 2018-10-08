#include <iostream>

using namespace std;

long long mfat[21], mdes[21];

void fat(){
    long long k = 1;
    int i;
    mfat[0] = 1;
    for(i=1;i<=20;i++){
        k *= i;
        mfat[i] = k;
    }
}

void des(){
    long long i;
    mdes[0] = 1;
    mdes[1] = 0;
    mdes[2] = 1;
    for(i=3;i<=20;i++){
        mdes[i] = (i-1)*(mdes[i-1]+mdes[i-2]);
    }
}

long long comb(int n, int p){
    return (mfat[n]/mfat[p])/mfat[n-p];
}



int main(){
    int i, n, p;
    long long sum;
    des();
    fat();
    while(cin >> n >> p){
        sum = 0;
        for(i=0;i<=p;i++){
            sum += mdes[n-i]*comb(n,i);
        }
        cout << sum << endl;
    }
}
