
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int equalSubstring(const string& firstInput, const string& secondInput, int maxCost) const {
        int maxLengthForMaxCost = 0;
        int front = 0;
        int back = 0;
        int cost = 0;

        while (front < firstInput.length()) {
            cost += abs(firstInput[front] - secondInput[front]);

            while (cost > maxCost && back < firstInput.length()) {
                cost -= abs(firstInput[back] - secondInput[back]);
                ++back;
            }
            maxLengthForMaxCost = max(maxLengthForMaxCost, front - back + 1);
            ++front;
        }

        return maxLengthForMaxCost;
    }
};
