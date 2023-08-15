#include <iostream>
using namespace std;

int divide(int divisor,int dividend){
    int s = 0;
    int e = abs(dividend);
    int ans;

    while(s <= e){
        int mid = s+(e-s)/2;
        if(abs(mid*divisor) == abs(dividend)) {
            ans = mid;
            break;
        }
        else if(abs(mid*divisor) < abs(dividend)){
            ans = mid;
            s = mid+1;
        }
        else e = mid-1;
    }
    if((dividend < 0 && divisor < 0) || (dividend >= 0 && divisor >= 0))
        return ans;
    return ans*-1;
}

double final_ans(int divisor,int dividend,int precesion){
    double ans = divide(divisor,dividend);
    double step = 0.1;
    for(int i = 0; i < precesion; i++){
        for(double j = ans; j*divisor <= dividend; j += step){
            ans = j;
        }
        step /= 10;
    }
    return ans;
}
                   
int main()
{
    int divisor;
    int dividend;
    int precesion;
    cout<<"Enter dividend: ";
    cin>>dividend;
    cout<<"Enter divisor: ";
    cin>>divisor;
    cout<<"Enter precesion: ";
    cin>>precesion;
    double ans = final_ans(divisor,dividend,precesion);
    cout<<"Ans: "<<ans<<endl; 
    return 0;
}