#include "quat.h"
#include "parser.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;
void Parser::parseFile(char* fileName)
{
  ifstream inFile;
  inFile.open(fileName);
  if(inFile.is_open())
  {
    m_lineNum = 0;
    while(inFile.good())
    {
      getline(inFile, m_line);
      if(m_lineNum == 0)
        m_numQuats = atoi(m_line.c_str());
      else
      {
        m_quatVect.push_back(parseLine(m_line));
      }
      m_lineNum++;
    }
    inFile.close();
    if(m_numQuats != m_quatVect.size() -1)
      cout << "DATA FILE INCOMPLETE" << endl;
  }
  else
    cout << "UNABLE TO OPEN FILE" << endl;
}
template<typename T>
vector<T> Parser::buildQuatVect(T var1, T var2, T var3, T var4)
{
  vector<T> temp;
  temp.push_back(var1);
  temp.push_back(var2);
  temp.push_back(var3);
  temp.push_back(var4);
  return temp;
}
vector<string> Parser::parseLine(string curLine)
{
  #define INT 1
  #define FLOAT 2
  #define DOUBLE 3
  size_t p0 = 0;
  size_t p1 = string::npos;
  vector<string> tokenized;
  while(p0 != string::npos)
  {
    p1 = curLine.find_first_of(" ", p0);
    if(p1 != p0)
    {
      string substr = curLine.substr(p0, p1 - p0);
      tokenized.push_back(substr);
    }
    p0 = curLine.find_first_not_of(" ", p1);
  }
  //determine type
  ParseQuat<int> pq;
  pq.setQuat(1,2,3,4);

  buildQuatVect(1,2,3,4);
  return tokenized;
}
int Parser::getNumQuats()
{
  return m_numQuats;
}
int Parser::getLineNum()
{
  return m_lineNum;
}
vector<vector<string> > Parser::getQuatVect()
{
  return m_quatVect;
}
template<class T> 
void Parser::ParseQuat<T>::setQuat(T var1, T var2, T var3, T var4)
{
  Quat<T> hello(var1, var2, var3, var4);
  m_quat = hello;

}
template<class T>
Quat<T> Parser::ParseQuat<T>::getQuat()
{
  return m_quat;
}
