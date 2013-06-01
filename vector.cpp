/**
* @file vector.cpp
* @author skwo
* @brief Realization of vector class.
*/

#include <cmath>

#include "vector.hpp"

namespace skmath{

  //Constructor
  Vector::Vector()
  {
    _v[0] = 0.0f;
    _v[1] = 0.0f;
    _v[2] = 0.0f;
  }
  Vector::Vector(const Vector& v)
  {
    _v[0] = v[0];
    _v[1] = v[1];
    _v[2] = v[2];
  }
  Vector::Vector(float xVal, float yVal, float zVal)
  {
    _v[0] = xVal;
    _v[1] = yVal;
    _v[2] = zVal;
  }

  //Destructor
  Vector::~Vector()
  {
  }

  //Norm
  float Vector::norm() const
  {
    return (_v[0] * _v[0] + _v[1] * _v[1] + _v[2] * _v[2]);
  }

  //Magnitude
  float Vector::magnitude() const
  {
    return static_cast<float>(sqrt(this->norm()));
  }

  //Normalize
  Vector Vector::normalize() const
  {
    float length = this->magnitude();
    Vector res;

    if(length != 0.0f)
    {
      res[0] = _v[0] / length;
      res[1] = _v[1] / length;
      res[2] = _v[2] / length;
    }

    return res;
  }

  //Inverse
  Vector Vector::inverse() const
  {
    Vector res;
    res[0] = -_v[0];
    res[1] = -_v[1];
    res[2] = -_v[2];

    return res;
  }

  //Dot
  float Vector::dot(const Vector& rhs) const
  {
    float res = _v[0] * rhs[0] + _v[1] * rhs[1] + _v[2] * rhs[2];
    return res;
  }

  //Operator []
  const float& Vector::operator [](const int place) const
  {
    return _v[place];
  }
  float& Vector::operator [](const int place)
  {
    return _v[place];
  }

  //Operator ==
  bool Vector::operator ==(const Vector& rhs) const
  {
    if(&rhs == this)
      return true;
    else
    {
      if((_v[0] == rhs[0]) && (_v[1] == rhs[1]) && (_v[2] == rhs[2]))
        return true;
      else
        return false;
    }

    return false;
  }

  //Operator !=
  bool Vector::operator !=(const Vector& rhs) const
  {
    return !(*this == rhs);
  }

  //Operator =
  Vector& Vector::operator =(const Vector& rhs)
  {
    if(&rhs == this)
      return *this;
    else
    {
      _v[0] = rhs[0];
      _v[1] = rhs[1];
      _v[2] = rhs[2];
    }

    return *this;
  }

  //Operator +
  Vector Vector::operator +(const Vector& rhs) const
  {
    Vector res(_v[0] + rhs[0], _v[1] + rhs[1], _v[2] + rhs[2]);
    return res;
  }

  //Operator -
  Vector Vector::operator -(const Vector& rhs) const
  {
    Vector res(_v[0] - rhs[0], _v[1] - rhs[1], _v[2] - rhs[2]);
    return res;
  }

  Vector Vector::operator *(const Vector& rhs) const
  {
    Vector res(_v[1] * rhs[2] - _v[2] * rhs[1],  //Ay*Bz - Az*By
               _v[2] * rhs[0] - _v[0] * rhs[2],  //Az*Bx - Ax*Bz
               _v[0] * rhs[1] - _v[1] * rhs[0]); //Ax*By - Ay*Bx

    return res;
  }

  //Operator *
  Vector Vector::operator *(const float& rhs) const
  {
    Vector res(_v[0] * rhs, _v[1] * rhs, _v[2] * rhs);

    return res;
  }

  Vector Vector::operator /(const float& rhs) const
  {
    Vector res(_v[0] / rhs, _v[1] / rhs, _v[2] / rhs);

    return res;
  }

};
