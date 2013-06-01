/**
* @file vector.hpp
* @author skwo
* @brief Defenition of vector class.
*/

#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED

const unsigned short int cVectorSize = 3;

namespace skmath{

  class Vector{
    public:
      /** Constructor. Initialize vector to 0,0,0,1. */
      Vector();

      /** Copy constructor.
      * @param v Vector to copy.
      */
      Vector(const Vector& v);

      /** Constructor. Initialize vector.
      * @param xVal X Value.
      * @param yVal Y Value.
      * @param zVal Z Value.
      */
      Vector(float xVal, float yVal, float zVal);

      /** Destructor. */
      ~Vector();

      /** Norma. (xx + yy + zz)
      * @return Sum of components in square.
      */
      float norm() const;

      /** Calculate vector magnitude/length.
      * @return Magnitude of vector.
      */
      float magnitude() const;

      /** Normalize vector. */
      Vector normalize() const;

      /** Inverse vector. */
      Vector inverse() const;

      /** Dot product.
      * @param rhs Reference to right value vector.
      * @return Scalar number the dot product of <c>this</c> and <c>rhs</c>.
      */
      float dot(const Vector& rhs) const;


      /** Const access operator.
      * @param place Place of component to get.
      * @return Const reference to component in <c>place</c>.
      * @note Place must be 0, 1 or 2.
      */
      const float& operator [](const int place) const;

      /** Access operator
      * @param place Place of component to get.
      * @return Reference to component in <c>place</c>.
      * @note Place must be 0, 1 or 2.
      */
      float& operator [](const int place);

      /** Equal to operator.
      * @param rhs Right value vector.
      * @return true if <c>this</c> and <c>rhs</c> are equal, otherwise false.
      */
      bool operator ==(const Vector& rhs) const;

      /** Not equal to operator.
      * @param rhs Right value vector.
      * @return true if <c>this</c> and <c>rhs</c> are not equal, otherwise false.
      */
      bool operator !=(const Vector& rhs) const;

      /** Assign operator.
      * @param rhs Right value vector.
      * @return reference to <c>this</c>.
      */
      Vector& operator =(const Vector& rhs);

      /** Addition operator.
      * @param rhs Right value vector.
      * @return New vector the sum of <c>this</c> and <c>rhs</c>.
      */
      Vector operator +(const Vector& rhs) const;

      /** Substraction operator.
      * @param rhs Right value vector.
      * @return New vector, the substract of <c>this</c> and <c>rhs</c>.
      */
      Vector operator -(const Vector& rhs) const;

      /** Multiplication operator.
      * @param rhs Right value vector.
      * @return New vector, thr cross product of <c>this</c> and <c>rhs</c>.
      */
      Vector operator *(const Vector& rhs) const;

      /** Multiplication operator.
      * @param rhs Right value scalar.
      * @return New vector, the multiplication of <c>this</c> and <c>rhs</c>.
      */
      Vector operator *(const float& rhs) const;

      /** Division operator.
      * @param rhs Right value scalar.
      * @return New vector, the divison of <c>this</c> and <c>rhs</c>.
      */
      Vector operator /(const float& rhs) const;

    private:
      float _v[cVectorSize]; /**< The vector it self. */
  };

};

#endif // VECTOR_HPP_INCLUDED
