class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1 && k == 1) return 0;
        int length = pow(2, n-1);
        int mid = length/2;
        if(k <= mid){
            return kthGrammar(n-1, k);
        }
        return (1 - kthGrammar(n-1, k - mid));
    }
};//time complexity is O(N) using Recursion
// Key Idea:
// Recursive reduction based on binary tree structure or bit counting.


// class Solution {
// public:
//     int kthGrammar(int n, int k) {
//         return __builtin_popcount(k-1)%2;
//     }
// };////time complexity is O(log k) 