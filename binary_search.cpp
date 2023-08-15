#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Recursive approach
int binary_search_01(vector<int>& arr, int l,int h, int key){
    int mid = (l+h)/2;
    sort(arr.begin(),arr.end());
    if(l <= h){   
        if(arr[mid] == key) return mid;
        else if(arr[mid] > key) return binary_search_01(arr,l,mid-1,key);
        else if(arr[mid] < key) return binary_search_01(arr,mid+1,h,key);
    }
    else return -1;
}

// Iterative approach
int binary_search_02(vector<int>& arr,int key){
    int l = 0;
    int h = arr.size()-1;
    int flag = 0;
    sort(arr.begin(),arr.end());
    while(l <= h){
        int mid = l+(h-l)/2;
        if(arr[mid] == key){
            flag = 1;
            return mid;
        }
        else if(arr[mid] > key) h = mid-1;
        else l = mid+1;
    }
    if(!flag) return -1;
}

int main()
{
    vector<int> arr{10,9,3,5,8,1,6,0,1,3};
    int key = 50;
    if(binary_search_02(arr,key) == -1) cout<<"Key not found"<<endl;
    else cout<<"Key found"<<endl;

    if(binary_search_01(arr,0,arr.size()-1,key) == -1) cout<<"Key not found"<<endl;
    else cout<<"Key found"<<endl;

    if(binary_search(arr.begin(),arr.end(),key)) cout<<"Key found"<<endl;
    else cout<<"Key not found"<<endl;
    
    return 0;
}