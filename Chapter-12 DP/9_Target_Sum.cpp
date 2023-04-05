#include <bits/stdc++.h>
using namespace std;

int findTargetSumWays(vector<int> &nums, int S)
{
    int count = 0, sumArr = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        sumArr += nums[i];
        if (nums[i] == 0)
            count++;
    }
    if (S > sumArr)
        return 0;

    if ((S + sumArr) % 2 != 0)
        return 0;

    int sum = (S + sumArr) / 2;

    int t[n + 1][sum + 1];

    for (int i = 0; i < n + 1; i++)
        t[i][0] = 1;

    for (int j = 1; j < sum + 1; j++)
        t[0][j] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (nums[i - 1] == 0)
                t[i][j] = t[i - 1][j];

            else if (j < nums[i - 1])
                t[i][j] = t[i - 1][j];

            else
                t[i][j] = t[i - 1][j] + t[i - 1][j - nums[i - 1]];
        }
    }

    return pow(2, count) * t[n][sum];
}