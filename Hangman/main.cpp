#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <set>
using namespace std;

vector<string> load_words(const string& filename) {
    ifstream ifs(filename);
    vector<string> words;
   if (!ifs) {
       cerr << "Could not open file " << filename << endl;
    return words;
   }
    string w;
    while (ifs>>w) {
        words.push_back(w);

    }
    ifs.close();
    return words;

}
string pick_word(const vector<string>& words) {
if (words.empty()) {
    return "";

}
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


    uniform_int_distribution<int> dist(0, words.size() - 1);
    return words[ dist(rng)];
}
string maskint (int length) {
  return string(length, '*');
}
bool apply_guess(const string& word, string& mask, char guess) {
    bool found = false;

    for (size_t i = 0; i < word.length(); ++i) {
        for (size_t i = 0; i < word.length(); ++i) {
            if (word[i] == guess && mask[i] == '*') {
                mask[i] = guess;
                found = true;
            }
        }
        return found;
    }
}
    int main() {
    auto words = load_words("C:/Users/cemil/CLionProjects/Hangman/words.txt");

        if (words.empty()) {
            cerr << "Word list is empty.\n";
            return 1;
        }
        string chosen_word=pick_word(words);
    for (char& c : chosen_word) {
        c = tolower(c);
    }
        string mask=maskint(chosen_word.length());
        set<char> guessed;
        int lives = 6;

        while (mask != chosen_word && lives > 0) {
            cout << "Word: ";
            for (char c : mask) cout << c << ' ';
            cout << "\nRemaining lives: " << lives << endl;

            cout << "Guess a letter: ";
            char guess;
            cin >> guess;
            guess = tolower(guess);

            if (guessed.count(guess)) {
                cout << "You already guessed this letter!\n\n";
                continue;
            }

            guessed.insert(guess);

            if (apply_guess(chosen_word, mask, guess)) {
                cout << "Correct guess!\n";
            } else {
                cout << "Incorrect guess!\n";
                lives--;
            }

            cout << "Guessed letters: ";
            for (char c : guessed) cout << c << ' ';
            cout << "\n\n";
        }

        if (mask == chosen_word) {
            cout << "Congratulations! You guessed the word: " << chosen_word << endl;
        } else {
            cout << "Sorry, you lost. The correct word was: " << chosen_word << endl;
        }

        return 0;
    }
