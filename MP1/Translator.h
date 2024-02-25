#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include<iostream>
#include<string>
#include "Model.h"
using namespace std;

class Translator{
    public:
        Translator();
        ~Translator();
        string translateEnglishWord(string englishWord);
        string translateEnglishSentence(string englishSentence);


    private:
        char getChar(string englishWord, int index);
        string getWord(string englishSentence, int index, int startWordPos);
        bool isLetter(char character);
        bool isConsonant(char character);
        Model* myModel;
};

#endif
