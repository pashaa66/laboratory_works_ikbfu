#include <iostream>
#include<fstream>
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

int main()
{
    string text;
    cin >> text;
    for (int i = 0; i < text.length(); i++) {
        cout<<text[i]<<endl;
    }
    return 0;
}
