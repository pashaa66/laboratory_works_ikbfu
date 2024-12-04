#include "inc/func.hpp"
#include <iostream>
#include <climits>

namespace pa{
    void Read(int mas[100][100], int& n)
    {
        std::cin >> n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                std::cin >> mas[i][j];
    }

    void Write(int mas[100][100], int n)
    {
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                std::cout << mas[i][j] << "\t";
            }    
            std::cout<<std::endl;
        }
    }
    int sumOfDigits(int num)
    {
        int sum = 0;
        while(num>0)
        {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int findMinElement(int mas[100][100], int n){
        int min = INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mas[i][j] < min)
                    min = mas[i][j];
            }
        }
        return min;
    }
    int findMaxElement(int mas[100][100], int n){
        int max = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mas[i][j] > max)
                    max = mas[i][j];
            }
        }
        return max;
    }
    bool differenceMaxMinLess2(int mas[100][100], int n){
        int min = findMinElement(mas, n);
        int max = findMaxElement(mas, n);
        int sum_min = sumOfDigits(min);
        int sum_max = sumOfDigits(max);
        if (abs(sum_max - sum_min)<=2){
            return true;
        }
        return false;
    }
    int sumOfColumn(int mas[100][100], int n, int j){
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += mas[i][j];
        }
        return sum;
    }
    void SortColumnsBySum(int mas[100][100], int n){
        for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < n-i-1; j++) {
                if(sumOfColumn(mas, n, j) > sumOfColumn(mas, n, j+1)) {
                    for(int k = 0; k < n; k++) {
                        int temp = mas[k][j];
                        mas[k][j] = mas[k][j+1];
                        mas[k][j+1] = temp;
                    }
                }
            }
        }
    }
}