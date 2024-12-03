#include <iostream>
#include <climits>
#include<string>
using namespace std;
//1
// bool AreAllDigitsSame(int num){
//     string str = to_string(num);
//     char firts_digit = str[0];
//     for(int i=1;i<str.length();i++){
//         if(str[i]!=firts_digit){
//             return false;
//         }
//     }
//     return true;
// }


//2
// int SumOfDigits(int num){
//     int sum = 0;
//     while(num > 0){
//         sum += num % 10;
//         num /= 10;
//     }
//     return sum;
// }
// int SmallestDigit(int num){
//     int smallest = 9;
//     while(num>0){
//         int digit = num % 10;
//         if(digit < smallest){
//             smallest = digit;
//         }
//     }
//     return smallest;
// }


//4
bool SumOfDigitsMultiple7(int num){
    int sum = 0;
    while(num > 0){
        sum += num % 10;
        num /= 10;
    }
    return sum % 7 == 0;
}
bool duplicate(int num) {
    string str = to_string(num);
    for(int i = 0; i < str.length(); i++) {
        for(int j = i + 1; j < str.length(); j++) {
            if(str[i] == str[j]) {
                return true;
            }
        }
    }
    return false;
}
int main()
{   //1
    // int n, count = 0;
    // cin >> n;
    // int* A = new int[n];
    // for(int i = 0; i < n; i++){
    //     cin >> A[i];
    //     if(AreAllDigitsSame(A[i])){
    //         count++;
    //     }
    // }
    // if(count >= 3){
    //     for(int i = 0; i < n-1; i++) {
    //         for(int j = 0; j < n-i-1; j++) {
    //             if(A[j] < A[j+1]) {
    //                 int temp = A[j];
    //                 A[j] = A[j+1];
    //                 A[j+1] = temp;
    //             }
    //         }
    //     }
    // }
    // for(int i = 0; i < n; i++){
    //     cout << A[i] << " ";
    // }
    // delete[] A;
    // return 0;


    //2
    // int n;
    // cin>>n;
    // int* A = new int[n];
    // for(int i = 0; i < n; i++){
    //     cin >> A[i];
    // }
    // for(int i = 0; i<n-1;i++){
    //     for(int j = 0; j<n-i-1;j++){
    //         int sum1 = SumOfDigits(A[j]);
    //         int sum2 = SumOfDigits(A[j+1]);
    //         int smallest1 = SmallestDigit(A[j]);
    //         int smallest2 = SmallestDigit(A[j+1]);
    //         if(sum1 > sum2){
    //             int temp = A[j];
    //             A[j] = A[j+1];
    //             A[j+1] = temp;
    //         }
    //         else if(sum1 == sum2){
    //             if(smallest1 > smallest2){
    //                 int temp = A[j];
    //                 A[j] = A[j+1];
    //                 A[j+1] = temp;
    //             }
    //         }
    //         else if(sum1 == sum2 && smallest1 == smallest2){
    //             if(A[j] > A[j+1]){
    //                 int temp = A[j];
    //                 A[j] = A[j+1];
    //                 A[j+1] = temp;
    //             }
    //         }
    //     }
    // }
    // for(int i = 0; i < n; i++){
    //     cout << A[i] << " ";
    // }
    // delete[] A;
    // return 0;


    //3
    // int n,m;
    // cin>>n>>m;
    // int** A = new int* [n];
    // for (int i = 0; i < n; i++) {
    //     A[i] = new int[m];
    // }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cin >> A[i][j];
    //     }
    // }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout<< A[i][j]<<" ";
    //     }
    //     cout << endl;
    // }
    // int max_proizv = INT_MIN;
    // int max_j = -1;

    // for (int j = 0; j < m; j++) {
    //     int proizved = 1;
    //     for (int i = 0; i < n; i++) proizved *= A[i][j];
    //     if (proizved > max_proizv) {
    //         max_proizv = proizved;
    //         max_j = j;
    //     }
    // }
    // for (int i = 0; i < n; i++) {
    //     A[i][max_j] -= 3;
    // }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout<< A[i][j]<<" ";
    //     }
    //     cout << endl;
    // }
    // for (int i = 0; i < n; i++) {
    //     delete[] A[i];
    // }
    // delete[] A;
    // return 0;


    //4
    int n;
    cin >> n;
    int* A = new int[n];
    for (int i = 0; i < n;i++) cin >> A[i];
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    cout << endl;
    for(int i=0;i<n;i++)
    {
        if(SumOfDigitsMultiple7(A[i]))
        {
            for(int j = i; j<n-1;j++)
                A[j] = A[j+1];
            i--;
            n--;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(duplicate(A[i]))
        {
            for(int j = n;j>i;j--)
                A[j] = A[j-1];
            i++;
            n++;   
        }
    }
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    return 0;

}