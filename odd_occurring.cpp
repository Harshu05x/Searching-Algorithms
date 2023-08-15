#include <iostream>
#include <vector>
using namespace std;

int odd_ele(vector<int>& arr){
    int s = 0;
    int e = arr.size()-1;

    while(s <= e){
        int mid = s+(e-s)/2;
        if(s == e)
            return s;
        else if(mid%2 == 0){
            if(arr[mid] == arr[mid+1])
                s = mid+2;
            else
                e = mid;
        }
        else{
            if(arr[mid] == arr[mid-1])
                s = mid+1;
            else   
                e = mid-1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr{2,2,1};
    int ans = odd_ele(arr);
    cout<<"Odd occuring ele: "<<arr[ans];
    return 0;
}