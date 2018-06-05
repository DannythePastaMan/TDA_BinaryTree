//
// Created by dgome on 5/31/2018.
//

#include "Tree.h"
#include <iostream>

using namespace std;

Tree::Tree()
{

}

Node *Tree::insertNode(Node *root, int v, Node *father)
{

    auto *newnode = new Node(v);
    newnode->left = nullptr;
    newnode->right = nullptr;
    newnode->father_of_node = father;

    if(root == nullptr)
    {
        root = newnode;
    }

    if(v < root->value)
    {
        root->left = insertNode(root->left, v, root);
    }

    else if(v > root->value)
    {
        root->right = insertNode(root->right, v, root);
    }

    return root;
}

void Tree::inorder(Node *root)
{
    if(root != nullptr)
    {
        inorder(root->left);
        cout << root->value << endl;
        inorder(root->right);
    }
}

void Tree::postOrder(Node *root)
{
    if(root != nullptr)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->value << "-";
    }
}

void Tree::preOrder(Node *root)
{
    if(root != nullptr)
    {
        cout << root->value << "-" << endl;
        preOrder(root->left);
        preOrder(root->right);
    }

}

void Tree::Delete(Node *root, int value)
{
    if(root == nullptr)
    {
        return;
    }

    else if(value < root->value)
    {
        Delete(root->left, value);
    }

    else if(value > root->value)
    {
        Delete(root->right, value);
    }

    else
    {
        deleteNode(root);
    }
}

void Tree::deleteNode(Node *node_to_delete) {
    if(node_to_delete->right && node_to_delete->left)
    {
        Node *min = minValue(node_to_delete->right);
        node_to_delete->value = min->value;
        deleteNode(min);
    }

    else if(node_to_delete->left)
    {
        Replace(node_to_delete, node_to_delete->left);
        node_to_delete->right = nullptr;
        node_to_delete->left = nullptr;
        delete node_to_delete;
    }

    else if(node_to_delete->right)
    {
        Replace(node_to_delete, node_to_delete->right);
        node_to_delete->right = nullptr;
        node_to_delete->left = nullptr;
        delete node_to_delete;
    }

    else
    {
        Replace(node_to_delete, nullptr);
        node_to_delete->right = nullptr;
        node_to_delete->left = nullptr;
        delete node_to_delete;
    }

}

Node *Tree::minValue(Node *root)
{
    if(root == nullptr)
    {
        return nullptr;
    }

    if(root->left)
    {
        return minValue(root->left);
    }

    else
    {
        return root;
    }
}

void Tree::Replace(Node *root, Node *substitute)
{
    if(root->father_of_node)
    {
        if(root->value == root->father_of_node->left->value)
        {
            root->father_of_node->left = substitute;
        }

        else if(root->value == root->father_of_node->right->value)
        {
            root->father_of_node->right = substitute;
        }
    }

    if(substitute)
    {
        substitute->father_of_node = root->father_of_node;
    }
}

void Tree::printLeaf(Node *root)
{
    if(root == nullptr)
    {
        return;
    }

    if(!root->left && !root->right)
    {
        cout << root->value << " " << endl;
    }

    if(root->left)
    {
        printLeaf(root->left);
    }

    if(root->right)
    {
        printLeaf(root->right);
    }
}

int Tree::sizeofTree(Node *root)
{
    if(root == nullptr)
    {
        return -1;
    }

    else
    {
        int size;
        size = (sizeofTree(root->left) + 1 + sizeofTree(root->right));
        cout << size << endl;
    }
}

