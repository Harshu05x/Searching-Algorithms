#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int first_occurrence(vector<int>& arr,int key){
    int l = 0;
    int h = arr.size()-1;
    int ans = -1;
    sort(arr.begin(),arr.end());
    while(l <= h){
        int mid = l+(h-l)/2;
        if(arr[mid] == key){
            ans = mid;
            h = mid - 1;
        }
        else if(arr[mid] > key) h = mid-1;
        else l = mid+1;
    }
   return ans;
}
int last_occurrence(vector<int>& arr,int key){
    int l = 0;
    int h = arr.size()-1;
    int ans = -1;
    sort(arr.begin(),arr.end());
    while(l <= h){
        int mid = l+(h-l)/2;
        if(arr[mid] == key){
            ans = mid;
            l = mid + 1;
        }
        else if(arr[mid] > key) h = mid-1;
        else l = mid+1;
    }
   return ans;
}

int main()
{
    vector<int> arr{1,6,2,3,4,4,4,4,6,6,6,7};
    int key = 6;

    if(first_occurrence(arr,key) == -1) cout<<"Key not found"<<endl;
    else cout<<"First occurrence: "<<first_occurrence(arr,key)<<endl;
    
    auto ans1 = lower_bound(arr.begin(),arr.end(),key);
    cout<<"First occurrence: "<<ans1-arr.begin()<<endl;
    
    if(last_occurrence(arr,key) == -1) cout<<"Key not found"<<endl;
    else cout<<"Last occurrence: "<<last_occurrence(arr,key)<<endl;

    auto ans2 = upper_bound(arr.begin(),arr.end(),key);
    cout<<"Last occurrence: "<<ans2-arr.begin()-1<<endl;

    return 0;
}