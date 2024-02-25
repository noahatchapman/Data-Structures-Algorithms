#include "Model.h"
#include <cctype>

/*
    Default constructor
*/
Model::Model(){
}
/*
    Destructor
*/
Model::~Model(){
    cout << "Calling Model destructor" << endl;
}

/*
    Returns a consonant as a string translated into Robber Language. 
    Consonant is first turned into a string 
    Then, the consonant is repeated with an o between.
*/
string Model::translateSingleConsonant(char consonant){ 
    string modelConsonant = "";
    string consonantAsString = string(1, consonant); // Turn character consonant into string
    char consonantLowerCase = tolower(consonant); // Turn character consonant to lowercase and then into a string so second character isn't uppercase
    string lowerConsonantAsString = string(1, consonantLowerCase);

    modelConsonant = consonantAsString + 'o' + consonantLowerCase;
    return modelConsonant;
}

/*
    Returns a vowel as a string translated into Robber Language.
    All vowels are kept the same from English to Robber Language,
    so vowel is converted to string before returning.
*/
string Model::translateSingleVowel(char vowel){
    return string(1, vowel);
}

