template<class T>
Quat<T>::Quat()
{
  m_magnitude = 0;
  m_uCoef = 0;
  m_iCoef = 0;
  m_jCoef = 0;
  m_kCoef = 0;
}
template<class T>
Quat<T>::Quat(T uCoef, T iCoef, T jCoef, T kCoef)
{
  m_magnitude = mag(uCoef, iCoef, jCoef, kCoef);
  m_uCoef = uCoef;
  m_iCoef = iCoef;
  m_jCoef = jCoef;
  m_kCoef = kCoef;
}
template<class T>
Quat<T>::Quat(Quat<T>& copyQuat)
{
  m_magnitude = copyQuat.m_magnitude;
  m_uCoef = copyQuat.m_uCoef;
  m_iCoef = copyQuat.m_iCoef;
  m_jCoef = copyQuat.m_jCoef;
  m_kCoef = copyQuat.m_kCoef;
}
template<class T>
Quat<T>::~Quat()
{
  //TODO
}
template<class T>
Quat<T>& Quat<T>::operator=(const Quat<T> &copyQuat)
{
  m_magnitude = copyQuat.m_magnitude;
  m_uCoef = copyQuat.m_uCoef;
  m_iCoef = copyQuat.m_iCoef;
  m_jCoef = copyQuat.m_jCoef;
  m_kCoef = copyQuat.m_kCoef;
  return *this;
}
template<class T>
Quat<T> Quat<T>::operator+(const Quat<T> &quat2) const
{
  Quat<T> sum;
  sum.m_uCoef = m_uCoef + quat2.m_uCoef;
  sum.m_iCoef = m_iCoef + quat2.m_iCoef;
  sum.m_jCoef = m_jCoef + quat2.m_jCoef;
  sum.m_kCoef = m_kCoef + quat2.m_kCoef;
  sum.m_magnitude = mag(sum.m_uCoef, sum.m_iCoef, sum.m_jCoef, sum.m_kCoef);
  return sum;
}
template<class T>
Quat<T> Quat<T>::operator-(const Quat<T> &quat2) const
{
  Quat<T> sum;
  sum.m_uCoef = m_uCoef - quat2.m_uCoef;
  sum.m_iCoef = m_iCoef - quat2.m_iCoef;
  sum.m_jCoef = m_jCoef - quat2.m_jCoef;
  sum.m_kCoef = m_kCoef - quat2.m_kCoef;
  sum.m_magnitude = mag(sum.m_uCoef, sum.m_iCoef, sum.m_jCoef, sum.m_kCoef);
  return sum;
}
template<class T>
Quat<T>& Quat<T>::operator+=(const Quat<T> &quat2)
{
  m_uCoef = m_uCoef + quat2.m_uCoef;
  m_iCoef = m_iCoef + quat2.m_iCoef;
  m_jCoef = m_jCoef + quat2.m_jCoef;
  m_kCoef = m_kCoef + quat2.m_kCoef;
  m_magnitude = mag(m_uCoef, m_iCoef, m_jCoef, m_kCoef);
  return *this;
}
template<class T>
Quat<T>& Quat<T>::operator-=(const Quat<T> &quat2)
{
  m_uCoef = m_uCoef - quat2.m_uCoef;
  m_iCoef = m_iCoef - quat2.m_iCoef;
  m_jCoef = m_jCoef - quat2.m_jCoef;
  m_kCoef = m_kCoef - quat2.m_kCoef;
  m_magnitude = mag(m_uCoef, m_iCoef, m_jCoef, m_kCoef);
  return *this;
}
template<class T>
bool Quat<T>::operator==(const Quat<T> &quat2) const
{
  return (m_uCoef == quat2.m_uCoef && m_iCoef == quat2.m_iCoef && m_jCoef == quat2.m_jCoef && m_kCoef == quat2.m_kCoef);
}
template<class T>
bool Quat<T>::operator!=(const Quat<T> &quat2) const
{
  return !(*this == quat2);
}
template<class T>
Quat<T> Quat<T>::operator-() const
{
  Quat<T> retQuat;
  retQuat.m_uCoef = -m_uCoef;
  retQuat.m_iCoef = -m_iCoef;
  retQuat.m_jCoef = -m_jCoef;
  retQuat.m_kCoef = -m_kCoef;
  return retQuat; 
}
template<class T>
Quat<T> Quat<T>::operator*(const Quat<T> &quat2) const
{
  Quat<T> retQuat;
  retQuat.m_uCoef = (m_uCoef * quat2.m_uCoef) - (m_iCoef * quat2.m_iCoef) - (m_jCoef * quat2.m_jCoef) - (m_kCoef * quat2.m_kCoef);
  retQuat.m_iCoef = (m_uCoef * quat2.m_iCoef) + (m_iCoef * quat2.m_uCoef) + (m_jCoef * quat2.m_kCoef) - (m_kCoef * quat2.m_jCoef);
  retQuat.m_jCoef = (m_uCoef * quat2.m_jCoef) - (m_iCoef * quat2.m_kCoef) + (m_jCoef * quat2.m_uCoef) + (m_kCoef * quat2.m_iCoef);
  retQuat.m_kCoef = (m_uCoef * quat2.m_kCoef) + (m_iCoef * quat2.m_jCoef) - (m_jCoef * quat2.m_iCoef) + (m_kCoef * quat2.m_uCoef);
  return retQuat; 
}
template<class T>
T Quat<T>::operator[](const unsigned int index)
{
  switch(index)
  {
    case 0: return m_uCoef;
    case 1: return m_iCoef;
    case 2: return m_jCoef;
    case 3: return m_kCoef;
    default: throw IndexOutOfRangeError(index); 
  }
}
template<class T>
Quat<T> Quat<T>::operator!()
{
  Quat<T> retQuat;
  retQuat.m_uCoef = m_uCoef;
  retQuat.m_iCoef = -m_iCoef;
  retQuat.m_jCoef = -m_jCoef;
  retQuat.m_kCoef = -m_kCoef;
  return retQuat;
}
template<class T>
float Quat<T>::operator~()
{
  return mag(m_uCoef, m_iCoef, m_jCoef, m_kCoef);
}
template<class T>
float Quat<T>::mag(T uCoef, T iCoef, T jCoef, T kCoef) const
{
  return sqrt(uCoef*uCoef + iCoef*iCoef + jCoef*jCoef + kCoef*kCoef);
}
template<class T>
string Quat<T>::toString()
{
  stringstream ss (stringstream::in | stringstream::out);
  ss << "u: " << m_uCoef << " i: " << m_iCoef << " j: " << m_jCoef << " k: " << m_kCoef << " mag: " << m_magnitude << "\n";
  return ss.str();
}

