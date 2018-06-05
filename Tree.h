//
// Created by dgome on 5/31/2018.
//

#ifndef TDA_BTREE_TREE_H
#define TDA_BTREE_TREE_H

#include "Node.h"

class Tree {
public:
    Tree();
    Node *insertNode(Node *, int, Node *);
    void inorder(Node *);
    void postOrder(Node *);
    void preOrder(Node *);
    void deleteNode(Node *);
    Node *minValue(Node *);
    void Replace(Node *, Node *);
    void Delete(Node *, int);
    void printLeaf(Node *);
    int sizeofTree(Node *);
};



#endif //TDA_BTREE_TREE_H
