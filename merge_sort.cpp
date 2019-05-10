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
int arr[10000] = {0};
vector <int> merge(int start, int end);
int main(){
	int n;
	cin >> n;
    vector<int> sorted_list;
	for(int i=0;i<n;i++){ cin >> arr[i]; }
    
    sorted_list = merge(0, n-1);
 
    for(int i=0;i<n;i++){ cout << sorted_list[i] << endl; }
  

}

vector <int> merge(int start, int end){
	if(start == end){ 
		vector <int> out;
        out.pb(arr[start]);
        return out;               
	}
	vector <int> l,r,out;
	int middle = (start + end)/2;
	l = merge(start, middle);
	r = merge(middle +1, end);
	int index_1=0, index_2=0;

    for(int i=start;i<=end;i++){
    	if (((l[index_1]>r[index_2])||(index_1==(middle-start+1)))&&(index_2!=(end-middle)))  { 
    		out.pb(r[index_2]);
    		index_2++; 
    	}
    	else{
    		out.pb(l[index_1]);
    		index_1++;
    	}

    }
    //for(int i=start;i<=end;i++){ printf("%d__",out[i-start] ); }
    //	printf("\n");
    return out;
}

