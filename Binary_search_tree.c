#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode
{
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode *createNode (int data)
{
  struct TreeNode *newNode =
    (struct TreeNode *) malloc (sizeof (struct TreeNode));
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

bool
isBST (struct TreeNode * root, struct TreeNode* prev)
{
  if (root == NULL)
    {
      return true;
    }
    if(!isBST(root->left,prev)){
        return false;
    }


  if (prev!= NULL && root->data <= prev->data)
    {
      return false;
    }
    
  prev = root;

return isBST (root->right, prev);}

int
main ()
{
  struct TreeNode *root = createNode (10);
  root->left = createNode (5);
  root->right = createNode (15);
  root->left->left = createNode (2);
  root->left->right = createNode (7);
  root->right->left = createNode (12);
  root->right->right = createNode (20);

  struct TreeNode *prev = NULL;
  if (isBST (root, prev))
    {
      printf ("the given tree is binary search tree");
    }
  else
    {
      printf ("the given tree is not binary search tree");
    }

  return 0;
}
