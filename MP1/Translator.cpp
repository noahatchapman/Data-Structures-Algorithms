#include "Translator.h"
#include "Model.h"

/*
    Default Constructor which initilizes a Model object
*/
Translator::Translator(){
    myModel = new Model();
}

/*
    Destructor
*/
Translator::~Translator(){
    delete myModel;
    cout << "Calling Translator destructor" << endl;
}

/*  
    Translates an English word to Robber Language.
    Checks each character of the word. If it's a letter, then it's checked to be either
    a vowel or a consonant. If it's a consonant, the consonant is repeated with an o added between. If it's a vowel
    no change. If it's not a letter, no change. 
    Returns the translated word as a string. 
*/
string Translator::translateEnglishWord(string englishWord){ 
    string translatedWord = "";
    for(int i = 0; i < englishWord.length(); ++i){
        char myChar = getChar(englishWord, i); // Get each character
        if(isLetter(myChar)){                   // Check if its a letter
            if(isConsonant(myChar)){            // Check if its a consonant or vowel
                string translatedConsonant = myModel->translateSingleConsonant(myChar); // Translate and add the consonant to word
                translatedWord += translatedConsonant; 
            }
            else{
                string translatedVowel = myModel->translateSingleVowel(myChar); // Translate and add the vowel to word
                translatedWord += translatedVowel; 
            }
        }
        else{
            translatedWord += myChar; // If not a letter, add to word without translating
        }
    }
    return translatedWord;

}

/*
    Translates an English sentence to Robber language. 
    Keeps track of the starting index of each word in the sentence using startWordPos.
    A word is translated once a space is identified or if the sentence has ended.
    startWordpos is increased by the index i + 1 everytime a space is reached in order to place startWordPos at the start of the next word
    Returns a string of the translated sentence.

*/
string Translator::translateEnglishSentence(string englishSentence){
    int startWordPos = 0;                   // Keep track of the start of the next word to be translated
    string translatedEnglishSentence = "";
    for(int i = 0; i <= englishSentence.length(); ++i){
        if(englishSentence[i] == ' ' || i == englishSentence.length()){ // If index is a space or end of sentence:
            string englishWord = getWord(englishSentence, i, startWordPos); // Get the word from the startingWordPos indexx to curent index (i).
            string translatedWord = translateEnglishWord(englishWord); // Translate the word
            translatedEnglishSentence += translatedWord + ' '; // Add translated word to sentence
            startWordPos = i + 1;                           // Increase startWordPos to one index past the space to get first index of next word.
        }
    }

    return translatedEnglishSentence;
}

/*
    Returns the string of a word in a sentence between startWordPos and index - 1 using substr method.
    Index is subtracted by 1 because index is currently on a space character.
*/
string Translator::getWord(string englishSentence, int index, int startWordPos){
    string englishWord = englishSentence.substr(startWordPos, index - startWordPos); 
    return englishWord;
}

/*
    Returns the character in a word at a position. 
*/
char Translator::getChar(string englishWord, int index){
    return englishWord[index]; 
}

/*
    Returns true if character is a letter, false if not. 
*/
bool Translator::isLetter(char character){
    if(isalpha(character)){
        return true;
    }
    else{
        return false;
    }
}

/*
    Returns true if character is a consonant, false if a vowel.
*/
bool Translator::isConsonant(char character){
    character = tolower(character);
    if(character != 'a' && character != 'e' && character != 'i' && character != 'o' && character != 'u'){
        return true;
    }
    else{
        return false;
    }
}