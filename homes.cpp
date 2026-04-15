#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void getWords(vector<string>& words, ifstream& file);
void sortWords(vector<string>& words);
vector<pair<string, int>> getWordCounts(vector<string>& words);

int main(){
    ifstream file("homes.txt");

    if(!file) {
        cout << "Error opening file" << endl;
        return 1;
    }

    vector<string> words;

    getWords(words, file);
    sortWords(words);

    vector<pair<string, int>> counts = getWordCounts(words);   

    for (int i = 0; i < counts.size(); i++) {
        cout << counts[i].first << " " << counts[i].second << endl;
    }

    file.close();
    return 0;
}

void getWords(vector<string>& words, ifstream& file) {
    string word;
    
    while (file >> word) {
        words.push_back(word);
    }
}

void sortWords(vector<string>& words) {
    sort(words.begin(), words.end());

}
vector<pair<string, int>> getWordCounts(vector<string>& words) {
    vector<pair<string, int>> counts;

    for (int i = 0; i < words.size(); i++) {
        int count = 1;

        while (i + 1 < words.size() && words[i] == words[i + 1]) {
            count++;
            i++;
        }

        counts.push_back(make_pair(words[i], count));
    }

    return counts;
}

