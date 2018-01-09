#include<iostream>
#include"SortTestHelper.h"

template<typename Key , typename Value>
class BST{
public:

     BST(){
          root = NULL;
          count = 0;
     }

     ~BST(){
          //TODO:
     }

     bool isEmpty(){
          return count == 0;
     }

     int size(){
          return count;
     }

     void insert(Key key, Value value){
          root = insert(root,key,value);
     }
private:
     struct Node{
          Node* left;
          Node* right;
          Key key;
          Value value;

          Node(Key key ,Value value){
               this->key = key;
               this->value = value;
               this->left = this->right = NULL;
          }
     }
     int count;
     Node* root;

//Recursive insert!
     Node* insert(Node* root,Key key,Value value){

          if(root == NULL){
               count ++;
               return new Node(key,value);
          }

          if(key > root->key)
               root->right = insert(root->right,key,value);
          else if( key < root->key)
               root->left = insert(root->left,key,value);
          else{
               root->key = key;
               root->value = value;
          }
          return node;
     }
//Without Recursive!
     Node* wr_insert(Node* root,Key key,Value value){

          while(root != NULL){
               if(key == root->key){
                    root->key = key;
                    root->value = value;
                    return root;
               } else if(key > root->key){
                    root = root->right;
               } else {
                    root = root->left;
               }
          }
          Node* ret = new Node(key,value);

          return ret;
     }
};
