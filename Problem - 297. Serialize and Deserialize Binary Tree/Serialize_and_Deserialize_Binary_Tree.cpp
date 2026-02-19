class Codec {
public:

    /*
    =============================================================
    PROBLEM:
    Serialize and Deserialize a Binary Tree
    =============================================================

    GOAL:
    -------------------------------------------------------------
    Convert a binary tree into a string (serialize)
    Convert that string back into the original tree (deserialize)

    IMPORTANT REQUIREMENT:
    -------------------------------------------------------------
    The structure of the tree must be preserved.
    So we must also store NULL nodes.

    APPROACH CHOSEN:
    -------------------------------------------------------------
    Use LEVEL ORDER TRAVERSAL (BFS).

    WHY LEVEL ORDER?
    -------------------------------------------------------------
    - It naturally preserves tree structure.
    - Parent-child relationship is easy to rebuild.
    - Queue helps reconstruct children in correct order.
    - Very intuitive for serialization problems.

    We represent NULL nodes as "$".
    Each value is separated by comma ",".
    */


    // ------------------------------------------------------------
    // SERIALIZE FUNCTION
    // ------------------------------------------------------------
    // Converts tree into string using BFS traversal.
    // ------------------------------------------------------------
    string serialize(TreeNode* root) {

        string s = "";

        /*
        If tree is empty,
        return empty string.
        */
        if(root == nullptr)
            return s;

        /*
        Use queue for level order traversal.
        */
        queue<TreeNode*> q;
        q.push(root);

        /*
        BFS Traversal
        */
        while(!q.empty()){

            TreeNode* node = q.front();
            q.pop();

            /*
            If node is NULL,
            store special marker "$"
            */
            if(node == nullptr){
                s.append("$,");
            }
            else{
                /*
                Store current node value.
                */
                s.append(to_string(node->val) + ",");

                /*
                Push left and right children
                EVEN IF THEY ARE NULL.

                Why?
                Because structure must be preserved.
                */
                q.push(node->left);
                q.push(node->right);
            }
        }

        return s;
    }


    // ------------------------------------------------------------
    // DESERIALIZE FUNCTION
    // ------------------------------------------------------------
    // Reconstruct tree from serialized string.
    // ------------------------------------------------------------
    TreeNode* deserialize(string data) {

        /*
        If string is empty,
        tree was empty.
        */
        if(data.size() == 0)
            return nullptr;

        /*
        Use stringstream to split by comma.
        */
        stringstream s(data);
        string str;

        /*
        First value always represents root.
        */
        getline(s, str, ',');

        TreeNode* root = new TreeNode(stoi(str));

        /*
        Use queue again to rebuild tree level by level.
        */
        queue<TreeNode*> q;
        q.push(root);

        /*
        Process until queue becomes empty.
        */
        while(!q.empty()){

            TreeNode* node = q.front();
            q.pop();

            /*
            --------------------
            BUILD LEFT CHILD
            --------------------
            */
            getline(s, str, ',');

            if(str != "$"){

                TreeNode* leftNode = new TreeNode(stoi(str));

                node->left = leftNode;

                q.push(leftNode);
            }

            /*
            --------------------
            BUILD RIGHT CHILD
            --------------------
            */
            getline(s, str, ',');

            if(str != "$"){

                TreeNode* rightNode = new TreeNode(stoi(str));

                node->right = rightNode;

                q.push(rightNode);
            }
        }

        return root;
    }
};


/*
=================================================================
COMPLETE INTUITION SUMMARY
=================================================================

SERIALIZATION:
--------------
1) Use BFS traversal.
2) Store node value.
3) If NULL, store "$".
4) Separate values by comma.
5) This preserves full structure.

Example Tree:
        1
       / \
      2   3
         / \
        4   5

Serialized string:
"1,2,3,$,$,4,5,$,$,$,$,"



DESERIALIZATION:
----------------
1) Read first value → create root.
2) Use queue to assign children.
3) For every node:
      - Next value → left child
      - Next value → right child
4) If "$", skip node creation.



=================================================================
TIME COMPLEXITY
=================================================================

Let n = number of nodes.

Serialization:
- Each node visited once → O(n)

Deserialization:
- Each node created once → O(n)

Total Time Complexity = O(n)



=================================================================
SPACE COMPLEXITY
=================================================================

1) Queue storage → O(n)
2) Output string storage → O(n)
3) Reconstructed tree → O(n)

Total Space Complexity = O(n)



=================================================================
WHY THIS APPROACH IS GOOD FOR INTERVIEWS?
=================================================================

- Simple
- Deterministic reconstruction
- Preserves exact structure
- Works for skewed trees
- Handles NULL nodes properly

This is the standard optimal BFS-based solution.
=================================================================
*/
