#include <iostream>


class BinaryTreeNode
{
   public:
      int _value;
      BinaryTreeNode* _left;
      BinaryTreeNode* _right;

      BinaryTreeNode(int value)
      {
         _value = value;
      }
};

class BinaryTree
{
   public:
      BinaryTreeNode* root;

   public:
      BinaryTreeNode* insert(BinaryTreeNode* node, BinaryTreeNode* parent)
      {
         if (!parent)
         {
            return node;
         }
         else if (node->_value < parent->_value)
         {
            printf("Going Left: (%d,%d)\n", node->_value, parent->_value);
            parent->_left = insert(node, parent->_left);
         }
         else if (node->_value > parent->_value)
         {
            printf("Going Right: (%d,%d)\n", node->_value, parent->_value);
            insert(node, parent->_right);
         }
         return parent;
      }
};

int main()
{
   BinaryTree* tree = new BinaryTree();

   BinaryTreeNode* root = new BinaryTreeNode(0);

   tree->insert(new BinaryTreeNode(10), root);
   tree->insert(new BinaryTreeNode(12), root);
   tree->insert(new BinaryTreeNode(1), root);
   tree->insert(new BinaryTreeNode(-1), root);
   tree->insert(new BinaryTreeNode(4), root);
   tree->insert(new BinaryTreeNode(8), root);
   tree->insert(new BinaryTreeNode(-4), root);




   return 0;
}
