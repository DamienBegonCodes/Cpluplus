#pragma once

class TreeNode
{
public:
    int val;
    TreeNode * left;
    TreeNode * right;
    
    TreeNode();
    TreeNode(int);
    TreeNode(int, TreeNode *, TreeNode *);
};