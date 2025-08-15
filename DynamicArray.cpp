#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;


int main()
{
    return 0;
}


//Implementation of resizable array (vector)
class DmArray
{
public:
    int capacity = 2;
    int length = 0;
    int *arr = new int[capacity];

    DmArray() {};

    // Insert n in the last position of the array
    void pushback(int n)
    {
        if (length == capacity)
        {
            Resize();
        }
        arr[length++] = n;
    }

    void Resize()
    {
        capacity = capacity * 2;
        int *newArr = new int [capacity];

        // Copy elements to newArr
        for (int i=0; i<length; i++)
        {
            newArr[i] = arr[i];
        }

        arr = newArr;
    }

    // Remove the last element in the array
    void popBack()
    {
        if(length > 0)
        {
            length--;
        }
    }



    // Get value at i-th index
    int get(int i)
    {
        if(i < length)
        {
            return arr[i];
        }
        return -1;
    }



    // Insert n at i-th index
    void insert(int i, int n)
    {
        if (i < length)
        {
            arr[i] = n;
        }
        else
        {
            cout<<"This index is out of bound"<<endl;
        }
    }


    void print()
    {
        for (int i = 0; i < length; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
};
