#include<iostream>
#include"SortTestHelper.h"
#include<queue>
#include<ctime>
#include<cassert>


template<typename Key , typename Value>
class BST{
public:

     BST(){
          root = NULL;
          count = 0;
     }

     ~BST(){
          destroy(root);
     }

     bool isEmpty(){
          return count == 0;
     }

     int size(){
          return count;
     }

     bool contain(Key key){

          return contain(root,key);
     }

     Value* search(Key key){

          return search(root,key);
     }

     void insert(Key key, Value value){

          root = insert(root,key,value);
     }
     //Breathed-first Search .
     void levelOrder(){

          queue<Node*> q;

          q.push(root);

          while( !q.empty()){
               Node* node = q.front();
               q.pop();

               std::cout << node->value << std::endl;

               if(node->left)
                    q.push(node->left);
               if(node->right)
                    q.push(node->right);
          }
     }

     void preOrder(){

          preOrder(root);
     }

     void removeMin(){

          if(root)
               removeMin(root);
     }

     void removeMax(){

          if(root)
               removeMax(root);
     }

     Key minmum(){
          assert( count != 0);
          Node* minnode = minmum(root);
          return minnode->key;
     }

     Key maxmum(){
          assert( count != 0 );

          Node* maxnode = maxmum(root);
          return maxnode->key;
     }

     void remove(Key key){

          if(root)
               root = remove(root,key);
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
          Node(Node* node){
               this->key = node->key;
               this->value = node->value;
               this->left = node->left;
               this->right = node->right;
          }
     };

     Node* remove(Node* node, Key key){

          if( node == NULL )
               return NULL;

          if( node->key < key){
               node->right = remove(node->right,key);
               return node;
          }
          else if( node->key > key){
               node->left = remove(node->left,key);
               return node;
          }
          else { //node->key == key

               if(node->right ==NULL){
                    Node* leftnode = node->left;
                    delete node;
                    count --;
                    return leftnode;
               }

               if(node->left == NULL){
                    Node* rightnode = node->right;
                    delete node;
                    count --;
                    return rightnode;
               }

               Node* newnode = new Node(minmum (node->right));
               count ++;

               newnode->right = removeMin(node->right);
               newnode->left = node->left;

               delete node;
               count --;
               return newnode;
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
          return root;
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

     bool contain(Node* node,Key key){

          if( node == NULL)
               return false;

          if(key == node->key)
               return true;
          else if ( key < node->key )
               contain(node->left,key);
          else
               contain(node->right,key);
     }

     Value* search(Node* node,Key key){

          if(node == NULL)
               return &(node->value);

          if(key ==  node->key)
               return &(node->value);
          else if ( key < node->key )
               return search(node->left,key);
          else  //key > node->key;
               return search(node->right,key);
     }

     void preOrder(Node* node){

          if(node != NULL){

               std::cout << node->value << std::endl;
               preOrder(node->left);
               preOrder(node->right);
          }
     }

     void inOrder(Node* node){

          if(node != NULL){
               inOrder(node->left);
               std::cout << node->value << std::endl;
               inOrder(node->right);
          }
     }

     void postOrder(Node* node){

          if(node != NULL){

               inOrder(node->left);
               inOrder(node->right);
               std::cout << node->value << std::endl;
          }
     }

     //释放以node根的二叉搜索树的节点
     //采用后序遍历的方法
     void destroy(Node* node){

          if( node != NULL ){

               destroy(node->left);
               destroy(node->right);

               delete node;
               count --;
          }
     }

     Node* minmum(Node* node){

          if(node == NULL)
               return NULL;
          return minmum(node->left);
     }

     Node* maxmum(Node* node){

          if( node == NULL )
               return NULL;

          return maxmum(node->right);
     }

     Node* removeMin(Node* node){

          if(node->left == NULL){

               Node* leftnode = node->right;
               count --;
               delete node;
               return leftnode;
          }

          node->left = removeMin(node->left);
          return node;
     }

     Node* removeMax(Node* node){

          if(node->right == NULL){

               Node* rightnode = node->left;
               count --;
               delete node;
               return rightnode;
          }

          node->right = removeMax(node->right);
          return node;
     }

     void removeMaxWithoutRecursive(Node* node){

          Node* newnode = node;

          while( newnode->right != NULL )
               newnode = newnode->right;

          delete newnode;
          count --;
     }
};

void shuffle(int arr[],int n)
{
     srand(time(NULL));
     for(int i=0; i < n ; i++){
          int x = rand()% (i+1);
          swap(arr[i],arr[x]);
     }
}
int main()
{
     srand(time(NULL));
     int n = 10;

     BST<int,int> bst = BST<int,int>();
     for( int i = 0 ; i < n ; i++){
          int x = i;
          int value = x;
          bst.insert(x,value);
     }

     bst.preOrder();
     std::cout << "++++++++++++++++++++++++++++++++++++" <<std::endl;
     int order[n];
     for(int i = 0 ; i < n ; i++)
          order[i] = i;

     shuffle(order,n);

     for(int i = 0; i < n ; i++)
          std::cout << order[i] << std::endl;

     for(int i = 0;i < n ; i++ ){
          if(bst.contain(order[i])){
               bst.remove(order[i]);
               std::cout << "After remove bst size : " << bst.size() << std::endl;
          }
     }

     std::cout << " end === size = " << bst.size() << std::endl;
     return 0;
}
