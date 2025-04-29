#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <cctype>

using namespace std;

map<string, long> wordToNum = {
    {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
    {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9},
    {"ten", 10}, {"eleven", 11}, {"twelve", 12}, {"thirteen", 13},
    {"fourteen", 14}, {"fifteen", 15}, {"sixteen", 16}, {"seventeen", 17},
    {"eighteen", 18}, {"nineteen", 19}, {"twenty", 20}, {"thirty", 30},
    {"forty", 40}, {"fifty", 50}, {"sixty", 60}, {"seventy", 70},
    {"eighty", 80}, {"ninety", 90}, {"hundred", 100}, {"thousand", 1000},
    {"million", 1000000}, {"billion", 1000000000}
};

vector<string> split(const string& s) {
    vector<string> words;
    string word;
    for (char ch : s) {
        if (isalpha(ch)) {
            word += tolower(ch);
        }
        else if (word != "") {
            words.push_back(word);
            word = "";
        }
    }
    if (word != "") {
        words.push_back(word);
    }
    return words;
}

long wordsToNumber(const string& s) {
    vector<string> words = split(s);
    long result = 0;
    long current = 0;

    for (const string& word : words) {
        auto it = wordToNum.find(word);
        if (it == wordToNum.end()) {
            continue; // skip unknown words
        }

        long value = it->second;

        if (value == 100) {
            current *= value;
        }
        else if (value == 1000 || value == 1000000 || value == 1000000000) {
            current *= value;
            result += current;
            current = 0;
        }
        else {
            current += value;
        }
    }

    result += current;
    return result;
}

int main() {
    string input;
    cout << "Enter a number in words: ";
    getline(cin, input);

    long number = wordsToNumber(input);
    cout << "The number is: " << number << endl;

    return 0;
}