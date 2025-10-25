/*
 * Author: Lorena
 */

#include "BinaryTreeClass.h"
#include "globals.h"
#include <iostream>
#include <string.h>

using namespace std;

BinaryTree::BinaryTree(){
    root = nullptr;
    this->size = 0;
}

int BinaryTree::returnIndex(char* parent){
    for(int i = 0; i < this->size; i++){
        if(strcmp(parent, vertices[i].name) == 0){
            return i;
        }
    }
    return -1;
}
        
void BinaryTree::nameTree(){
    this->name = list.remove();
}

void BinaryTree::nameRoot(){
    char* r = list.remove();
    int i = returnIndex(r);
    this->root = &vertices[i];
}

void BinaryTree::vertex(){
    int s = list.getSize();
    int count = 0;
    this->vertices = new BTreeNode[s];
    
    char* vert = list.remove();
    
    while(vert != nullptr){
        this->size++;
        this->vertices[count].name = vert;
        count++;
        vert = list.remove();
    }
}

void BinaryTree::edge(){
    char* p = list.remove(), *l = list.remove(), *r = list.remove();
    int i = 0, i1 = 0, i2 = 0;
    
    while(r != nullptr){
        i = returnIndex(p);
        i1 = returnIndex(l);
        i2 = returnIndex(r);
        
        if(i1 >= 0){
            vertices[i].left = &vertices[i1];
        }
        else{
            vertices[i].left = nullptr;
        }
        
        if(i2 >= 0){
            vertices[i].right = &vertices[i2];
        }
        
        else{
            vertices[i].right = nullptr;
        }
        
        p = list.remove();
        l = list.remove();
        r = list.remove();
    }
}

void BinaryTree::weight(){
    //store weights into associated linked lists
    char* n = list.remove(), *w = list.remove();
    int i = 0;
    
    while(w != nullptr){
        i = returnIndex(n);
        
        vertices[i].weight = w;
        
        n = list.remove();
        w = list.remove();
    }
}

//print right after all is read
void BinaryTree::printTree(){
    cout << "const char *" << this->name << "_Names[" << this->size << "] = {";
    for(int i = 0; i < this->size - 1; i++){
        cout << "\"" << vertices[i].name << "\",";
    }
    cout << "\""<< vertices[this->size - 1].name << "\"};" << endl;
    
    for(int i = this->size - 1; i >= 0; i--){
        cout << "vertex " << this->name << "_" << this->vertices[i].name << " = {";
        if(this->vertices[i].left == nullptr){
            cout << "NULL";
        }
        else{
            cout << "&" << this->name << "_" << this->vertices[i].left->name;
        }
        
        cout << ",";
        
        if(this->vertices[i].right == nullptr){
            cout << "NULL";
        }
        else{
            cout << "&" << this->name << "_" << this->vertices[i].right->name;
        }
        
        cout << "," << this->vertices[i].weight << "};\n";
        
    }
    
    cout << "vertex *" << this->name << "_Root = &" << this->name << "_" << this->root->name << ";" << endl;
    btree = BinaryTree();
}


LinkedList::LinkedList(){
    head = nullptr;
    tail = nullptr;
    this->size = 0;
}

int LinkedList::getSize() const{
    return this->size;
}

//add to end
void LinkedList::add(char* v){
    if(head == nullptr){
        head = new Node(strdup(v));
        tail = head;
    }
    else{
        if(tail != nullptr){
            tail->next = new Node(strdup(v));
            tail = tail->next;
        }
    }
    this->size++;
}

//remove from front
char* LinkedList::remove(){
    Node *ptr;
    char* name;
    
    if(!head){
        return nullptr;
    }
    else{
        ptr = head;
        head = head->next;
        name = ptr->value;
        delete ptr;
    }
    this->size--;
    return name;
}
