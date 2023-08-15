#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& arr, int key){
    int s = 0;
    int e = arr.size()-1;

    while(s <= e){
        int mid = s+(e-s)/2;
        if(arr[mid] == key) return mid;
        else if(arr[mid+1] == key && mid+1 < e) return mid+1;
        else if(arr[mid-1] == key && mid-1 >= s) return mid-1;
        else if(arr[mid] > key) e = mid - 2;
        else s = mid + 2;
    }
    return -1;
}
                   
int main()
{
    vector<int> arr{10,3,40,20,50,80,70};
    int key = 10;
    int ans = search(arr,key);
    if(ans != -1) cout<<"Key found at "<<ans<<endl;  
    else cout<<"Key not found "<<endl;  
    return 0;
}