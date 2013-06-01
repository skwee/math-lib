/**
* @file matrix.hpp
* @author skwo
* @brief Defenition of matrix class.
* @note Translation matrix is not supported.
*/

#ifndef MATRIX_HPP_INCLUDED
#define MATRIX_HPP_INCLUDED

#include "vector.hpp"

const unsigned short int cMatrixSize = 16;
const float cAngToRad = 0.0174532925199432957693f;

namespace skmath{

  class Quaternion;

  class Matrix{
    public:
      friend void matrixToQuaternion(Matrix& m, Quaternion& q);
      /** Constructor. Create identity matrix. */
      Matrix();

      /** Constructor. Create matrix with <c>x</c> <c>y</c> and <c>z</c> axes.
      * @param x X axis.
      * @param y Y axis.
      * @param z Z axis.
      */
      Matrix(Vector& x, Vector& y, Vector& z);

      /** Constructor. Create matrix from <c>m</c>.
      * @param m Matrix to create from.
      */
      Matrix(float m[cMatrixSize]);

      /** Destructor. */
      ~Matrix();

      /** Create identity matrix. */
      void createIdentity();

      /** Create matrix with <c>x</c> <c>y</c> and <c>z</c> axes.
      * @param x X axis.
      * @param y Y axis.
      * @param z Z axis.
      */
      void create(Vector& x, Vector& y, Vector& z);

      /** Create matrix from <c>m</c>.
      * @param m Matrix to create from.
      */
      void create(float m[cMatrixSize]);

      /** Create rotation matrix around x axis.
      * @param angle Angle of rotation (degrees).
      */
      void createRotationX(float angle);

      /** Create rotation matrix around y axis.
      * @param angle Angle of rotation (degrees).
      */
      void createRotationY(float angle);

      /** Create rotation matrix around z axis.
      * @param angle Angle of rotation (degrees).
      */
      void createRotationZ(float angle);

      /** Get Current matrix.
      * @param m Array to store matrix in.
      */
      void get(float m[cMatrixSize]);

      /** Access operator.
      * @param place Place of component.
      * @return Const reference to component in <c>place</c>.
      * @note Place msut be between in range [0,15]!.
      */
      const float& operator [](const int place) const;

      /** Access operator.
      * @param place Place of component.
      * @return Reference to component in <c>place</c>.
      * @note Place msut be between in range [0,15]!.
      */
      float& operator [](const int place);

      /** Equal to operator.
      * @param rhs Right value matrix.
      * @return true if <c>this</c> and <c>rhs</c> are equal, otherwise false.
      */
      bool operator ==(const Matrix& rhs) const;

      /** Not equal to operator.
      * @param rhs Right value matrix.
      * @return true if <c>this</c> and <c>rhs</c> are not equal, otherwise false.
      */
      bool operator !=(const Matrix& rhs) const;

      /** Assign operator.
      * @param rhs Right value matrix.
      * @return reference to <c>this</c>.
      */
      Matrix& operator =(const Matrix& rhs);

      /** Addition operator.
      * @param rhs Right value matrix.
      * @return New matrix, the sum of <c>this</c> and <c>rhs</c>.
      */
      Matrix operator +(const Matrix& rhs) const;

      /** Substraction operator.
      * @param rhs Right value matrix.
      * @return New matrix, the substract of <c>this</c> and <c>rhs</c>.
      */
      Matrix operator -(const Matrix& rhs) const;

      /** Multiplication operator.
      * @param rhs Right value.
      * @return New matrix, the multiplication of <c>this</c> and <c>rhs</c>.
      */
      Matrix operator *(const Matrix& rhs) const;

      /** Multiplication operator.
      * @param rhs Right value.
      * @return New vector, the multiplication of <c>this</c> and <c>rhs</c>.
      */
      Vector operator *(const Vector& rhs) const;

    private:
      float _m[cMatrixSize];
  };


  /** Matrix toquaternion. Convert matrix to quaternion.
  * @param m Matrix to convert.
  * @param q Quaternion to store converted matrix in.
  */
  void matrixToQuaternion(Matrix& m, Quaternion& q);

};

#endif // MATRIX_HPP_INCLUDED
