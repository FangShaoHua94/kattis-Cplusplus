#include <bits/stdc++.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
long long int  merge_sort(int arr[],int from,int to);
long long int merge(int a[], int low, int mid, int high);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    long long int count=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>x;
        arr[i]=x;
    }
    count=merge_sort(arr,0,n-1);
    cout<<count<<endl;
    return 0;
}

long long int  merge(int a[], int low, int high, int mid) {
  // subarray1 = a[low..mid], subarray2 = a[mid+1..high], both sorted
  long long int count=0;
  int N = high-low+1;
  int b[N]; // discuss: why do we need a temporary array b?
  int left = low, right = mid+1, bIdx = 0;
  while (left <= mid && right <= high){ // the merging
    if(a[left] <= a[right]){
        b[bIdx++]=a[left++];
    }else{
        count+=mid-left+1;
        b[bIdx++]=a[right++];
    }
    
//  b[bIdx++] = (a[left] <= a[right]) ? a[left++] : a[right++];
  }
  while (left <= mid){
        b[bIdx++] = a[left++]; // leftover, if any
  }
  while (right <= high){
        b[bIdx++] = a[right++]; // leftover, if any
  }
  for (int k = 0; k < N; k++){
        a[low+k] = b[k]; // copy back
  }
  return count;
}

long long int  merge_sort(int arr[],int from,int to){
    int mid;
    long long int count=0;
    if(from<to){
        mid=(from+to)/2;
        count+=merge_sort(arr,from,mid);
        count+=merge_sort(arr,mid+1,to);
        count+=merge(arr,from,to,mid);
    }
    return count;
}
