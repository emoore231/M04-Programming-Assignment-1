#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cassert>

#ifndef MAIN
#define MAIN
int main(int argc, char* argv[]);
#endif

#ifndef PRINTDATA
#define PRINTDATA
const inline void PrintData(const std::string& Username, const int& Score);
#endif

#ifndef PRINTHEADER
#define PRINTHEADER
const inline void PrintHeader();
#endif

#ifndef OPENFILE
#define OPENFILE
inline std::fstream OpenFile(const std::string& filename);
#endif

#ifndef SCORE
#define SCORE
typedef struct Score Score;
#endif

#ifndef READFILE
#define READFILE
const inline std::vector<Score> ReadFile(std::fstream& File);
#endif

#ifndef PRINTSCORES
#define PRINTSCORES
const inline void PrintScores(const std::vector<Score>& scores);
#endif

#ifndef TESTTOP3
#define TESTTOP3
const inline void TestTop3(const Score& Score);
#endif

#ifndef PRINTTOP3
#define PRINTTOP3
const inline void PrintTop3();
#endif