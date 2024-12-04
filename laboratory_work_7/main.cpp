#include "inc/func.hpp"
int main()
{  
    int n;
    int mas[100][100];
    pa::Read(mas, n);
    pa::Write(mas, n);
    if(pa::differenceMaxMinLess2(mas, n)){
        pa::SortColumnsBySum(mas, n);
    }
    pa::Write(mas, n);
    return 0;

}