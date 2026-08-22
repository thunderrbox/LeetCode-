class Solution {
    public int evalRPN(String[] tokens) {

        /*
         * APPROACH:
         * ----------
         * Reverse Polish Notation (RPN) follows:
         *
         * Operand Operand Operator
         *
         * Example:
         *     ["2", "1", "+", "3", "*"]
         *
         *     2 1 +  -> 3
         *     3 3 *  -> 9
         *
         * A Stack is the natural data structure for this problem.
         *
         * Whenever we see:
         *     1. Number  -> push it into the stack
         *     2. Operator -> pop the top two numbers,
         *                    perform the operation,
         *                    push the result back.
         */

        // Edge case: if there is only one token,
        // it must be a number, so directly return it.
        if (tokens.length == 1) {
            return Integer.parseInt(tokens[0]);
        }

        // Stack stores operands/results that are waiting
        // to be used by a future operator.
        Stack<Integer> st = new Stack<>();

        int a = 0;

        // Process every token from left to right.
        for (String token : tokens) {

            /*
             * If token is NOT an operator,
             * then it is an operand/number.
             *
             * Example:
             * "5" -> push 5
             * "-10" -> push -10
             */
            if (!token.equals("+") &&
                    !token.equals("-") &&
                    !token.equals("*") &&
                    !token.equals("/")) {

                // Convert String number into int
                // and push it onto the stack.
                st.push(Integer.parseInt(token));

            } else {

                /*
                 * We found an operator.
                 *
                 * The top two elements of the stack
                 * are the operands for this operator.
                 *
                 * IMPORTANT:
                 * The order matters for '-' and '/'.
                 *
                 * Example:
                 * Stack: [5, 2]
                 *
                 * For "-":
                 *     5 - 2
                 *
                 * NOT:
                 *     2 - 5
                 */

                // First pop = RIGHT operand
                int b = st.pop();

                // Second pop = LEFT operand
                a = st.pop();

                /*
                 * Perform the required operation.
                 *
                 * Example:
                 *     5 2 -
                 *
                 * b = 2
                 * a = 5
                 *
                 * result = 5 - 2 = 3
                 */
                switch (token) {

                    case "+":
                        a = a + b;
                        break;

                    case "-":
                        a = a - b;
                        break;

                    case "*":
                        a = a * b;
                        break;

                    case "/":
                        a = a / b;
                        break;
                }

                /*
                 * Push the calculated result back.
                 *
                 * This result can now act as an operand
                 * for a future operator.
                 *
                 * Example:
                 *     ["2", "1", "+", "3", "*"]
                 *
                 *     2, 1
                 *     + -> 3
                 *     stack -> [3]
                 *
                 *     3
                 *     3
                 *     * -> 9
                 */
                st.push(a);
            }
        }

        /*
         * At the end, only one value remains in the stack.
         * That value is the final answer.
         */
        return st.pop();
    }
}

// class Solution {
//     public int evalRPN(String[] tokens) {

//         int a = Integer.parseInt(tokens[0]);
//         int b = Integer.parseInt(tokens[1]);
//         for(int i= 2; i < tokens.length; i++){
//             if(tokens[i].equals("+")){
//                 a = a + b;
//             }else if(tokens[i].equals("-")){
//                 a = a - b;
//             }else if(tokens[i].equals("*")){
//                 a = a * b;
//             }else if(tokens[i].equals("/")){
//                 a = a / b;
//             }else{
//                 b = Integer.parseInt(tokens[i]);
//             }

//         }
//         return a;
//     }
// }