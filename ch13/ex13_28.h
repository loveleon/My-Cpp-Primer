#pragma once
#include <iostream>
#include <string>
class TreeNode{
    public:
    TreeNode(std::string v=std::string()):value(v),count(new int(1)),left(nullptr),right(nullptr){}
    TreeNode(const TreeNode &t);
    TreeNode &operator=(TreeNode &tnode);
    ~TreeNode();
    private:
        std::string value;
        int *count;
        TreeNode *left;
        TreeNode *right;
};

class BinTreeNode{
    public:
        BinTreeNode(TreeNode *t=new TreeNode()):root(t){}
        BinTreeNode(BinTreeNode &bnode);
        BinTreeNode &operator=(BinTreeNode &bnode);
        ~BinTreeNode();
    private:
        TreeNode *root;
};
