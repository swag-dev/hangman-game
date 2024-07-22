#include <iostream>
#include <vector>
#include <ctime>
#include <string>

using namespace std;
vector<string> simple_nouns{
                "house", "dog", "cat", "tree", "bird", "sun", "moon", "star", "water", "sky",
                "river", "mountain", "cloud", "food", "hand", "face", "foot", "shoe", "shirt",
                "ball", "book", "chair", "table", "light", "rain", "snow", "wind", "time", "day",
                "night", "sleep", "dream", "laugh", "smile", "play", "love", "friend", "school",
                "work", "game", "music", "dance", "sing", "eat", "drink", "run", "jump", "swim",
                "fly", "see", "hear", "smell", "taste", "touch", "hot", "cold", "big", "small",
                "happy", "sad", "angry", "good", "bad", "in", "out", "up", "down", "here",
                "there", "now", "then", "yes", "no", "one", "two", "three", "four", "five",
                "six", "seven", "eight", "nine", "ten", "red", "blue", "green", "yellow",
                "black", "white", "open", "close", "full", "empty", "fast", "slow", "hot",
                "cold", "long", "short"
};
int main(){
  srand(time(nullptr));
  string word {simple_nouns[static_cast<int>(rand()) %  simple_nouns.size()]};

  unsigned short int lives {3};
  unsigned short int user_char_pos {};
  unsigned char user_char {};
  unsigned int missing_count {};


  vector<char> word_chars(word.begin(), word.end());
  vector<char> pos_gens;
  vector<int> poss_hidden;
  vector<char> chars_hidden;

  for(unsigned int i {0}; i < (word.length() / 2); ++i)
  {
    int pos {static_cast<int>(rand()) % static_cast<int>(word.length())};
    while(word_chars[pos] == '_') {
      pos = static_cast<int>(rand()) % static_cast<int>(word.length());
    }
    chars_hidden.push_back(word_chars[pos]);
    word_chars[pos] = '_';
    ++missing_count;
    poss_hidden.push_back(pos);
  }
  for(auto x : word_chars)
  {
    cout << x << endl;
  }
  cout <<"Lives: " << lives << endl;

  while(missing_count != 0 && lives > 0) {
    cout << "Enter position: ";
    cin >> user_char_pos;
    while(user_char_pos > word.length()) {
      cout << "Enter valid position: ";
      cin >> user_char_pos;
    }
    cout << "Enter character: ";
    cin >> user_char;
    while(!isalpha(user_char)){
      cout << "Enter valid character: ";
      cin >> user_char;
    }
      char char_missing{};
      for (int i{0}; i < chars_hidden.size(); ++i) {
        if (user_char == chars_hidden[i] && user_char_pos - 1 == poss_hidden[i]) {

          word_chars[poss_hidden[i]] = chars_hidden[i];
          char_missing = chars_hidden[i];
          break;
        }
      }
      if (char_missing) {
        cout << "Correct" << endl;
        --missing_count;
        for (auto x: word_chars) {
          cout << x << endl;
        }
        cout <<"Lives: " << lives << endl;
        if(missing_count == 0)
        {
          cout << "YOU WON" << endl;
        }
      } else {
        cout << "Incorrect" << endl;
        --lives;
        for (auto x: word_chars) {
          cout << x << endl;
        }
        cout <<"Lives: " << lives << endl;
        if(lives == 0)
        {
          cout << "YOU LOST" << endl;
          cout << "The word was " + word << endl;
        }
      }
  }
  return 0;
}
