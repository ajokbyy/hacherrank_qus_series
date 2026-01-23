class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        n = len(grid)

    # Step 1: flatten the grid into a list
        numbers = []
        for row in grid:
            for num in row:
                numbers.append(num)

    # Step 2: count frequency of each number
        count = {}
        for num in numbers:
            if num in count:
                count[num] += 1
            else:
                count[num] = 1

        repeated = -1
        missing = -1

    # Step 3: check numbers from 1 to n*n
        for i in range(1, n * n + 1):
            if i not in count:
                missing = i
            elif count[i] == 2:
                repeated = i

        return [repeated, missing]
