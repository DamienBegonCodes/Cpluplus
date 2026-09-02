#include "TreeNode.hpp"


// Representation of root_1 tree
//            1
//          /   \
//         2     5
//        / \   / \
//       3   4 6   7
TreeNode elem_7 = TreeNode(7);
TreeNode elem_6 = TreeNode(6);
TreeNode elem_5 = TreeNode(5, &elem_6, &elem_7);
TreeNode elem_4 = TreeNode(4);
TreeNode elem_3 = TreeNode(3);
TreeNode elem_2 = TreeNode(2, &elem_3, &elem_4);
TreeNode root_1 = TreeNode(1, &elem_2, &elem_5);