//
//  Matrix.hpp
//  Pretty BST print
//
//  Created by Philipp Habti on 17/10/2022.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>
#include <vector>
template<typename T>
class Matrix {
public:
  Matrix(int rows, int columns);

  Matrix(int rows, int columns, T defaultValue);

  T& at(int r, int c);

  int rows() const
  {
    return nbrRows;
  }

  int columns() const
  {
    return nbrColumns;
  }

private:
  std::vector<T> data;
  int            nbrRows;
  int            nbrColumns;
};

template<typename T>
Matrix<T>::Matrix(int rows, int columns) : data(rows * columns)
{
  nbrRows    = rows;
  nbrColumns = columns;
}

template<typename T>
Matrix<T>::Matrix(int rows, int columns, T defaultValue)
  : data(rows * columns, defaultValue)
{
  nbrRows    = rows;
  nbrColumns = columns;
}

template<typename T>
T& Matrix<T>::at(int r, int c)
{
  if ((r < 0) || (r >= nbrRows) || (c < 0) || (c >= nbrColumns))
    throw std::out_of_range("matrix");
  return data.at(r * nbrColumns + c);
}
#endif /* Matrix_hpp */
