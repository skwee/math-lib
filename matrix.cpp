/**
* @file matrix.cpp
* @author skwo
* @brief Realization of matrix class.
*/

#include <cmath>

#include "matrix.hpp"
#include "quaternion.hpp"

namespace skmath{

  //Constructor
  Matrix::Matrix()
  {
    createIdentity();
  }
  Matrix::Matrix(Vector& x, Vector& y, Vector& z)
  {
    create(x, y, z);
  }
  Matrix::Matrix(float m[cMatrixSize])
  {
    create(m);
  }

  //Destructor
  Matrix::~Matrix()
  {
  }

  //Create identity
  void Matrix::createIdentity()
  {
    _m[0] = 1.0f; _m[4] = 0.0f; _m[ 8] = 0.0f; _m[12] = 0.0f;
    _m[1] = 0.0f; _m[5] = 1.0f; _m[ 9] = 0.0f; _m[13] = 0.0f;
    _m[2] = 0.0f; _m[6] = 0.0f; _m[10] = 1.0f; _m[14] = 0.0f;
    _m[3] = 0.0f; _m[7] = 0.0f; _m[11] = 0.0f; _m[15] = 1.0f;
  }

  //Create
  void Matrix::create(Vector& x, Vector& y, Vector& z)
  {
    _m[0] = x[0];  _m[4] = y[0];  _m[ 8] = z[0];  _m[12] = 0.0f;
    _m[1] = x[1];  _m[5] = y[1];  _m[ 9] = z[1];  _m[13] = 0.0f;
    _m[2] = x[2];  _m[6] = y[2];  _m[10] = z[2];  _m[14] = 0.0f;
    _m[3] = 0.0f;  _m[7] = 0.0f;  _m[11] = 0.0f;  _m[15] = 1.0f;
  }
  void Matrix::create(float m[cMatrixSize])
  {
    _m[0] = m[0]; _m[4] = m[4]; _m[ 8] = m[ 8]; _m[12] = m[12];
    _m[1] = m[1]; _m[5] = m[5]; _m[ 9] = m[ 9]; _m[13] = m[13];
    _m[2] = m[2]; _m[6] = m[6]; _m[10] = m[10]; _m[14] = m[14];
    _m[3] = m[3]; _m[7] = m[7]; _m[11] = m[11]; _m[15] = m[15];
  }

  //Create rotation X
  void Matrix::createRotationX(float angle)
  {
    float a = angle * cAngToRad;
    float s = sin(a);
    float c = cos(a);

    _m[0] = 1.0f; _m[4] = 0.0f; _m[ 8] = 0.0f; _m[12] = 0.0f;
    _m[1] = 0.0f; _m[5] = c;    _m[ 9] = -s;   _m[13] = 0.0f;
    _m[2] = 0.0f; _m[6] = s;    _m[10] =  c;   _m[14] = 0.0f;
    _m[3] = 0.0f; _m[7] = 0.0f; _m[11] = 0.0f; _m[15] = 1.0f;
  }

  //Create rotation Y
  void Matrix::createRotationY(float angle)
  {
    float a = angle * cAngToRad;
    float s = sin(a);
    float c = cos(a);

    _m[0] =  c;   _m[4] = 0.0f; _m[ 8] = s;    _m[12] = 0.0f;
    _m[1] = 0.0f; _m[5] = 1.0f; _m[ 9] = 0.0f; _m[13] = 0.0f;
    _m[2] = -s;   _m[6] = 0.0f; _m[10] = c;    _m[14] = 0.0f;
    _m[3] = 0.0f; _m[7] = 0.0f; _m[11] = 0.0f; _m[15] = 1.0f;
  }

  //Create rotation Z
  void Matrix::createRotationZ(float angle)
  {
    float a = angle * cAngToRad;
    float s = sin(a);
    float c = cos(a);

    _m[0] = c;    _m[4] = -s;   _m[ 8] = 0.0f; _m[12] = 0.0f;
    _m[1] = s;    _m[5] =  c;   _m[ 9] = 0.0f; _m[13] = 0.0f;
    _m[2] = 0.0f; _m[6] = 0.0f; _m[10] = 1.0f; _m[14] = 0.0f;
    _m[3] = 0.0f; _m[7] = 0.0f; _m[11] = 0.0f; _m[15] = 1.0f;
  }

  //Get Current matrix
  void Matrix::get(float m[cMatrixSize])
  {
    m[0] = _m[0]; m[4] = _m[4]; m[ 8] = _m[ 8]; m[12] = _m[12];
    m[1] = _m[1]; m[5] = _m[5]; m[ 9] = _m[ 9]; m[13] = _m[13];
    m[2] = _m[2]; m[6] = _m[6]; m[10] = _m[10]; m[14] = _m[14];
    m[3] = _m[3]; m[7] = _m[7]; m[11] = _m[11]; m[15] = _m[15];
  }

  //Operator []
  const float& Matrix::operator [](const int place) const
  {
    return _m[place];
  }
  float& Matrix::operator [](const int place)
  {
    return _m[place];
  }

