/**
* @file quaternion.hpp
* @author skwo
* @brief Defenition of quaternion class.
*/

#ifndef QUATERNION_HPP_INCLUDED
#define QUATERNION_HPP_INCLUDED

#include "vector.hpp"

namespace skmath{

  class Matrix;

  class Quaternion{
    public:
      friend void quaternionToMatrix(Quaternion& q, Matrix& m);

      /** Constructor. Create identity quaternion.
      * @note The identity quaternion which created is a
      * Multiplication quaternion (1, [0,0,0]) and <b>NOT</b> Addition quaternion (0, [0,0,0]).
      */
      Quaternion();

      /** Copy constructor.
      * @param q Quaternion to copy.
      */
      Quaternion(const Quaternion& q);

      /** Constructor. Create quaternion.
      * @param w Scalar component of quaternion.
      * @param vec Vector component of quaternion.
      */
      Quaternion(float w, const Vector& vec);

      /** Destructor. */
      ~Quaternion();


      /** Get Vector.
      * @return Const vector component of quaternion.
      */
      const Vector& v() const;

      /** Get Vector.
      * @return Vector component of quaternion.
      */
      Vector& v();

      /** Get Scalar.
      * @return Const scalar component of quaternion.
      */
      const float& w() const;

      /** Get Scalar.
      * @return Const scalar component of quaternion.
      */
      float& w();

      /** Norma. (xx + yy + zz + ww)
      * @return Sum of components in square.
      */
      float norm() const;

      /** Magnitude.
      * @return Length/magnitude of quaternion.
      */
      float magnitude() const;

      /** Normalize.
      * @return Normalized quaternion.
      */
      Quaternion normalize() const;

      /** Conjugate.
      * @return Conjugated quaternion.
      */
      Quaternion conjugate() const;

      /** Inverese.
      * @return Inversed quaternion.
      */
      Quaternion inverse() const;

      /** Inner product of 2 quaternions.
      * @param rhs Right value quaternion.
      * @return Scalar number, inner product of <c>this</c> and <c>rhs</c>.
      */
      float inner(const Quaternion& rhs) const;

      /** Create rotation.
      * Create from current quaternion a rotation quaternion around the axis <c>vec</c> with
      * angle <c>angle</c>.
      * @param vec Axis of rotation.
      * @param angle Angle of rotation (degrees).
      */
      void createRotation(const Vector& vec, float angle);


      /** Const access operator.
      * @param place Place of component.
      * @return Const reference to component in <c>place</c>.
      * @note Place msut be 1, 2, 3 - for vector components, or 4 for scalat <c>w</c>!.
      */
      const float& operator [](const int place) const;

      /** Access operator.
      * @param place Place of component.
      * @return Reference to component in <c>place</c>.
      * @note Place msut be 1, 2, 3 - for vector components, or 4 for scalat <c>w</c>!.
      */
      float& operator [](const int place);

      /** Equal to operator.
      * @param rhs Right value quaternion.
      * @return true if <c>this</c> and <c>rhs</c> are equal, otherwise false.
      */
      bool operator ==(const Quaternion& rhs) const;

      /** Not equal to operator.
      * @param rhs Right value quaternion.
      * @return true if <c>this</c> and <c>rhs</c> are not equal, otherwise false.
      */
      bool operator !=(const Quaternion& rhs) const;

      /** Assign operator.
      * @param rhs Right value quaternion.
      * @return reference to <c>this</c>.
      */
      Quaternion& operator =(const Quaternion& rhs);

      /** Addition operator.
      * @param rhs Right value quaternion.
      * @return New quaternion, the sum of <c>this</c> and <c>rhs</c>.
      */
      Quaternion operator +(const Quaternion& rhs) const;

      /** Substraction operator.
      * @param rhs Right value quaternion.
      * @return New quaternion, the substract of <c>this</c> and <c>rhs</c>.
      */
      Quaternion operator -(const Quaternion& rhs) const;

      /** Multiplication operator.
      * @param rhs Right value.
      * @return New quaternion, the multiplication of <c>this</c> and <c>rhs</c>.
      */
      Quaternion operator *(const Quaternion& rhs) const;

      /** Multiplication operator.
      * @param rhs Right value.
      * @return New quaternion, the multiplication of <c>this</c> and <c>rhs</c>.
      */
      Quaternion operator *(const float& rhs) const;

      /** Division operator.
      * @param rhs Right value.
      * @return New quaternion, the division of <c>this</c> and <c>rhs</c>.
      */
      Quaternion operator /(const float& rhs) const;

    private:
      float _w; /**< Scalar component of quaternion. */
      Vector _v; /**< Vector component of quaternion. */
  };


  /** Quaternion to Matrix. Convert quaternion to matrix.
  * @param q Quaternion to convert.
  * @param m Matrix to store converted quaternion in.
  */
  void quaternionToMatrix(Quaternion& q, Matrix& m);

  /** Rotate.
  * Rotate <c>point</c> around <c>rotQuat</c>.
  * @param rotQuat Rotation Quaternion.
  * @param point Point to rotate.
  * @return New point, the result of rotation.
  */
  Vector rotate(const Quaternion& rotQuat, const Vector& point);

};

#endif // QUATERNION_HPP_INCLUDED
