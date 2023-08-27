//
//  main.cpp
//  Pretty BST print
//
//  Created by Philipp Habti on 17/10/2022.
//

#include "TheBST.h"
#include <iostream>

int main(int argc, const char* argv[])
{
  BST myBST;
  std::cout << "Enter the numbers to be stored:"<< std::endl;
  std::string        s;
  std::getline(std::cin, s);
  std::istringstream is(s);
  myBST.processInput(s);
  // std::cout << "\n Which number do you want to look up?";
  // int numinput;
  // std::cin >> numinput;
  // if (myBST.hasKey(numinput)) {
  //   std::cout << std::endl << numinput << " is in the tree: yes\n";
  // }
  // else {
  //   std::cout << std::endl << numinput << " is in the tree: no\n";
  // }
  std::cout << "The numbers in sorted order: ";

  std::vector<int> inOrder1;
  inOrder1 = myBST.inOrder();
  for (int i = 0; i < inOrder1.size(); i++) {
    std::cout << inOrder1.at(i) << " ";
  }
  std::cout << '\n';

  // std::cout << "\nHeight of the tree: " << myBST.getHeight();

  myBST.prettyPrint();

  return 0;
}
