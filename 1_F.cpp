#include <iostream>

using namespace std;

int n, i, maxi, j;
float w, h, maxl;

int main(){
    while(1){
        cin >> n;
        if(n < 1){
            break;
        }
        else{
            maxi = 0;
            maxl = 0;
            for(i=0;i<n;i++){
                cin >> w >> h;
                for(j=0;j<2;j++){
                    if(w >= h){
                        w = w/2;
                    }
                    else{
                        h = h/2;
                    }
                }
                if(min(w, h) > maxl){
                    maxl = min(w, h);
                    maxi = i+1;
                }
            }
            cout << maxi << endl;
        }
    }
}
