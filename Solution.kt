
import kotlin.math.abs
import kotlin.math.max

class Solution {
    fun equalSubstring(firstInput: String, secondInput: String, maxCost: Int): Int {
        var maxLengthForMaxCost = 0
        var front = 0
        var back = 0
        var cost = 0

        while (front < firstInput.length) {
            cost += abs(firstInput[front] - secondInput[front])

            while (cost > maxCost && back < firstInput.length) {
                cost -= abs(firstInput[back] - secondInput[back])
                ++back
            }
            maxLengthForMaxCost = max(maxLengthForMaxCost, front - back + 1)
            ++front
        }

        return maxLengthForMaxCost
    }
}
