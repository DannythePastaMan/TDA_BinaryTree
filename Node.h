//
// Created by dgome on 5/31/2018.
//

#ifndef TDA_BTREE_NODE_H
#define TDA_BTREE_NODE_H

#include <iostream>

class Node {
public:
    Node(int);
    Node *left;
    Node *right;
    Node *father_of_node;
    int value;
};


#endif //TDA_BTREE_NODE_H
