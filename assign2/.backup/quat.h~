#ifndef QUAT
#define QUAT
#include <vector>
#include <string>
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
    vector<T> parseStringVect(vector<string> sQuatVect);
    float mag(T uCoef, T iCoef, T jCoef, T kCoef);

};
#endif //QUAT
