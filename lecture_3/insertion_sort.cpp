//insertion sort//
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#define mod 1000000000+7
#define ll long long int
#define ull unsigned long long int
#define pb push_back
#define mp make_pair 
#define pii pair <int, int>
using namespace std;
void swap(int* n, int* m);
int main(){
	int n;
    cin >> n;
    int arr[n]={0};
    for(int i=0;i<n;i++){ cin >> arr[i]; }

    for(int key=1;key<n;key++){
        
        for(int j=key;(arr[j-1]>arr[j])&&(j>0);j--){
        	swap(&arr[j-1], &arr[j]);
        }
  
    }
    for(int i=0;i<n;i++){ cout << arr[i] << endl; }    

}
void swap(int* n, int* m){
	int temp;
	temp = *m;
	*m = *n;
	*n = temp;
}
