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
    vector<int> arr{1,6,2,3,4,6,4,4,6,6,6,7};
    int key = 6;

    int first = first_occurrence(arr,key);
    int last = last_occurrence(arr,key);

    cout<<"Total Occurance: "<<last-first+1<<endl;

    return 0;
}