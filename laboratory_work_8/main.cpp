#include <iostream>
using namespace std;
string vowels = "AEIOUYaeiouy";
string consonants = "BCDFGHJKLMNPQRSTVWXZbcdfghjklmnpqrstvwxz";
bool isVowel(char c) {
    return vowels.find(c) != string::npos;
}

bool hasDoubleVowels(string& s) {
    for (int i = 0; i < s.length(); i++) {
        if (isVowel(s[i])) {
            for (int j = i + 1; j < s.length(); j++) {
                if (s[i] == s[j] && isVowel(s[j])) {
                    return true;
                }
            }
        }
    }
    return false;
}

int count_vowels(string s){
    int cnt = 0;
    for(int i = 0; i < s.length(); i++){
        if(vowels.find(s[i]) != -1)
            cnt++;
    }
    return cnt;
}

void delete_consonants(string &s){
    for(int i = 0; i < s.length();){
        if(consonants.find(s[i]) != -1){
            s.erase(i,1);
        }
        else i++;
    }
}


void duplicate_vowels(string &s){
    for(int i = 0; i < s.length();){
        if(vowels.find(s[i]) != -1){
            s.insert(i+1,1,s[i]);
            i+=2;
        }
        else i++;
    }
}
void sort(string * words, int n){
    for(int i = 0; i<n;i++){
        for(int j = i + 1; j < n; j++){
            if(words[i] > words[j]){
                swap(words[i],words[j]);
            }
        }
    }
}

int main() {
    const int MAX_WORDS = 100;
    string words[MAX_WORDS];
    int word_count = 0;
    string word;
    while (cin >> word && word != ".") {
        words[word_count++] = word;
    }
    
    bool has_word_with_duplicate_vowels = false;
    for (int i = 0; i < word_count; i++) {
        if (hasDoubleVowels(words[i])) {
            has_word_with_duplicate_vowels = true;
            break;
        }
    }
    
    for (int i = 0; i < word_count; i++) {
        if (has_word_with_duplicate_vowels) {
            delete_consonants(words[i]);
        } else if (count_vowels(words[i]) >= 3) {
            duplicate_vowels(words[i]);
        }
    }
    sort(words, word_count);
    for (int i = 0; i < word_count; i++) {
        cout << words[i] << " ";
    }
    cout << endl;
    return 0;
}
