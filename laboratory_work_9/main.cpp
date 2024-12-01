#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
    long long a; 
    cin >> a;
    unsigned char* p = (unsigned char*) &a;
    for (int i=0; i < sizeof(a); i++) {
        long long b = *(p + i);
        cout << setfill('0')<< setw(2)<< hex<<b << " ";
    }
    return 0;
}
