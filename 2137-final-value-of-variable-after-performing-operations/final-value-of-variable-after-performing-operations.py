class Solution(object):
    def finalValueAfterOperations(self, operations):
        """
        :type operations: List[str]
        :rtype: int
        """
        nums = 0
        for x in operations:
            if "++" in x:
                nums +=1 
            else:
                nums -=1
        return nums
        