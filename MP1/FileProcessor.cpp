#include "FileProcessor.h"
#include <fstream>

/*
    Default Constructor, initilizes a Translator object
*/
FileProcessor::FileProcessor(){
    myTranslator = new Translator();
}

/*
    Destructor
*/
FileProcessor::~FileProcessor(){
    delete myTranslator;
    cout << "Calling File Processor destructor" << endl;
}

/*
    Takes in an inputFile and makes an outputFile translating the contents of the input file
    to Robber Language. Uses startHTML to outfile initial html tags, then outputEnglish 
    to outfile English portion in bold, then outputTranslate to outfile translated part in italics.
    Void return type
*/
void FileProcessor::processFile(string inputFile, string outputFile){
    ifstream infile(inputFile);
    ofstream outfile(outputFile);

    //Start HTML tags
    startHTML(outfile); // Creates initial HTML tags

    //Output English portion
    outputEnglish(outfile, infile); // Outfiles input before translation + HTML tags for bolding.

    ifstream infile2(inputFile); 

    //Output Translate
    outputTranslate(outfile, infile2); // Outfiles input after translatoin + HTML tags for italics
    }

/*
    Creates the starting HTML tags 
    Void return type
*/
void FileProcessor::startHTML(ofstream& outfile){

    if(outfile.is_open()){
        outfile << "<!DOCTYPE html>" << endl;
        outfile << "<html>" << endl;
        outfile << "<head>" << endl;
        outfile << "<title> English to Robber Translation </title>" << endl;
        outfile << "</head>" << endl;
        outfile << "<body>" << endl;
    }
}

/*
    Outfiles the input content before translation and also provides tags for bolding the words.
*/
void FileProcessor::outputEnglish(ofstream& outfile, ifstream& infile){
    string line;
    if(infile.is_open()){
        if(outfile.is_open()){
            while(getline(infile, line)){
                outfile << "<p><b>" << line << "</b><br></p>" << endl; 
            }
            outfile << "<p><b></b><br></p>" << endl;
    }
        else{
            cerr << "Error opening file." << endl;
        }

    }
    else{
        cerr << "Error opening file." << endl;
    }
}

/*
    Outfiles the content translated into Robber Language and also necessary HTML tags for italicizing the words.
*/
void FileProcessor::outputTranslate(ofstream& outfile, ifstream& infile){
    string line;
    if(infile.is_open()){
        if(outfile.is_open()){
            while(getline(infile, line)){
                outfile << "<p><i>" << myTranslator->translateEnglishSentence(line) << "</i><br></p>" << endl; 
            }
            outfile << "<p><i></i><br></p>" << endl;
    }
        else{
            cerr << "Error opening file." << endl;
        }

    }
    else{
        cerr << "Error opening file." << endl;
    }

    outfile << "<body>" << endl;
    outfile << "</html>" << endl;
}
