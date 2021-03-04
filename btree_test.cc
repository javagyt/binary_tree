#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct btreeNode
{
  int value;
  btreeNode* lnode;
  btreeNode* rnode;
  btreeNode(int val) : value(val), lnode(nullptr), rnode(nullptr) {}
};

void inorder(btreeNode* node)
{
  if(node == nullptr)
    return;
  //pre order
  //cout << node->value << endl;
  inorder(node->lnode);
  //in order
  cout << node->value << endl;
  inorder(node->rnode);
  //back order
  //cout << node->value << endl;
}

void iterater_order(btreeNode* node)
{
  if(node == nullptr)
    return;

  stack<btreeNode*> st;
  while(node != nullptr || !st.empty())
  {
    while(node)
    {
      st.push(node);
      node = node->lnode;
    }
    if(!st.empty())
    {
      node = st.top();
      cout << node->value << endl;
      st.pop();
      node = node->rnode;
    }
  }
}

void levelOrder(btreeNode* node)
{
  if(node == nullptr)
	  return;
  queue<btreeNode*> q;
  q.push(node);
  while(!q.empty())
  {
    int currentLevelSize = q.size();
    for(int i = 0; i < currentLevelSize; i++)
    {
      auto it = q.front();
      cout << it->value << endl;
      q.pop();
      if(it->lnode != nullptr)
	      q.push(it->lnode);
      if(it->rnode != nullptr)
	      q.push(it->rnode);
    }
  }
}

int main(int args, const char **argv)
{
  // create a banary tree
  btreeNode* root = new btreeNode(1);
  root->lnode = new btreeNode(4);
  root->rnode = new btreeNode(7);

  inorder(root);

  cout << endl;

  iterater_order(root);

  cout << endl;

  levelOrder(root);

  return 0;
}
