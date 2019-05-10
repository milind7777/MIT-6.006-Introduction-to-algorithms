// one dimensional peak finding //
// find a peak in the given aray //
// a[n]->peak if a[n]>=a[n-1]and a[n]>=a[n+1]
// complexity log2n
#include <iostream>
using namespace std;
int arr[12]={0},index,peak;
void find_peak(int begin,int n);
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    { cin >> arr[i]; } 
    
    find_peak(1,n);
    
    printf("%d_%d",peak,index);
	
}
void find_peak(int begin,int n)
{   
	if(n<2)
		{ peak=arr[begin+n/2]; index=begin+n/2;}
	else if(arr[begin+n/2]<arr[begin+n/2-1])
		{ find_peak(begin,n/2); }
	else if(arr[begin+n/2]<arr[begin+n/2+1])
		{ find_peak(begin +n/2+1,n/2); }
	else 
		{ peak=arr[begin+n/2]; index=begin+n/2;}
	
	return;
}