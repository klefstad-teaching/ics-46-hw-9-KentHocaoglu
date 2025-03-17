#include "ladder.h"
#include <unordered_set>

void error(string word1, string word2, string msg){
    cout << "Error: (" << word1 << ", " << word2 << ") " << msg << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    int diff_length = static_cast<int>(str1.size() - str2.size());
    if (abs(diff_length) > d) return false;
    
    int count = 0;
    for (size_t i = 0; i < str1.size() && i < str2.size(); ++i) {
        if (str1[i] != str2[i]) {
            if (++count > d) return false;
        }
    }
    return count <= d;
}
    
bool is_adjacent(const string& word1, const string& word2) {
    return edit_distance_within(word1, word2, 1);
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    queue<vector<string>> ladder_queue;
    string lower_case_begin_word = begin_word;
    transform(lower_case_begin_word.begin(), lower_case_begin_word.end(), begin_word.begin(), tolower);
    if (begin_word == end_word) return {};
    
    ladder_queue.push({begin_word});
    unordered_set<string> visited;
    visited.insert(begin_word);

    while (!ladder_queue.empty()) {
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back();
        
        for (const string& word : word_list) {
            if (is_adjacent(last_word, word) && visited.count(word) == 0) {
                visited.insert(word);
                vector<string> new_ladder = ladder;
                new_ladder.push_back(word);
                
                if (word == end_word) return new_ladder;
                
                ladder_queue.push(new_ladder);
            }
        }
    }
    return {};
}

void load_words(set<string>& word_list, const string& file_name) {
    string word;
    ifstream file(file_name);
    while (file >> word) {
        word_list.insert(word);
    }
}

void print_word_ladder(const vector<string>& ladder){
    if(!ladder.empty()){
     cout << "Word ladder found: " << endl;
        for (string word : ladder) {
            cout << word << " ";
        }
        cout << endl;
    }
    else{
        cout << "No word ladder found." << endl;
    }
}


#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}

void verify_word_ladder() {

    set<string> word_list;

    load_words(word_list, "words.txt");

    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);

    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);

    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);

    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);

    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);

    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);

}