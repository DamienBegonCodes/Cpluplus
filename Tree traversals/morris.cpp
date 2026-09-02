#include "TreeNode.hpp"
#include "test_tree.hpp"
#include <iostream>

// Inorder tree traversal with morris traversal
// Inorder traversal is printed in std::cout
void morris_traversal(TreeNode * root)
{
    TreeNode * current(root);
    while (current != nullptr)
    {
        if (current->left == nullptr)
        {
            std::cout << current->val << ", ";
            current = current->right;
        }
        else
        {
            TreeNode * prev(current->left);
            while (prev->right != nullptr && prev->right != current)
            {
                prev = prev->right;
            }
            if (prev->right == nullptr)
            {
                prev->right = current;
                current = current->left;
            }
            else
            {
                prev->right == nullptr;
                std::cout << current->val << ", ";
                current = current->right;
            }
        } 
    }
    std::cout << "TREE END" << std::endl;
}


int main()
{
    // Representation of root_1 tree
    //            1
    //          /   \
    //         2     5
    //        / \   / \
    //       3   4 6   7
    morris_traversal(&root_1);
    return 0;
}