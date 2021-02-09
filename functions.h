#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <stack>
using std::stack;

//STRUCT DECLARATION
struct BSTNode{
    int data;
    BSTNode *right;
    BSTNode *left;
};

//FUNCTION PROTOTYPES
void displayAllNode(BSTNode *root, stack<int> &testQ);
void DisplayMenu(BSTNode *root, int &choice);
void displayTree(BSTNode *root, int test);
void MenuOption(BSTNode *root, int &choice);
void insertNode(BSTNode *&root, int data);
void printMaxSum(BSTNode *root);
bool Search(BSTNode *root, int data);
int rootSum(BSTNode *root);
int height(BSTNode *root);
BSTNode *createNode(int data);
BSTNode *minValue(BSTNode *node);
BSTNode *deleteNode(BSTNode *root, int key);

#endif // FUNCTIONS_H_INCLUDED
