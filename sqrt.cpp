#include <iostream>
#include <vector>
using namespace std;

int sqrt(int num){
    int l = 0;
    int h = num;
    int ans;
    while(l <= h){
        int mid = l+(h-l)/2;
        if(mid*mid < num){
            ans = mid;
            l = mid+1;
        }
        else if(mid*mid > num){
            h = mid-1;
        }
        else return mid;
    }
    return ans;
}

double final_sqrt(int num,int pre){
    double final_ans = sqrt(num);
    double step = 0.1;
    for(int i = 0; i < pre; i++){
        for(double j = final_ans; j*j <= num; j += step){
                final_ans = j;
        }
        step /= 10;
    }
    return final_ans;   
}

int main()
{
    int num,pre;
    cout<<"Enter num: ";
    cin>>num;
    cout<<"Enter precesion: ";
    cin>>pre;

    cout<<"Final ans: "<<final_sqrt(num,pre)<<endl;

    return 0;
}