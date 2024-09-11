#include "DSTR-G19.hpp" //main

// // Utility function to trim whitespace from a string
// std::string trim(const std::string& str) {
//     size_t first = str.find_first_not_of(' ');
//     if (std::string::npos == first) return str;
//     size_t last = str.find_last_not_of(' ');
//     return str.substr(first, (last - first + 1));
// }

// // ==================== SentimentAnalysisArray Class Implementation ====================

// SentimentAnalysisArray::SentimentAnalysisArray(const std::string& csvFileName, const std::string& posWordsFile, const std::string& negWordsFile) {
//     loadWordsFromFile(posWordsFile, positiveWords);
//     loadWordsFromFile(negWordsFile, negativeWords);
//     loadReviewsFromCSV(csvFileName);
// }

// void SentimentAnalysisArray::loadWordsFromFile(const std::string& fileName, std::vector<std::string>& wordList) {
//     std::ifstream file(fileName);
//     std::string word;
//     while (file >> word) {
//         wordList.push_back(word);
//     }
//     file.close();
// }

// void SentimentAnalysisArray::loadReviewsFromCSV(const std::string& csvFileName) {
//     std::ifstream file(csvFileName);
//     std::string line, review;
//     int rating;
//     while (getline(file, line)) {
//         std::istringstream ss(line);
//         getline(ss, review, ',');
//         ss >> rating;
//         reviews.push_back(trim(review));
//         ratings.push_back(rating);
//     }
//     file.close();
// }

// int SentimentAnalysisArray::calculateSentimentScore(const std::string& review) {
//     int positiveCount = 0, negativeCount = 0;
//     std::istringstream ss(review);
//     std::string word;
//     while (ss >> word) {
//         word = trim(word);
//         if (std::find(positiveWords.begin(), positiveWords.end(), word) != positiveWords.end()) {
//             positiveCount++;
//         } else if (std::find(negativeWords.begin(), negativeWords.end(), word) != negativeWords.end()) {
//             negativeCount++;
//         }
//     }
//     return positiveCount - negativeCount;
// }

// void SentimentAnalysisArray::calculateAllSentimentScores() {
//     for (size_t i = 0; i < reviews.size(); ++i) {
//         int sentimentScore = calculateSentimentScore(reviews[i]);
//         std::cout << "Review: " << reviews[i] << "\nSentiment Score: " << sentimentScore << "\n" << std::endl;
//     }
// }

// void SentimentAnalysisArray::compareRatingsWithSentiment() {
//     for (size_t i = 0; i < reviews.size(); ++i) {
//         int sentimentScore = calculateSentimentScore(reviews[i]);
//         // Implement comparison logic and output results as required
//     }
// }

// void SentimentAnalysisArray::generateOverallSentimentReport() {
//     // Implement overall sentiment analysis report logic here
// }

// // ==================== SentimentAnalysisLinkedList Class Implementation ====================

// SentimentAnalysisLinkedList::SentimentAnalysisLinkedList(const std::string& csvFileName, const std::string& posWordsFile, const std::string& negWordsFile) : head(nullptr) {
//     loadWordsFromFile(posWordsFile, positiveWords);
//     loadWordsFromFile(negWordsFile, negativeWords);
//     loadReviewsFromCSV(csvFileName);
// }

// SentimentAnalysisLinkedList::~SentimentAnalysisLinkedList() {
//     while (head) {
//         ReviewNode* temp = head;
//         head = head->next;
//         delete temp;
//     }
// }

// void SentimentAnalysisLinkedList::loadWordsFromFile(const std::string& fileName, std::vector<std::string>& wordList) {
//     std::ifstream file(fileName);
//     std::string word;
//     while (file >> word) {
//         wordList.push_back(word);
//     }
//     file.close();
// }

// void SentimentAnalysisLinkedList::loadReviewsFromCSV(const std::string& csvFileName) {
//     std::ifstream file(csvFileName);
//     std::string line, review;
//     int rating;
//     while (getline(file, line)) {
//         std::istringstream ss(line);
//         getline(ss, review, ',');
//         ss >> rating;
//         addReviewToLinkedList(trim(review), rating);
//     }
//     file.close();
// }

// void SentimentAnalysisLinkedList::addReviewToLinkedList(const std::string& review, int rating) {
//     ReviewNode* newNode = new ReviewNode{ review, rating, nullptr };
//     if (!head) {
//         head = newNode;
//     } else {
//         ReviewNode* temp = head;
//         while (temp->next) {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//     }
// }

// int SentimentAnalysisLinkedList::calculateSentimentScore(const std::string& review) {
//     int positiveCount = 0, negativeCount = 0;
//     std::istringstream ss(review);
//     std::string word;
//     while (ss >> word) {
//         word = trim(word);
//         if (std::find(positiveWords.begin(), positiveWords.end(), word) != positiveWords.end()) {
//             positiveCount++;
//         } else if (std::find(negativeWords.begin(), negativeWords.end(), word) != negativeWords.end()) {
//             negativeCount++;
//         }
//     }
//     return positiveCount - negativeCount;
// }

// void SentimentAnalysisLinkedList::calculateAllSentimentScores() {
//     ReviewNode* current = head;
//     while (current) {
//         int sentimentScore = calculateSentimentScore(current->review);
//         std::cout << "Review: " << current->review << "\nSentiment Score: " << sentimentScore << "\n" << std::endl;
//         current = current->next;
//     }
// }

// void SentimentAnalysisLinkedList::compareRatingsWithSentiment() {
//     // Implement comparison logic and output results as required
// }

// void SentimentAnalysisLinkedList::generateOverallSentimentReport() {
//     // Implement overall sentiment analysis report logic here
// }

// // ==================== Main Function ====================

// int main() {
//     // Example file paths (replace with your actual file paths)
//     std::string reviewsFile = "tripadvisor_hotel_reviews.csv";
//     std::string positiveWordsFile = "positive-words.txt";
//     std::string negativeWordsFile = "negative-words.txt";

//     // Sentiment analysis using arrays
//     std::cout << "Sentiment Analysis using Arrays:" << std::endl;
//     SentimentAnalysisArray analysisArray(reviewsFile, positiveWordsFile, negativeWordsFile);
//     analysisArray.calculateAllSentimentScores();
//     analysisArray.compareRatingsWithSentiment();
//     analysisArray.generateOverallSentimentReport();

//     // Sentiment analysis using linked lists
//     std::cout << "\nSentiment Analysis using Linked Lists:" << std::endl;
//     SentimentAnalysisLinkedList analysisLinkedList(reviewsFile, positiveWordsFile, negativeWordsFile);
//     analysisLinkedList.calculateAllSentimentScores();
//     analysisLinkedList.compareRatingsWithSentiment();
//     analysisLinkedList.generateOverallSentimentReport();

//     return 0;
// }
