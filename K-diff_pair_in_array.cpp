#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int find_pairs(vector<int>& arr,int k){
    sort(arr.begin(),arr.end());
    int i = 0, j = 1;
    set<pair<int,int>> ans;
    while(j < arr.size()){
        int diff = arr[j] - arr[i];
        if(diff == k){
            ans.insert({arr[i],arr[j]});
            i++; j++;
        }
        else if(diff > k){
            i++;
        }
        else j++;
        if(i == j) j++;
    }
    return ans.size();
}
                   
int main()
{
    vector<int> arr{1,1,1,1,1};
    cout<<"Unique pairs: "<<find_pairs(arr,0);
    return 0;
}