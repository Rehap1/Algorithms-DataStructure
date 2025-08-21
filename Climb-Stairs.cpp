// C++ program for implementation of Insertion Sort
#include <iostream>
#include <vector>
using namespace std;


vector<int> cache;

int dfs(int n, int i)
{
    if(i>=n) return i==n;
    if(cache[i] != -1) return cache[i];
    return cache[i] = dfs(n , i+1) + dfs(n, i+2);
}

int climbstairs(int n)
{

    cache.resize(n, -1);
    return dfs(n, 0);
}


// Driver method
int main()
{
    int x = 5;
    cout<<climbstairs(x)<<endl;
    return 0;
}

/* This code is contributed by Hritik Shah. */
