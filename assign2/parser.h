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
    vector<T> test();
    vector<string> parseLine(string curLine);
    int getNumQuats();
    int getLineNum();
    vector<vector<string> > getQuatVect();
};
#endif //PARSER
