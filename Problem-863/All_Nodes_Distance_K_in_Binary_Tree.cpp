/*
  All Nodes Distance K in Binary Tree  (LeetCode 863)

  Problem summary:
    Given the root of a binary tree, a pointer to a target node in the tree,
    and an integer k, return the values of all nodes that are exactly k edges
    away from the target node.

  Intuition (high level):
    A binary tree node knows its children but not its parent. To find nodes
    at distance k from `target` we need to be able to move up (to parent)
    as well as down (to children). Treat the tree like an undirected graph
    where each child has a connection to its parent.

  Approach (step-by-step):
    1) Run a BFS (or DFS) from the root and create a parent map: for every
       node, store a pointer to its parent. This gives us O(1) access to the
       parent of any node.

    2) Run a BFS starting from the `target` node and expand outward level by
       level. At each step we can move to three neighbors of a node: left child,
       right child, and parent (if they exist and are unvisited). Maintain a
       `seen` set to avoid revisiting nodes (prevent cycles).

    3) When the BFS level equals `k`, all nodes currently in the queue are
       exactly `k` distance away. Collect their values and return them.

  Complexity:
    Time: O(N) — each node is visited a constant number of times (build parent
                  map and the BFS from target).
    Space: O(N) — parent map + seen set + queue + answer vector.

  Note about node value field:
    Your original code used `node->data`. Many LeetCode problems use `val`.
    This file defines TreeNode with `data` to match your code. If you run
    this on LeetCode, change `.data` to `.val` or adjust the struct.
*/

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;


class Solution {
public:
    // Public function called by the problem framework.
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // ---------- Edge-case handling ----------
        // If tree is empty or target is null, no nodes can be at distance k.
        if (!root || !target) return {};

        // If k == 0, the only node at distance 0 is the target itself.
        if (k == 0) return { target->val };

        // ---------- Step 1: Build parent pointers ----------
        // Create a map: child_node -> parent_node. We use BFS from root to
        // ensure we visit every node and record its parent pointer.
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();

            // If left child exists, record its parent and push it for traversal
            if (cur->left) {
                parent[cur->left] = cur;
                q.push(cur->left);
            }

            // If right child exists, record its parent and push it
            if (cur->right) {
                parent[cur->right] = cur;
                q.push(cur->right);
            }
        }

        // ---------- Step 2: BFS from target to find nodes at distance k ----------
        // We will do a level-order traversal starting from `target` and expand
        // until we reach level k. Use `seen` set to avoid revisiting nodes.
        vector<int> ans;
        unordered_set<TreeNode*> seen;

        // Reuse queue `q` (clear it first) and start from target.
        while (!q.empty()) q.pop();
        q.push(target);
        seen.insert(target);

        int dist = 0; // current distance from target

        while (!q.empty()) {
            int sz = q.size();

            // If we've reached the required distance, collect all nodes in queue
            if (dist == k) {
                while (!q.empty()) {
                    TreeNode* nodeAtK = q.front();
                    q.pop();
                    ans.push_back(nodeAtK->val);
                }
                return ans; // finished — return collected values
            }

            // Otherwise, process the next BFS level (all nodes at current `dist`)
            for (int i = 0; i < sz; ++i) {
                TreeNode* cur = q.front();
                q.pop();

                // Explore left child if present and not visited
                if (cur->left && !seen.count(cur->left)) {
                    seen.insert(cur->left);
                    q.push(cur->left);
                }

                // Explore right child if present and not visited
                if (cur->right && !seen.count(cur->right)) {
                    seen.insert(cur->right);
                    q.push(cur->right);
                }

                // Explore parent (if recorded) and not visited
                // parent.count(cur) will be false only for the root node because
                // we didn't set a parent for the root while building the map.
                if (parent.count(cur) && !seen.count(parent[cur])) {
                    seen.insert(parent[cur]);
                    q.push(parent[cur]);
                }
            }

            // Completed one level of BFS (moved outward by one edge from target)
            ++dist;
        }

        // If we exhaust the BFS without reaching distance k, there are no nodes
        // at distance k (e.g., k is larger than tree diameter). Return empty.
        return ans;
    }
};

/*
  Extra notes / debugging tips:
    - If you test locally and your TreeNode uses `val` instead of `data`,
      change occurrences of `data` to `val`.
    - If the target pointer might not be part of the tree (not typical in the
      problem's constraints), you should either verify membership or handle
      that case based on how you want to respond (here we assume target is
      valid and present in the tree).
    - This solution is easy to reason about because it converts the problem
      into a graph-distance problem and then uses standard BFS level-order.
*/