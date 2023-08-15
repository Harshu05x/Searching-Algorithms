#include <iostream>
using namespace std;

void binary_search(int arr[][4],int rows,int cols,int key){
    int s = 0;
    int e = rows*cols-1;
    int flag = 0;

    while(s <= e){
        int mid = s+(e-s)/2;
        int i = mid/cols;
        int j = mid%cols;
        if(arr[i][j] == key){
            cout<<"Key found at ( "<<i<<","<<j<<" )"<<endl;
            flag = 1;
            break;
        }
        else if(arr[i][j] < key){
            s = mid+1;
        }
        else e = mid-1;
    }
    if(!flag) cout<<"Key not found"<<endl;
}
                   
int main()
{
    int arr[5][4] = {{1,2,3,4},
                    {5,6,7,8,},
                    {9,10,11,12},
                    {13,14,15,16},
                    {17,18,19,20}};
    int key = 19;
    binary_search(arr,5,4,key);

    return 0;
}