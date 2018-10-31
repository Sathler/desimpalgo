#include <iostream>
#include <algorithm>

using namespace std;

typedef struct doll{int x; int y;};

doll colection[1000000], pilhas[1000000];

void mergex(doll arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    doll L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i].x > R[j].x)
        {
            arr[k] = L[i];
            i++;
        }
        else if(L[i].x == R[j].x){
                if(L[i].y >= R[j].y){
                    arr[k] = L[i];
                    i++;
                }
                else{
                    arr[k] = R[j];
                    j++;
                }
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(doll arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        mergex(arr, l, m, r);
    }
}

/*void quicksort(int e, int d){

	int t, i, j;
	if(d>e){
	i = e; j = d; t = colection[(int)(e+d)/2].x;
	while(i <= j){
		while(colection[i].x > t){
			i++;
		}
		while(colection[j].x < t){
			j--;
		}
		if(i <= j){
			swap(colection[i], colection[j]); i++; j--;
		}
	}
	quicksort(e, j);
	quicksort(i, d);
	}
}*/

bool encaixa(doll a, doll b){
	if(a.x < b.x && a.y < b.y){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	int t, n, p;
	bool cond;
	cin >> t;
	for(int i=0; i<t; i++){
		cin >> n;
		for(int j=1;j<=n;j++){
			cin >> colection[j].x >> colection[j].y;
		}
		mergeSort(colection, 1, n);
		pilhas[1] = colection[1];
		p = 1;
		for(int i=2;i<=n;i++){
			cond = false;
			for(int l=1;l<=p;l++){
				if(encaixa(colection[i], pilhas[l])){
					cond = true;
					pilhas[l] = colection[i];
					break;
				}
			}
			if(!cond){
				pilhas[++p] = colection[i];
			}
		}
		cout << p << endl;

	}
}
