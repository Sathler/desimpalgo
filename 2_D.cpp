#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int d[1000], nd = 0, b[101], n;

void Divisores(int q){
	int i, rq;
	nd = 0;
	rq = (int)(sqrt(q)+0.5);
	for(i=1;i<=rq;i++){
		if(q%i == 0){
			nd++; d[nd] = i;
			nd++; d[nd] = q/i;
		}
	}
	if(rq*rq == q){
		nd--;
	}
}

void quicksort(int e, int f,int *d){
	int i, j, t;
	if(f > e){
		i = e; j = f; t = d[(int)((e+f)/2)];
		while(i<=j){
			while(d[i] < t){
				i++;
			}
			while(d[j] > t){
				j--;
			}
			if(i <= j){
				swap(d[i], d[j]); i++; j--;
			}
		}
		quicksort(e, j, d);
		quicksort(i, f, d);
	}
}

int mmc(int a, int b){
	int r, c, d;
	c = a;
	d = b;
	do{
		r = c%d;
		c = d;
		d = r;
	}
	while(r != 0);
	return (a*b)/c;
}

bool match(int n){
    int i;
    for(i=1;i<=n;i++){
        if(n == b[i]){
            return false;
        }
    }
    return true;
}


int main(){
    int t, i, mm, r;
	while(1){
        cin >> n >> t;
        if(n == 0 && t == 0){
            break;
        }
        mm = 1;
        for(i=1;i<=n;i++){
            cin >> b[i];
            mm = mmc(mm, b[i]);
        }
        Divisores(t);
        quicksort(1, nd, d);
        quicksort(1, n, b);
        r = 0;
        for(i=2;i<=nd;i++){
            if(mmc(mm, d[i]) == t && match(d[i])){
                r = d[i];
                break;
            }
        }
        /*for(i=1;i<=nd;i++){
            cout << d[i] << " ";
        }*/
        if(r == 0){
            cout << "impossivel" << endl;
        }
        else{
            cout << r << endl;
        }

	}
}

