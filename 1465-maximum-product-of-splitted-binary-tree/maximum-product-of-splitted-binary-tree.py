class Solution:
    def maxProduct(self, root):
        MOD = 10**9 + 7
        self.max_prod = 0

        # 1️⃣ Get total sum of the tree
        def total_sum(node):
            if not node:
                return 0
            return node.val + total_sum(node.left) + total_sum(node.right)

        total = total_sum(root)

        # 2️⃣ DFS to compute subtree sums and max product
        def dfs(node):
            if not node:
                return 0

            left = dfs(node.left)
            right = dfs(node.right)

            subtree_sum = node.val + left + right

            self.max_prod = max(
                self.max_prod,
                subtree_sum * (total - subtree_sum)
            )

            return subtree_sum

        dfs(root)
        return self.max_prod % MOD
