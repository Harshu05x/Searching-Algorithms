#include <iostream>
#include <vector>
using namespace std;

int find_pivot(vector<int>& arr){
    int l = 0;
    int h = arr.size()-1;
    while(l <= h){
        int mid = l+(h-l)/2;
        if(l == h) return l;
        if(mid+1 < arr.size() && arr[mid] > arr[mid+1]) return mid;
        if(mid-1 >= 0 && arr[mid-1] > arr[mid]) return mid-1;
        if(arr[l] > arr[mid]) h = mid-1;
        else l = mid+1;
    }
    return -1;
}

int main()
{
    vector<int> arr{2,4,6,8,10};
    int ans = find_pivot(arr);
    cout<<"Pivot ele: "<<arr[ans]<<endl;
    return 0;
}