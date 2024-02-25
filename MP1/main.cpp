#include "Model.h"
#include "Translator.h"
#include "FileProcessor.h"

/*
    Creates a pointer to a new FileProcessor object. Then, processFile is called which takes original.txt and translates
    the content into Robber Language and outputs to an HTML file translated.html. 
*/
int main(){
    FileProcessor* myFileProcessor = new FileProcessor();
    myFileProcessor->processFile("original.txt", "translated.html");
    delete myFileProcessor;
    
}