#define SUCCESSFUL 0
#include <iostream>
#include <string>

#include "parser.h"
#include "quat.h"
using namespace std;
int main()
{
  Parser parsing;
  parsing.parseFile((char*)"data.dat");
  vector<vector<string> > sQuatVect = parsing.getQuatVect();
  Quat<int> q;
  q.parseStringVect(sQuatVect);

  for(int i = 0; i < sQuatVect.size(); i++)
  {
    for(int j = 0; j < sQuatVect[i].size(); j++)
    {
      cout << sQuatVect[i][j] << " ";
    }
    cout << endl;
  } 
  cout << "MAIN COMPLETE\n";
  return (SUCCESSFUL);
}
