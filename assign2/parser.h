#ifndef PARSER
#define PARSER
#include <string>
#include <vector>
#include "quat.h"
using namespace std;
class Parser
{
  private:
    string m_line;
    int m_lineNum;
    int m_numQuats;
    vector<vector<string> > m_quatVect;
    
     
  public:
    void parseFile(char* fileName);
    template<typename T>
    vector<T> buildQuatVect(T var1, T var2, T var3, T var4);
    vector<string> parseLine(string curLine);
    int getNumQuats();
    int getLineNum();
    vector<vector<string> > getQuatVect();
    template<class T>
    class ParseQuat
    {
      private: 
        Quat<T> m_quat;
      public:
        Quat<T> getQuat();
        void setQuat(T var1, T var2, T var3, T var4);
    };
};
#endif //PARSER
