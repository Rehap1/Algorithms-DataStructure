#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;


int main()
{
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

