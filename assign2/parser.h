#ifndef PARSER
#define PARSER

class Parser
{
  private:
    char line[16];
  public:
    void parseFile(char* fileName); 
    void parseLine(char* curLine);
};
#endif //PARSER
