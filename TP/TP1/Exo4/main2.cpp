#include <iostream>
#include <string>
#include <vector>

using namespace std;

//  '\0'  ' '   ','   '.'   'TAB'   '!'   '?' (Not counted)

bool valid_char(const char c) {
  return !(c=='\0'||c==' '||c=='\t'||c==','||c=='.'||c=='!'||c=='?');
}

void slice_sentence_and_sort(const string sentence, vector<string> &words) {
  size_t sentence_length = sentence.length();
  string word = "";
  int current_index = 0;
  for (size_t i = 0; i < sentence_length; i++) {
    bool is_valid = valid_char(sentence[i]);
    if (is_valid) word += sentence[i];
    if (
      (!is_valid || i == sentence_length-1) &&
      !word.empty()
    ) {
      words.push_back(word);
      int j = current_index-1;
      while (j >= 0 && (word.length() < words[j].length())) {
        words[j+1] = words[j];
        j--;
      }
      words[j+1] = word;
      current_index++;
      word.clear();
    }
  }
}

int main() {
  string sentence;
  vector<string> words;
  cout << "Enter Sentence: ";
  getline(cin >> ws, sentence);
  
  cout << "Your Sentence:   " << '"'+sentence+'"' << endl;

  slice_sentence_and_sort(sentence, words);

  cout << "Sorted Sentence: ";
  for (string word: words) cout << word << " ";
  cout << endl;

  return 0;
}
