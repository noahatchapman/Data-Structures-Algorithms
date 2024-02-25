#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H
#include "Translator.h"

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class FileProcessor{
    public:
        FileProcessor();
        ~FileProcessor();
        void processFile(string inputFile, string outputFile);
    private:
        Translator* myTranslator;
        void startHTML(ofstream& outFile);
        void outputEnglish(ofstream& outfile, ifstream& infile);
        void outputTranslate(ofstream& outfile, ifstream& infile);
};
    
#endif