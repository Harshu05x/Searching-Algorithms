#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int>& arr,int s,int e,int target){
    while(s <= e){
        int mid = s+(e-s)/2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] > target) e = mid-1;
        else s = mid+1;
    }
    return -1;
}

int find_pivot(vector<int>& arr){
    int l = 0;
    int h = arr.size()-1;
    while(l <= h){
        int mid = l+(h-l)/2;
        if(l == h) return l;
        if(mid < h && arr[mid] > arr[mid+1]) return mid;
        if(mid-1 >= l && arr[mid-1] > arr[mid]) return mid-1;
        if(arr[l] > arr[mid]) h = mid-1;
        else l = mid+1;
    }
    return -1;
}

int search(vector<int>& arr,int target){
    int pivot = find_pivot(arr);
    int ans = 0;
    if(target >= arr[0] && target <= arr[pivot]){
        ans = binary_search(arr,0,pivot,target);
    }
    else{
        ans = binary_search(arr,pivot+1,arr.size()-1,target);
    }
    return ans;
}

int main()
{
    vector<int> arr{1};
    int target = 1;
    int ans = search(arr,target);
    if(ans != -1) cout<<"Target found at index: "<<ans;
    else cout<<"Target not found";
    return 0;
}