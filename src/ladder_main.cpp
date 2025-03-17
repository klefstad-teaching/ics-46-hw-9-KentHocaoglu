#include "ladder.h"

using namespace std;

int main() {

    set<string> word_list;
    load_words(word_list, "src/words.txt");

    string begin_word = "cat";
    string end_word = "dog"; 

    vector<string> ladder = generate_word_ladder(begin_word, end_word, word_list);
    print_word_ladder(ladder);
    cout << endl;
    cout << ladder.size();
    cout << endl;
    verify_word_ladder();
    return 0;
}