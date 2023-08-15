#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void print(vector<int>& ans){
    for(int i = 0; i < ans.size(); i++)
        cout<<ans[i]<<" ";
}

vector<int> reverse(int x) {
    vector<int> ans;
    while(x > 0){
        ans.push_back(x%10);
        x = x /10; 
    }
    return ans;
}

int main()
{
    int x = 123;
    vector<int> ans = reverse(x);
    print(ans);
}