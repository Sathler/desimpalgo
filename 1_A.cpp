#include <iostream>
#include <math.h>

using namespace std;

long n, r;

int main(){
    while(cin >> n){
        if(n > 1){
            r = 3*(2*((long)pow((double)(((int)(n/2)+1)),2.0))-3);
            cout << r << endl;
        }
        else{
            cout << 1;
        }
    }
return 0;
}

