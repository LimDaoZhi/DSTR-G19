#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
//changes example 
using namespace std;
//notes

std::set<std::string> loadWords(const std::string& filename) {
    std::set<std::string> words;
    std::ifstream file(filename);
    std::string word;
    while (file >> word) {
        words.insert(word);
    }
    return words;
}

int countWordsInComment(const std::string& comment, const std::set<std::string>& wordSet) {
    std::istringstream iss(comment);
    std::string word;
    int count = 0;
    while (iss >> word) {
        // Remove punctuation and convert to lowercase
        word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        if (wordSet.find(word) != wordSet.end()) {
            count++;
        }
    }
    return count;
}

void analyzeFeedback(const std::string& csvFile, const std::set<std::string>& positiveWords, const std::set<std::string>& negativeWords, int ratingColumn) {
    std::ifstream file(csvFile);
    std::string line;
    int positiveTally = 0, negativeTally = 0, neutralTally = 0;

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string cell;
        int column = 0;
        std::string comment;

        // Extract the comment from the specified rating column
        while (std::getline(ss, cell, ',')) {
            if (column == ratingColumn) {
                comment = cell;
                break;
            }
            column++;
        }

        if (!comment.empty()) {
            int posCount = countWordsInComment(comment, positiveWords);
            int negCount = countWordsInComment(comment, negativeWords);

            if (posCount > negCount) {
                positiveTally++;
            } else if (negCount > posCount) {
                negativeTally++;
            } else {
                neutralTally++;
            }
        }
    }

    std::cout << "Positive Comments: " << positiveTally << std::endl;
    std::cout << "Negative Comments: " << negativeTally << std::endl;
    std::cout << "Neutral Comments: " << neutralTally << std::endl;
}

int main() {
    std::set<std::string> positiveWords = loadWords("positive-words.txt");
    std::set<std::string> negativeWords = loadWords("negative-words.txt");

    std::string csvFile = "feedback.csv";
    int ratingColumn = 1; // Adjust based on your CSV format (0-based index)
    
    analyzeFeedback(csvFile, positiveWords, negativeWords, ratingColumn);

    return 0;
}
