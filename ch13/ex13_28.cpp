#include "ex13_28.h"

TreeNode &TreeNode::operator=(TreeNode &tnode){
   value = tnode.value;
   ++*tnode.count;
   if(--*count == 0){
        delete left;
        delete right;
        delete count;
   }
    left = tnode.left;
    right = tnode.right;
    count = tnode.count;
    return *this;
}

TreeNode::TreeNode(const TreeNode &t){
    value = t.value;
    left = t.left;
    right = t.right;
    count = t.count;
    ++*count;
}

TreeNode::~TreeNode(){
    if(--*count == 0){
        delete left;
        delete right;
    }
}

BinTreeNode::BinTreeNode(BinTreeNode &bnode){
    root = new TreeNode(*bnode.root);
}

BinTreeNode::~BinTreeNode(){
    delete root;
}

BinTreeNode &BinTreeNode::operator=(BinTreeNode &bnode){
    auto node = new TreeNode(*bnode.root);
    delete root;
    root = node;
    return *this;
}

int main(){
    BinTreeNode bnode;
    BinTreeNode b2 = bnode;
    return 0;
}
