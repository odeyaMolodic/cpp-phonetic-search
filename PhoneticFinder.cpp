#include <stdexcept>
#include <string>

#include "PhoneticFinder.hpp"
using namespace std;

namespace phonetic {

    string find (string text, string word){

        string word_from_text = "";
        if (text == "" || text == " " || word == "" || word == " ")  
            throw invalid_argument("The word is empty");
        
        int i = 0;
        while (i < text.length()) {
            while (text[i] != ' ' && i < text.length()) {
                word_from_text += text[i];
                i++;
            }
            if(WordCompare(word_from_text, word))
                return word_from_text;
            i++;
            word_from_text.clear();
        } 

        throw out_of_range("There is no word : " + word + " in the text");
        return "";
    }

    bool WordCompare(string temp , string word){
      if(temp.length() != word.length()) return 0;
     
      int i = 0;
      while(i < word.length()) {
        if (!Spellcheck(temp[i], word[i])) return 0;
        i++;
      }
      
      return 1;
    }

    bool Spellcheck(char A, char B) {

        A = tolower(A);
        B = tolower(B);

        if( A == B) return 1;
        if ((A == 'w' || A == 'v') && (B == 'v' || B == 'w')) return 1;
        if ((A == 'g' || A == 'j') && (B == 'j' || B == 'g')) return 1;
        if ((A == 's' || A == 'z') && (B == 'z' || B == 's')) return 1;
        if ((A == 'd' || A == 't') && (B == 't' || B == 'd')) return 1;
        if ((A == 'o' || A == 'u') && (B == 'u' || B == 'o')) return 1;
        if ((A == 'i' || A == 'y') && (B == 'y' || B == 'i')) return 1;
        if ((A == 'c' || A == 'k' || A == 'q') && (B == 'k' || B == 'c' || B == 'q')) return 1;
        if ((A == 'b' || A == 'p' || A == 'f') && (B == 'p' || B == 'b' || B == 'f')) return 1;

        return 0;
    }

}
