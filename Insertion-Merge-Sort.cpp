#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;



//Insertion Sort
vector<int> InsertionSort(vector<int>& arr)
{
    for(int i = 1; i<arr.size(); i++)
    {
        int j = i - 1;
        while(j >= 0 && arr[j+1] < arr[j])
        {
            int temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
    return arr;
}

void Merge(vector<int>& arr, int s, int m, int e)
{
    vector<int> left = {arr.begin()+ s, arr.begin()+ m + 1};
    vector<int> right = {arr.begin()+ m + 1, arr.begin()+ e + 1};

    int l = 0;
    int r = 0;
    int k = s; //index for arr

    while(l < left.size() && r < right.size())
    {
        if (left[l] <= right[r])
        {
            arr[k] = left[l];
            l++;
        }
        else
        {
            arr[k] = right[r];
            r++;
        }

        k++;
    }

    while(l < left.size())
    {
        arr[k++] = left[l++];
    }

    while (r < right.size())
    {
        arr[k++] = right[r++];
    }


}

vector<int> mergeSort(vector<int>& arr, int s, int e)
{

    if(s >= e)
    {
        return arr;
    }

    int m = (s+e)/2;
    mergeSort(arr,s,m);
    mergeSort(arr,m+1,e);

    Merge(arr, s, m, e);

    return arr;

}

int main()
{
    vector<int> arr = {1,6,8,4,2,4};
    int n = arr.size();

    cout << "Original array: ";
    for (int x : arr) {
        cout << x << " ";
    }
    std::cout << std::endl;

    arr = mergeSort(arr, 0, n);

      cout << "Sortted array: ";
    for (int x : arr) {
        cout << x << " ";
    }
    std::cout << std::endl;



}



