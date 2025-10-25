/*
 * Author: Lorena
 */

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "vertex.h"
#include <stdlib.h>

class BinaryTree{
    private:
        struct BTreeNode{
            char* name;
            BTreeNode* left;
            BTreeNode* right;
            char* weight;
        };
    
        BTreeNode* root;
        char* name;
        BTreeNode* vertices;
        int size;
        
    public:
        BinaryTree();
    
        int returnIndex(char*);
        void nameTree();
        void nameRoot();
        void vertex();
        void edge();
        void weight();
        //print right after all is read
        void printTree();
};

class LinkedList{
    private:
        struct Node{
            char* value;
            Node *next;
            Node(char* val, Node *next1 = NULL){
                value = val;
                next = next1;
            }
        };
        Node *head;
        Node *tail;
        int size;
    
    public:
        LinkedList();
        
        int getSize() const;
        //add to end
        void add(char*);
        //remove from front and return value after removal
        char* remove();
};

#endif //BINARY_TREE_H