  //Operator ==
  bool Matrix::operator ==(const Matrix& rhs) const
  {
    if(&rhs == this)
      return true;
    else
    {
      for(int i = 0; i < cMatrixSize; i++)
        if(_m[i] != rhs[i])
          return false;
    }

    return true;
  }

  //Operator !=
  bool Matrix::operator !=(const Matrix& rhs) const
  {
    return !(*this == rhs);
  }

  //Operator =
  Matrix& Matrix::operator =(const Matrix& rhs)
  {
    if(&rhs == this)
      return *this;
    else
    {
      for(int i = 0; i < cMatrixSize; i++)
        _m[i] = rhs[i];
    }

    return *this;
  }

  //Operator +
  Matrix Matrix::operator +(const Matrix& rhs) const
  {
    float rm[cMatrixSize];

    for(int i = 0; i < cMatrixSize; i++)
      rm[i] = _m[i] + rhs[i];

    Matrix res(rm);

    return res;
  }

  //Operator -
  Matrix Matrix::operator -(const Matrix& rhs) const
  {
    float rm[cMatrixSize];

    for(int i = 0; i < cMatrixSize; i++)
      rm[i] = _m[i] - rhs[i];

    Matrix res(rm);

    return res;
  }

  //Operator *
  Matrix Matrix::operator *(const Matrix& rhs) const
  {
    float rm[cMatrixSize];

    rm[ 0] = _m[0] * rhs[ 0] + _m[4] * rhs[ 1] + _m[ 8] * rhs[ 2] + _m[12] * rhs [ 3];
    rm[ 1] = _m[1] * rhs[ 0] + _m[5] * rhs[ 1] + _m[ 9] * rhs[ 2] + _m[13] * rhs [ 3];
    rm[ 2] = _m[2] * rhs[ 0] + _m[6] * rhs[ 1] + _m[10] * rhs[ 2] + _m[14] * rhs [ 3];
    rm[ 3] = _m[3] * rhs[ 0] + _m[7] * rhs[ 1] + _m[11] * rhs[ 2] + _m[15] * rhs [ 3];
    rm[ 4] = _m[0] * rhs[ 4] + _m[4] * rhs[ 5] + _m[ 8] * rhs[ 6] + _m[12] * rhs [ 7];
    rm[ 5] = _m[1] * rhs[ 4] + _m[5] * rhs[ 5] + _m[ 9] * rhs[ 6] + _m[13] * rhs [ 7];
    rm[ 6] = _m[2] * rhs[ 4] + _m[6] * rhs[ 5] + _m[10] * rhs[ 6] + _m[14] * rhs [ 7];
    rm[ 7] = _m[3] * rhs[ 4] + _m[7] * rhs[ 5] + _m[11] * rhs[ 6] + _m[15] * rhs [ 7];
    rm[ 8] = _m[0] * rhs[ 8] + _m[4] * rhs[ 9] + _m[ 8] * rhs[10] + _m[12] * rhs [11];
    rm[ 9] = _m[1] * rhs[ 8] + _m[5] * rhs[ 9] + _m[ 9] * rhs[10] + _m[13] * rhs [11];
    rm[10] = _m[2] * rhs[ 8] + _m[6] * rhs[ 9] + _m[10] * rhs[10] + _m[14] * rhs [11];
    rm[11] = _m[3] * rhs[ 8] + _m[7] * rhs[ 9] + _m[11] * rhs[10] + _m[15] * rhs [11];
    rm[12] = _m[0] * rhs[12] + _m[4] * rhs[13] + _m[ 8] * rhs[14] + _m[12] * rhs [15];
    rm[13] = _m[1] * rhs[12] + _m[5] * rhs[13] + _m[ 9] * rhs[14] + _m[13] * rhs [15];
    rm[14] = _m[2] * rhs[12] + _m[6] * rhs[13] + _m[10] * rhs[14] + _m[14] * rhs [15];
    rm[15] = _m[3] * rhs[12] + _m[7] * rhs[13] + _m[11] * rhs[14] + _m[15] * rhs [15];

    Matrix res(rm);

    return res;
  }

  //Operator *
  Vector Matrix::operator *(const Vector& rhs) const
  {
    Vector res(_m[0] * rhs[0] + _m[4] * rhs[1] + _m[ 8] * rhs[2],  //X
               _m[1] * rhs[0] + _m[5] * rhs[1] + _m[ 9] * rhs[2],  //Z
               _m[2] * rhs[0] + _m[6] * rhs[1] + _m[10] * rhs[2]); //z

    return res;
  }


  //Matrix to quaternion
  void matrixToQuaternion(Matrix& m, Quaternion& q)
  {
    q[3] = sqrt(1.0f + m[0] + m[5] + m[10]) / 2.0f;
    q[0] = (m[9] - m[6]) / (4.0f * q[3]);
    q[1] = (m[2] - m[8]) / (4.0f * q[3]);
    q[2] = (m[4] - m[1]) / (4.0f * q[3]);
  }

};
