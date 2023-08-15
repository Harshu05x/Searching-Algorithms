#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// two pointer approach
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    vector<int> ans;
    int l = 0;
    int h = arr.size()-1;

    while((h-l) >= k){
        if((x-arr[l]) > (arr[h]-x)){
            l++;
        }
        else h--;
    }
    // for(int i = l; i <= h; i++){
    //     ans.push_back(arr[i]);
    // }
    // return ans;
    return vector<int>(arr.begin()+l,arr.begin()+h+1);
}                   
int main()
{
    vector<int> arr{1,2,3,4,5};
    int k = 4;
    int x = 3;
    vector<int> ans = findClosestElements(arr,k,x);
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}