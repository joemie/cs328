#include "quat.h"

template<class T>
Quat<T>::Quat()
{
  m_uCoef = 0;
  m_iCoef = 0;
  m_jCoef = 0;
  m_kCoef = 0;
}
template<class T>
Quat<T>::Quat(T uCoef, T iCoef, T jCoef, T kCoef)
{
  m_uCoef = uCoef;
  m_iCoef = iCoef;
  m_jCoef = jCoef;
  m_kCoef = kCoef;
}
template<class T>
vector<T> Quat<T>::parseStringVect(vector<string> sQuatVect)
{
  vector<int> temp;
  return temp;
}
template<class T>
float Quat<T>::mag(T uCoef, T iCoef, T jCoef, T kCoef)
{
  return 100;
}

