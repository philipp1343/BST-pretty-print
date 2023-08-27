//
//  TheBST.cpp
//  Pretty BST print
//
//  Created by Philipp Habti on 17/10/2022.
//

#include "TheBST.h"
#include <iomanip>

BST::BST() : inOrders(0, 0), root(nullptr), height(0), lHeight(0), rHeight(0)
{
}

BST::~BST()
{
  deletes();
}

Node* newNode(int key)
{
  Node* node = new Node;
  node->data = key;
  node->left = node->right = nullptr;

  return node;
}

int BST::treeHeight(Node* travPtr)
{
  if (travPtr == nullptr) {
    return -1;
  }

  int rightHeight = treeHeight(travPtr->right);
  int leftHeight  = treeHeight(travPtr->left);

  if (rightHeight >= leftHeight) {
    return 1 + rightHeight;
  }

  return 1 + leftHeight;
}

int BST::getHeight()
{
  height = treeHeight(root);
  return height;
}

void BST::deletes()
{
  traverseD(root);
}

void BST::traverseD(Node* travPtr)
{
  if (travPtr != NULL) {
    traverseD(travPtr->left);

    traverseD(travPtr->right);

    delete travPtr;
  }
}

void BST::traverse(Node* travPtr)
{
  if (travPtr != NULL) {
    traverse(travPtr->left);

    inOrders.push_back(travPtr->data);

    traverse(travPtr->right);
  }
}

std::vector<int> BST::inOrder()
{
  traverse(root);
  return inOrders;
}

void BST::keyInsertion(Node*& travptr, int data)
{
  if (travptr == nullptr) {
    travptr = newNode(data);
    return;
  }
  (data > travptr->data) ? keyInsertion(travptr->right, data)
                         : keyInsertion(travptr->left, data);
}

void BST::insertKey(int data)
{
  keyInsertion(root, data);
}

Matrix<std::string> createRotatedMatrix(Matrix<std::string>& matrix)
{
  Matrix<std::string> result(
    /* rows */ matrix.columns(), /* columns */ matrix.rows());

  for (int i = 0; i < matrix.rows(); i++) {
    for (int j = 0; j < matrix.columns(); j++) {
      result.at(j, matrix.rows() - 1 - i) = matrix.at(i, j);
    }
  }

  return result;
}

void swapMatrixLeftAndRight(Matrix<std::string>& matrix)
{
  for (int row = 0; row < matrix.rows(); row++) {
    for (int column = 0; column < matrix.columns() / 2; column++) {
      std::string value      = matrix.at(row, column);
      matrix.at(row, column) = matrix.at(row, matrix.columns() - column - 1);
      matrix.at(row, matrix.columns() - column - 1) = value;
    }
  }
}

void printMatrixDashes(Matrix<std::string>& matrix)
{
  int dashesPerCell = 5;

  for (int column = 0; column < matrix.columns(); column++) {
    for (int i = 0; i < dashesPerCell; i++) {
      std::cout << '-';
    }
  }

  std::cout << "-\n";
}

void printMatrix(Matrix<std::string>& matrix)
{
  printMatrixDashes(matrix);

  for (int row = 0; row < matrix.rows(); row++) {
    for (int column = 0; column < matrix.columns(); column++) {
      std::cout << '|' << std::setw(4) << matrix.at(row, column);
    }

    std::cout << "|\n";
    printMatrixDashes(matrix);
  }
}

void BST::prettyPrint()
{
  if (root == nullptr) {
    return;
  }

  int                 nodeCount                   = countNodes(root);
  int                 height                      = getHeight();
  int                 horizontalMatrixColumnCount = 1 + height;
  Matrix<std::string> matrix(
    /* row */ nodeCount, /* col */ horizontalMatrixColumnCount);
  int row = 0;
  prettyPrintFillMatrix(matrix, root, row, 0);
  matrix = createRotatedMatrix(matrix);
  swapMatrixLeftAndRight(matrix);
  printMatrix(matrix);
}

void BST::prettyPrintFillMatrix(
  Matrix<std::string>& matrix,
  Node*                node,
  int&                 row,
  int                  column)
{
  if (node == nullptr) {
    return;
  }

  prettyPrintFillMatrix(matrix, node->left, row, column + 1);
  matrix.at(row, column) = std::to_string(node->data);
  row++;
  prettyPrintFillMatrix(matrix, node->right, row, column + 1);
}

void BST::processInput(std::string str)
{
  std::stringstream ss;
  ss << str;
  std::string temp;
  int         found;
  while (!ss.eof()) {
    ss >> temp;
    if (std::stringstream(temp) >> found)
      insertKey(found);
  }
}

bool BST::keyChecker(Node* travptr, int data)
{
  if (travptr == nullptr) {
    return false;
  }
  if (data == travptr->data) {
    return true;
  }

  return (data > travptr->data) ? keyChecker(travptr->right, data)
                                : keyChecker(travptr->left, data);
}

bool BST::hasKey(int searchKey)
{
  bool Key;
  Key = keyChecker(root, searchKey);
  return Key;
}

int BST::countNodes(Node* node)
{
  if (node == nullptr) {
    return 0;
  }

  return countNodes(node->left) + countNodes(node->right) + 1;
}
