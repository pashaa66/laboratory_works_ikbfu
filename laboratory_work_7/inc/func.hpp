#pragma once
namespace pa
{
    void Read(int mas[100][100], int& n);
    void Write(int mas[100][100], int n);
    int findMinElement(int mas[100][100], int n);
    int findMaxElement(int mas[100][100], int n);
    bool differenceMaxMinLess2(int mas[100][100], int n);
    int sumOfColumn(int mas[100][100], int n, int j);
    void SortColumnsBySum(int mas[100][100], int n);
}