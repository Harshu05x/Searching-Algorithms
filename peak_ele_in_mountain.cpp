#include <iostream>
#include <vector>
using namespace std;


int peak_ele(vector<int>& arr){
    int l = 0;
    int h = arr.size()-1;

    while(l < h){
        int mid = l+(h-l)/2;
        if(arr[mid] < arr[mid+1]) l = mid+1;
        else h = mid;
    }
    return arr[l];
}
int main()
{
    vector<int> arr{5,6,7,88,9,2,3,4};
    cout<<"Peak ele: "<<peak_ele(arr)<<endl;  
    return 0;
}