
function equalSubstring(firstInput: string, secondInput: string, maxCost: number): number {
    let maxLengthForMaxCost = 0;
    let front = 0;
    let back = 0;
    let cost = 0;

    while (front < firstInput.length) {
        cost += Math.abs(firstInput.codePointAt(front) - secondInput.codePointAt(front));

        while (cost > maxCost && back < firstInput.length) {
            cost -= Math.abs(firstInput.codePointAt(back) - secondInput.codePointAt(back));
            ++back;
        }
        maxLengthForMaxCost = Math.max(maxLengthForMaxCost, front - back + 1);
        ++front;
    }

    return maxLengthForMaxCost;
};
