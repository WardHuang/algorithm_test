#ifndef _UNIONFINDWITHNODE_H_
#define _UNIONFINDWITHNODE_H_
#include<cassert>

namespace UF{
     class UnionFind{
     private:
          int count ;
     public:
          struct Node{
               Node* pre;
               Node* next;
               int sz;
               int value;
               Node* parent;
               bool operator==(Node* p1, Node* p2){
                    if(  p1->value == p2->value
                         && p1->parent == p2->parent
                         && p1->next == p2->next
                         && p1->pre == p2->pre
                         && p1->sz == p2->sz
                         )
                         return true;
                    return false;
               }
          };
          UnionFind(int n){
               this->count = n;

               Node* head = new Node;
               Node* temptr = head;
               head->pre = NULL;
               for(int i = 0; i < n ; i++){
                    Node* temp = new Node;
                    temp->value = i;
                    temp->parent = temp;
                    temptr->next = temp;
                    temp->pre = temptr;
                    temp->sz = 1;

                    temptr = temptr->next;
               }
          }
          ~UnionFind(){
//               destroy(head);
          }

          Node* find(Node* p){
               assert( p->parent == NULL );
               Node* NP = p;

               while( !(NP->parent == NP) ){
                    NP = NP->parent;
               }
               return NP;
          }

          bool isConnected(Node* p,Node* q){

               return find(p) == find(q);
          }

          void unionElementsBaseSize(Node* p, Node* q){

               Node* pRoot = find(p);
               Node* qRoot = find(q);

               if( pRoot == qRoot )
                    return ;

               if(pRoot->sz > qRoot->sz){
                    qRoot->parent = pRoot;
                    pRoot->sz += qRoot->sz;
               } else {
                    pRoot->parent = qRoot;
                    qRoot->sz += pRoot->sz;
               }
          }
     };
}

#endif
