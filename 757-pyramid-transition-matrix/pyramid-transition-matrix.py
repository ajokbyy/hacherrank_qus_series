class Solution:
    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:
        from collections import defaultdict
        
        mp = defaultdict(list)
        for a in allowed:
            mp[a[:2]].append(a[2])

        def dfs(row):
            if len(row) == 1:
                return True

            def backtrack(i, cur):
                if i == len(row) - 1:
                    return dfs(cur)
                pair = row[i:i+2]
                for c in mp.get(pair, []):
                    if backtrack(i + 1, cur + c):
                        return True
                return False

            return backtrack(0, "")

        return dfs(bottom)
        