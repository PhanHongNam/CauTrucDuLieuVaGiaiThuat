#include<iostream>
#include<stdio.h>

using namespace std;

void bubleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[j] < a[j-1])
            {
                int temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }
}

int binarySearch(int a[], int n, int k)
{
    int left, right, mid;
    left = 0, right = n - 1;

    while (left <= right)
    {
        mid = (right + left) / 2;
        if (a[mid] == k)
            return mid;
        if (k < a[mid])
                right = mid - 1;
        else
                left = mid + 1;
    }
    return -1;
}

void xuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

int main()
{
    int a[] = {20, 10, 25, 19, 26, 38, 32};
    int b;
    bubleSort(a,7);
    xuat(a,7);
    b = binarySearch(a,7,26);
    if (b == -1)
        cout << "Khong tim thay";
    else
        cout << "Vi tri can tim: " << b + 1;

    return 0;
}
