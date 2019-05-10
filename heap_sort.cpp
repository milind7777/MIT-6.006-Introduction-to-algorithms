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

vector<int> max_heapify(vector<int> arr, int i);
vector<int> build_max_heap(vector<int> arr);
vector<int> heap_sort(vector<int> arr);
int main(){
 	int n, x;
 	cin >> n;
    vector<int> arr;
    for(int i=0;i<n;i++){ cin >> x; arr.pb(x); }

    arr = heap_sort(arr);
   
    for(int i=0;i<n;i++){ cout << arr[i] << endl; }
}


vector<int> max_heapify(vector<int> arr, int i){
	int left_child  = 2*(i+1)-1;
	int right_child = 2*(i+1);
	int heap_size = arr.size();
    int largest = i;
    int temp;

    if((left_child<=heap_size-1)&&(arr[left_child]>arr[largest])){
        largest = left_child;
    }
    if((right_child<=heap_size-1)&&(arr[right_child]>arr[largest])){
        largest = right_child;
    }

    if(largest!=i){
    	temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        return max_heapify(arr, largest);
    }
    return arr;
}

vector<int> build_max_heap(vector<int> arr){
	int heap_size = arr.size();
	for(int i=(heap_size/2)-1;i>=0;i--){
        arr = max_heapify(arr, i);
	}
	return arr;
}

vector<int> heap_sort(vector<int> arr){
	vector<int> sorted_list;
	int temp;
	arr = build_max_heap(arr);
	int heap_size = arr.size();
	for(int i=heap_size-1;i>=0;i--){
        arr = max_heapify(arr, 0);
        sorted_list.pb(arr[0]);
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        arr.pop_back();
	}
	return sorted_list;
}