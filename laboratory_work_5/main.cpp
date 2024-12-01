#include <iostream>
using namespace std;
int main()
{   //1
    int n, proiz,i_max, max_elm;
    cin>>n;
    proiz = 1;
    i_max = -1;
    max_elm = -1;
    for(int i = 0;i<n;i++){
        int x;
        cin>>x;
        if (x%5!=0){
            proiz *= x;
            if(x>max_elm){
                max_elm = x;
                i_max = i;
            }
        }
    }
    cout<<proiz<<" "<<max_elm<<" "<<i_max;
    //2
    int num, proizv;
    cin>>num;
    proizv = 1;
    while(num>0){
        int x = num%10;
        if(x%2!=0){
            proizv *= x;
        }
        num=num/10;
    }
    cout<<proizv;
    return 0;
}