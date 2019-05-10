// peak finding in a two dimensional plane //
// any one peak //
// comlexity n*log2m
#include <iostream>
using namespace std;
int arr[10][10]={0},n,m,index_1,index_2,peak;
int find_max(int col);
void find_peak(int arr,int m);
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=m;j++)
    	{
    		cin >> arr[i][j];
    	}
    }
    find_peak(arr,m);
    printf("%d->(%d,%d)\n",peak,index_1,index_2);
	return 0;
} 
int find_max(int col)
{
	int max=arr[1][col],local_index=1;
	for(int i=2;i<=n;i++)
	{ 
       if(arr[i][col]> max){ max=arr[i][col];local_index=i; }
	}
	return local_index;
}
void find_peak(int begin,int m)
{   
	int i=find_max(begin+m/2);
    if(m<2){ peak=arr[i][begin+m/2]; index_1=i;index_2=begin+m/2; }
    else if(arr[i][begin+m/2] < arr[i][begin+m/2-1]){ find_peak(begin,m/2); }
    else if(arr[i][begin+m/2] < arr[i][begin+m/2+1]){ find_peak(begin+m/2+1,m/2); }
    else { peak=arr[i][begin+m/2]; index_1=i;index_2=begin+m/2;}
    return;
}