#include <iostream>
using namespace std;
int main()
{   //1
    int a,b,c;
    cin>>a>>b>>c;
    if((a%c==0)&(b%c==0)){
        cout<<(a+b)/c<<endl;
    }
    else if((a%c==0)&(b%c!=0)){
        cout<<(a/c)+b<<endl;
    }
    else{
        cout<<a-b-c<<endl;
    }
    //2
    int n;
    cin>>n;
    switch (n){
        case 0:
            cout << "zero" << endl;
            break;
        case 1:
            cout << "one" << endl;
            break;
        case 2:
            cout << "two" << endl;
            break;
        case 3:
            cout << "three" << endl;
            break;
        case 4:
            cout << "four" << endl;
            break;
        case 5:
            cout << "five" << endl;
            break;
        case 6:
            cout << "six" << endl;
            break;
        case 7:
            cout << "seven" << endl;
            break;
        case 8:
            cout << "eight" << endl;
            break;
        case 9:
            cout << "nine" << endl;
            break;
        default:
            cout << "input error" << endl;
            break;
    }
    //3
    int x;
    cin>>x;
    switch (x){
    case -1:
        cout<<"Negative number"<<endl;
        break;
    case 1:
        cout<<"Positive number"<<endl;
        break;
    default:
        cout << "input error" << endl;
        break;
    }
    return 0;
}