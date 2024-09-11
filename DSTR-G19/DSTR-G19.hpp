#ifndef DSTRG19_HPP
#define DSTRG19_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>

// Define constants for sentiment scoring
const int MIN_SENTIMENT_SCORE = 1;
const int MAX_SENTIMENT_SCORE = 5;

// Class for handling sentiment analysis using arrays
class SentimentAnalysisArray {
private:
    std::vector<std::string> positiveWords;  // Vector to store positive words
    std::vector<std::string> negativeWords;  // Vector to store negative words
    std::vector<std::string> reviews;        // Vector to store hotel reviews
    std::vector<int> ratings;                // Vector to store user ratings

    // Private function to load words from files
    void loadWordsFromFile(const std::string& fileName, std::vector<std::string>& wordList);
    
    // Private function to load reviews and ratings from CSV file
    void loadReviewsFromCSV(const std::string& csvFileName);

    // Private function to calculate sentiment score for a single review
    int calculateSentimentScore(const std::string& review);

public:
    // Constructor
    SentimentAnalysisArray(const std::string& csvFileName, const std::string& posWordsFile, const std::string& negWordsFile);

    // Function to calculate sentiment scores for all reviews
    void calculateAllSentimentScores();

    // Function to compare sentiment score with user rating
    void compareRatingsWithSentiment();

    // Function to generate overall sentiment report
    void generateOverallSentimentReport();
};

// Struct for Linked List Node
struct ReviewNode {
    std::string review;    // Hotel review
    int rating;            // User rating
    ReviewNode* next;      // Pointer to the next node
};

// Class for handling sentiment analysis using linked lists
class SentimentAnalysisLinkedList {
private:
    std::vector<std::string> positiveWords;  // Vector to store positive words
    std::vector<std::string> negativeWords;  // Vector to store negative words
    ReviewNode* head;                        // Head pointer for linked list

    // Private function to load words from files
    void loadWordsFromFile(const std::string& fileName, std::vector<std::string>& wordList);
    
    // Private function to load reviews and ratings from CSV file
    void loadReviewsFromCSV(const std::string& csvFileName);

    // Private function to add a review node to the linked list
    void addReviewToLinkedList(const std::string& review, int rating);

    // Private function to calculate sentiment score for a single review
    int calculateSentimentScore(const std::string& review);

public:
    // Constructor
    SentimentAnalysisLinkedList(const std::string& csvFileName, const std::string& posWordsFile, const std::string& negWordsFile);

    // Destructor
    ~SentimentAnalysisLinkedList();

    // Function to calculate sentiment scores for all reviews
    void calculateAllSentimentScores();

    // Function to compare sentiment score with user rating
    void compareRatingsWithSentiment();

    // Function to generate overall sentiment report
    void generateOverallSentimentReport();
};

#endif // DSTRG19_HPP