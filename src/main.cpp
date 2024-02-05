#include "main.h"

int main(int argc, char* argv[]) try {
    std::fstream File = OpenFile("./scores.txt");
    std::vector<Score> Scores = ReadFile(File);
    PrintScores(Scores);
    PrintTop3();
    File.close();
    return EXIT_SUCCESS;
}
catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "An error occurred" << std::endl;
}

typedef struct Score {
    std::string Name;
    int Score;
} Score;

std::vector<Score> Top3 = { {"",-1},{"",-2},{"",-3} };

const inline void TestTop3(const Score& Score) {
    if (Score.Score >= Top3[0].Score) {
        Top3[2] = Top3[1];
        Top3[1] = Top3[0];
        Top3[0] = Score;
    }
    else if (Score.Score >= Top3[1].Score) {
        Top3[2] = Top3[1];
        Top3[1] = Score;
    }
    else if (Score.Score >= Top3[0].Score) {
        Top3[0] = Score;
    }
}

const inline void PrintTop3() {
    std::cout << "The gold medal winner is " << Top3[0].Name << " with " << Top3[0].Score << " points." << std::endl;
    std::cout << "The Silver medal winner is " << Top3[1].Name << " with " << Top3[1].Score << " points." << std::endl;
    std::cout << "The Bronze medal winner is " << Top3[2].Name << " with " << Top3[2].Score << " points." << std::endl;
    std::cout << "Congratulations to the winners!See you at the next tournament." << std::endl;
}

const inline void PrintScores(const std::vector<Score>& scores) {
    PrintHeader();
    for (const auto& score : scores) {
        PrintData(score.Name, score.Score);
    }
}

const inline std::vector<Score> ReadFile(std::fstream& File) {
    std::vector<Score> Scores;
    std::string Name;
    int score;
    while (!File.eof()) try {
        File >> Name >> score;
        Scores.push_back({ Name, score });
        TestTop3({ Name, score });
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
    return Scores;
}

inline std::fstream OpenFile(const std::string& filename) {
    std::fstream file;
    file.exceptions(std::ios::badbit | std::ios::failbit);
    file.open(filename, std::ios::in);
    return file;
}

const inline void PrintHeader() {
    std::cout << "IvyGames Tournament Results:" << std::endl;
    std::cout << std::setw(35) << std::setfill('-') << "-" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << "| " << std::setw(15) << std::left << "Username" << "| " << std::setw(15) << "Score" << "|" << std::endl;
    std::cout << std::setw(35) << std::setfill('-') << "-" << std::endl;
    std::cout << std::setfill(' ');
}

const inline void PrintData(const std::string& Username, const int& Score) {
    std::cout << std::setfill(' ');
    std::cout << "| " << std::setw(15) << std::left << Username << "| " << std::setw(15) << Score << "|" << std::endl;
    std::cout << std::setw(35) << std::setfill('-') << "-" << std::endl;
    std::cout << std::setfill(' ');
}