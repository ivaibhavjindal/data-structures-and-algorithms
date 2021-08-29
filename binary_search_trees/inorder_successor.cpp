// https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1

/*The structure of Node

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node *inOrderSuccessor(Node *root, Node *x)
    {
        Node *successor = NULL;
        // if target has right subtree find min of that
        if (x->right)
        {
            successor = x->right;
            while (successor->left)
                successor = successor->left;
        }
        else
        {
            // find minimum greater val than target in path from root to target
            Node *temp = root;
            while (temp && temp != x)
            {
                if ((temp->data > x->data) && ((successor == NULL) || (temp->data < successor->data)))
                    successor = temp;

                if (temp->data > x->data)
                    temp = temp->left;
                else
                    temp = temp->right;
            }
        }

        return successor;
    }
};
