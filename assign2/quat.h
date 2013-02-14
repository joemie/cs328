#ifndef QUAT
#define QUAT
#include <vector>
#include <string>
#include <sstream>
#include <math.h>
#include <iostream>
#include "indexOutOfRangeError.h"
using namespace std;
template<class T>
class Quat
{
  private:
    float m_magnitude;
    T m_uCoef;
    T m_iCoef;
    T m_jCoef;
    T m_kCoef;
  public:
    Quat();
    Quat(T uCoef, T iCoef, T jCoef, T kCoef);
    Quat(Quat<T>& copyQuat);
    ~Quat();
    Quat<T>& operator=(const Quat<T> &copyQuat);
    Quat<T> operator+(const Quat<T> &quat2) const;
    Quat<T> operator-(const Quat<T> &quat2) const;
    Quat<T>& operator+=(const Quat<T> &quat2);
    Quat<T>& operator-=(const Quat<T> &quat2);
    bool operator==(const Quat<T> &quat2) const;
    bool operator!=(const Quat<T> &quat2) const;
    Quat<T> operator-() const;
    Quat<T> operator*(const Quat<T> &quat2) const;
    Quat<T> operator/(const Quat<T> &quat2) const;
    T operator[](const unsigned int index);
    Quat<T> operator!();
    float operator~();
    template<class U>
    friend ostream& operator<<(ostream& os, const Quat<U>& quat);
    float mag(T uCoef, T iCoef, T jCoef, T kCoef) const;
    Quat<T> inverse();
};
#include "quat.hpp"
#endif //QUAT
