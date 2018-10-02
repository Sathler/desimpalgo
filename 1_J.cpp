#include <iostream>
#include <math.h>

using namespace std;

int t, i, n;
unsigned long long s;

int main(){
    cin >> n;
    for(i=0;i<n;i++){
        cin >> s;
        cout << (s+1)*(s+1)-1 << endl;
    }
}
