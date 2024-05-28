
using System;

public class Solution
{
    public int EqualSubstring(string firstInput, string secondInput, int maxCost)
    {
        int maxLengthForMaxCost = 0;
        int front = 0;
        int back = 0;
        int cost = 0;

        while (front < firstInput.Length)
        {
            cost += Math.Abs(firstInput[front] - secondInput[front]);

            while (cost > maxCost && back < firstInput.Length)
            {
                cost -= Math.Abs(firstInput[back] - secondInput[back]);
                ++back;
            }
            maxLengthForMaxCost = Math.Max(maxLengthForMaxCost, front - back + 1);
            ++front;
        }

        return maxLengthForMaxCost;
    }
}
