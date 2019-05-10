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
int binary_search(int start, int l, int n);
int binary_search_2(int start, int end, int n);
int arr[10000]={0};
int main(){
	int n, insert;
    cin >> n;
    for(int i=0;i<n;i++){ cin >> arr[i]; }
    
    for(int key = 1;key<n;key++){
        insert = binary_search_2(0, key-1, arr[key]);
        for(int j=key;j>insert;j--){
        	swap(arr[j-1],arr[j]);
        }
        printf("%d\n",insert );
        for(int i=0;i<n;i++){ cout << arr[i] << " "; }
        	printf("\n");

    }
    
    for(int i=0;i<n;i++){ cout << arr[i] << endl; }

}

int binary_search(int start, int l, int n){
	//start is the first index in the array
	//l is the length of the segment to be consired
	//n is the number to be inserted
	if(l==1){
       if(arr[start]>n){ return start; }
       else { return start+1; }
	}
	
	if(l%2 == 1){
		if(arr[l/2]>n)  { return binary_search(start, l/2, n); }
		else          { return binary_search(start + l/2 +1, l/2, n); }
	}
    else{
    	if(arr[l/2]>n) { return binary_search(start, l/2, n);}
    	else        { return binary_search(start + l/2, l/2, n);}
    }
}

int binary_search_2(int start, int end, int n){
	//start is the first index in the array
	//end is the last index in the array
	//n is the number to be inserted
    if(start >= end){ 
    	if(arr[start]> n){return start;}
        return start + 1;
    }
    int middle = (start + end)/2;
    if(arr[middle]>n){ return binary_search_2(start, middle-1, n); }
    return binary_search_2(middle+1, end, n);
 

}
void swap(int* n, int* m){
	int temp;
	temp = *m;
	*m = *n;
	*n = temp;
}