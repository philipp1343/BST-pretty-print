#pragma once
#include <cctype>
#include <cmath>
#include <ctype.h>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

#include "Matrix.h"

class Node {
public:
  int   data;
  Node* left;
  Node* right;
};

class BST {
public:
  // given functions
  BST();
  ~BST();
  std::vector<int> inOrder();
  bool             hasKey(int searchKey);
  int              getHeight();
  void             insertKey(int newKey);
  void             prettyPrint();
  // My functions
  void deletes();
  void traverseD(Node* travPtr);
  void keyInsertion(Node*& travptr, int data);
  void processInput(std::string str);
  void traverse(Node* travPtr);
  bool keyChecker(Node* travptr, int data);
  int  treeHeight(Node* travPtr);

private:
  void prettyPrintFillMatrix(
    Matrix<std::string>& matrix,
    Node*                node,
    int&                 row,
    int                  column);

  int countNodes(Node* node);

  std::vector<int> inOrders;
  Node*            root;
  int              height;
  int              lHeight;
  int              rHeight;
};
