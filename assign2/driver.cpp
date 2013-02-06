#define SUCCESSFUL 0
#include <iostream>
#include <string>

#include "parser.h"

using std::cout;
int main()
{
  Parser parsing;
  parsing.parseFile((char*)"data.dat");
  parsing.parseLine((char*)"line"); 
  cout << "MAIN COMPLETE\n";
  return (SUCCESSFUL);
}
