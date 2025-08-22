// C++ program for implementation of Insertion Sort
#include <iostream>
#include <vector>
using namespace std;


bool searchMatrix(vector<vector<int>>& matrix, int target)
{

    int top = 0; // row 0
    int bot = matrix.size() - 1; //row n

    while(top <= bot)
    {
        //middle row of the array (n/2)
        int mid = (top + bot) / 2;
        ///the first element the mid row smaller target && last element is bigger than the target
        if( matrix[mid][0] < target && matrix[mid][matrix[mid].size() -1 ] > target )
        {
            //this means we found the target row
            break;
        }
        else if (matrix[mid][0]> target)
        {
            bot = mid - 1;
        }
        else
        {
            top = mid + 1;
        }
    }

    int row = (top + bot) / 2;
    int left = 0;
    int right = matrix[row].size() - 1;

    while(left <= right)
    {
        int mid =  (left + right) / 2;

        if(matrix[row][mid] < target)
        {
            left = mid + 1;
        }
        else if (matrix[row][mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            return true;
        }

    }
    return false;
}

// Driver method
int main()
{
    return 0;
}

