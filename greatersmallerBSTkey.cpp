#include <iostream>

using namespace std;

struct Node
{
  int key;
  Node *left;
  Node *right;
  Node *parent;
};

// Helper function that allocates a new Node 
Node* newNode( int key )
{
   Node* n = new Node;
   n->key = key;
   n->left = nullptr;
   n->right = nullptr;
   n->parent = nullptr;

   return n;
}

//                              12
//                 2                           25
//   1                    10            14            29

//  Given a binary search tree and a number, inserts a new Node with
//  the given number in the correct place in the tree. Returns the new
//  root pointer which the caller should then use 
Node *insert( Node *root, int key )
{
   // 1) If the tree is empty, return a new single Node
   if( root == nullptr )
      return newNode( key );

   Node *temp;

   // 2) Otherwise, recur down the tree
   if( key < root->key )
   {
      temp = insert( root->left, key );
      root->left = temp;
      temp->parent = root;
   } else
   {
      temp = insert( root->right, key );
      root->right = temp;
      temp->parent = root;
   }

   // Return the (unchanged) Node pointer
   return root;
}

void findres(Node *root, int num, int &res) {
  
         if(!root) {
            return;
         }
         if (root->key < num) {
               res = root->key;
         }else {
               findres(root, num, res);
         }
         
  
}


int findLargestSmallerKey(Node *root, int num) 
{
  
  int res = -1;
  
  findres(root, num, res);
  
  return res;
  // your code goes here
}

int main() {
  return 0;
}
