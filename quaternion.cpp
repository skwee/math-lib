/**
* @file quaternion.cpp
* @author skwo
* @brief Realization of quaternion class.
*/

#include <cmath>

#include "quaternion.hpp"
#include "matrix.hpp"

namespace skmath{

  //Constructor
  Quaternion::Quaternion()
  {
    //Multiplicaiton identity quaternion
    _w = 1.0f;
    _v[0] = 0.0f;
    _v[1] = 0.0f;
    _v[2] = 0.0f;
  }
  Quaternion::Quaternion(const Quaternion& q)
  {
    _w = q.w();
    _v = q.v();
  }
  Quaternion::Quaternion(float w, const Vector& vec)
  {
    _w = w;
    _v = vec;
  }

  //Destructor
  Quaternion::~Quaternion()
  {
  }

  //Get Vector
  const Vector& Quaternion::v() const
  {
    return _v;
  }
  Vector& Quaternion::v()
  {
    return _v;
  }

  //Get Scalar
  const float& Quaternion::w() const
  {
    return _w;
  }
  float& Quaternion::w()
  {
    return _w;
  }

  //Norm
  float Quaternion::norm() const
  {
    return (_w * _w + _v[0] * _v[0] + _v[1] * _v[1] + _v[2] * _v[2]);
  }

  //Magnitude
  float Quaternion::magnitude() const
  {
    return static_cast<float>(sqrt(this->norm()));
  }

  //Normalize
  Quaternion Quaternion::normalize() const
  {
    float length = this->magnitude();

    Quaternion res;

    if(length != 0.0f)
    {
      res[3] = _w / length;
      res[0] = _v[0] / length;
      res[1] = _v[1] / length;
      res[2] = _v[2] / length;
    }

    return res;
  }

  //Conjugate
  Quaternion Quaternion::conjugate() const
  {
    Quaternion res(_w, _v.inverse());

    return res;
  }

  //Inverse
  Quaternion Quaternion::inverse() const
  {
    Quaternion res(*this);

    res.conjugate() / res.norm();

    return res;
  }

  //Dot
  float Quaternion::inner(const Quaternion& rhs) const
  {
    return (_v[0] * rhs[0] + _v[1] * rhs[1] + _v[2] * rhs[2] + _w * rhs.w());
  }

  //Create Rotation
  void Quaternion::createRotation(const Vector& vec, float angle)
  {
    float a = angle * cAngToRad;
    float half_a = a / 2.0f;

    _v = vec * sin(half_a);
    _w = cos(half_a);
  }

  //Operator []
  const float& Quaternion::operator [](const int place) const
  {
    if((place >= 0) && (place <= 2))
      return _v[place];

    return _w;
  }
  float& Quaternion::operator [](const int place)
  {
    if((place >= 0) && (place <= 2))
      return _v[place];

    return _w;
  }

  //Operator ==
  bool Quaternion::operator ==(const Quaternion& rhs) const
  {
    if(&rhs == this)
      return true;
    else
    {
      if((_w == rhs.w()) && (_v == rhs.v()))
        return true;
      else
        return false;
    }

    return false;
  }

  //Operator !=
  bool Quaternion::operator !=(const Quaternion& rhs) const
  {
    return !(*this == rhs);
  }

  //Operator =
  Quaternion& Quaternion::operator =(const Quaternion& rhs)
  {
    if(&rhs == this)
      return *this;
    else
    {
      _v = rhs.v();
      _w = rhs.w();
    }

    return *this;
  }

  //Operator +
  Quaternion Quaternion::operator +(const Quaternion& rhs) const
  {
    Vector resV = _v + rhs.v();
    Quaternion res(_w + rhs.w(), resV);

    return res;
  }

  //Operator -
  Quaternion Quaternion::operator -(const Quaternion& rhs) const
  {
    Vector resV = _v - rhs.v();
    Quaternion res(_w - rhs.w(), resV);

    return res;
  }

  //Operator *
  Quaternion Quaternion::operator *(const Quaternion& rhs) const
  {
    Vector resV(_w * rhs[0] + _v[0] * rhs.w() + _v[1] * rhs[2] - _v[2] * rhs[1], //X
                _w * rhs[1] + _v[1] * rhs.w() + _v[2] * rhs[0] - _v[0] * rhs[2], //Y
                _w * rhs[2] + _v[2] * rhs.w() + _v[0] * rhs[1] - _v[1] * rhs[0]); //Z

    Quaternion res(_w * rhs.w() - _v[0] * rhs[0] - _v[1] * rhs[1] - _v[2] * rhs[2], resV);
    return res;
  }

  //Operator *
  Quaternion Quaternion::operator *(const float& rhs) const
  {
    Vector resV = _v * rhs;
    Quaternion res(_w * rhs, resV);

    return res;
  }

  //Operator /
  Quaternion Quaternion::operator /(const float& rhs) const
  {
    Vector resV = _v / rhs;
    Quaternion res(_w / rhs, resV);

    return res;
  }

  //Quaternion to matrix
  void quaternionToMatrix(Quaternion& q, Matrix& m)
  {
    float qx, qy, qz, qw;
    qx = q[0];
    qy = q[1];
    qz = q[2];
    qw = q[3];

    m[ 0] = 1.0f - 2.0f * (qy * qy + qz * qz);
    m[ 1] =        2.0f * (qx * qy - qz * qw);
    m[ 2] =        2.0f * (qx * qz + qy * qw);

    m[ 4] =        2.0f * (qx * qy + qz * qw);
    m[ 5] = 1.0f - 2.0f * (qx * qx + qz * qz);
    m[ 6] =        2.0f * (qy * qz - qx * qw);

    m[ 8] =        2.0f * (qx * qz - qy * qw);
    m[ 9] =        2.0f * (qy * qz + qx * qw);
    m[10] = 1.0f - 2.0f * (qx * qx + qy * qy);

    m[3] = m[7] = m[11] = m[12] = m[12] = m[14] = 0.0f;
    m[15] = 1.0f;
  }

  //Rotate
  Vector rotate(const Quaternion& rotQuat, const Vector& point)
  {
    Quaternion p(0.0f, point); //convert point to quaternion.

    Quaternion result = (rotQuat * p) * rotQuat.conjugate();

    Vector res(result[0], result[1], result[2]);

    return res;
  }

};
