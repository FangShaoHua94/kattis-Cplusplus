//#include <iostream>
//
//using namespace std;
//
//void merge_sort(int arr[],int from,int to);
//void merging(int arr[],int from,int to,int mid);
//void merge(int a[], int low, int mid, int high);
//
//int main()
//{
//    int arr[]={3,7,42,0,5,2,5};
//    int n =sizeof(arr)/sizeof(arr[0]);
//    merge_sort(arr,0,n-1);
//    for(int i=0;i<n;i++){
//        cout<<arr[i]<<" ";
//    }
//    return 0;
//}
//
//void merging(int arr[],int from,int to,int mid){
//    int i=from;
//    int j= mid+1;
//    int k=0;
//    int temp[to-from+1];
//    while(i<=mid&&j<=to){
//        if(arr[i]<arr[j]){
//            temp[k]=arr[i];
//            i++;
//        }else{
//            temp[k]=arr[j];
//            j++;
//        }
//        k++;
//    }
//    while(i<=mid){
//        temp[k]=arr[i];
//        i++;
//        k++;
//    }
//    while(j<=to){
//        temp[k]=arr[j];
//        j++;
//        k++;
//    }
//    for(i=from;i<=to;i++){
//        arr[i]=temp[i-from];
//    }
//}
//
//void merge_sort(int arr[],int from,int to){
//    int mid;
//    if(from<to){
//        mid=(from+to)/2;
//        merge_sort(arr,from,mid);
//        merge_sort(arr,mid+1,to);
//        merge(arr,from,to,mid);
//    }
//
//}
//
//
//
//void merge(int a[], int low, int mid, int high) {
//  // subarray1 = a[low..mid], subarray2 = a[mid+1..high], both sorted
//  int N = high-low+1;
//  int b[N]; // discuss: why do we need a temporary array b?
//  int left = low, right = mid+1, bIdx = 0;
//  while (left <= mid && right <= high) // the merging
//    b[bIdx++] = (a[left] <= a[right]) ? a[left++] : a[right++];
//  while (left <= mid) b[bIdx++] = a[left++]; // leftover, if any
//  while (right <= high) b[bIdx++] = a[right++]; // leftover, if any
//  for (int k = 0; k < N; k++) a[low+k] = b[k]; // copy back
//}

