class Solution {

    /*
     * Understanding:
     * We are given a target array and numbers from 1 to n.
     * For every number i:
     *
     * 1. We always perform "Push".
     * 2. If i is required in the target array, we keep it.
     * 3. Otherwise, we perform "Pop" to remove it.
     *
     * We use 'j' to keep track of the current element
     * that we need to match in the target array.
     */

    public List<String> buildArray(int[] target, int n) {

        ArrayList<String> str = new ArrayList<>();

        // j points to the current element of target
        int j = 0;

        /*
         * Approach:
         * Traverse numbers from 1 to n.
         * Every number is first pushed into the stack.
         *
         * If the current number matches target[j],
         * we keep it and move j to the next target element.
         *
         * Otherwise, we pop the number because it is
         * not required in the target array.
         *
         * Once all target elements are processed,
         * we can stop.
         */
        for (int i = 1; i <= n; i++) {

            // Every number is initially pushed
            str.add("Push");

            // Current number is required in target
            if (target[j] == i) {

                // Move to the next target element
                j++;

                // All target elements have been processed
                if (j == target.length) {
                    break;
                }

            } else {

                // Current number is not required, so remove it
                str.add("Pop");
            }
        }

        return str;
    }

    /*
     * Complexity:
     *
     * Time Complexity: O(n)
     * We traverse the numbers from 1 to n at most once.
     *
     * Space Complexity: O(n)
     * The result list can contain up to 2n operations.
     */
}



// class Solution {
//     public List<String> buildArray(int[] target, int n) {
//         ArrayList<String>str = new ArrayList<>();
//         Stack<Integer> st = new Stack<>();
//         for(int i = 1; i <= n; i++){
//             for(int j = 0; j < target.length; j++){
//                 if(target[j] == i){
//                     st.push(i);
//                     str.add("Push");
//                 }else if(!st.isEmpty() && st.peek() != --i){
//                     st.pop();
//                     str.add("Pop");
//                 }
//             }
//             if(target.length == st.size()){
//                 break;
//             }
//         }
//         return str;
//     }
// }