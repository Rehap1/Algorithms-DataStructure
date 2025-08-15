#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;


void plusMinus(vector<int> arr) {
    double pos=0;
    double neg=0;
    double zero=0;
    int n = arr.size();

    for(int i=0; i<n; i++)
    {
        if(arr[i] > 0)
        {
            pos++;
        }
        else if (arr[i]<0)
        {
            neg++;
        }
        else
        {
        zero++;
        }
    }

    pos = pos/n;
    neg = neg/n;
    zero = zero/n;

    cout<<pos<<endl;
    cout<<fixed<<setprecision(neg)<<endl;
    cout<<fixed<<setprecision(zero)<<endl;

}


int main()
{
    vector<int> num = {-1,2,0,4};
    plusMinus(num);
    return 0;
}



class Solution
{
public:

    //O( n log n)
    int removeDuplicates1(vector<int>& nums)
    {
        set<int> unique(nums.begin(), nums.end());
        int i = 0;

        for(int num : unique)
        {
            nums[i++] = num;
        }

        return unique.size();

    }
};

//O (n)
int removeDuplicates2(vector<int>& nums)
{
    int n = nums.size(), l = 0, r = 0;
    while (r < n)
    {
        nums[l] = nums[r];
        while (r < n && nums[r] == nums[l])
        {
            r++;
        }
        l++;
    }
    return l;
}

