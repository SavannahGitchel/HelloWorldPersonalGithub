#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

void openFileIn(ifstream&, string);
void openFileOut(ofstream&, string);
void processFileM(ifstream&, string);
void processFileT(ifstream&, string);

int main(){
	cout << "Command>";
	string conversion;
	string fileIn;
	string fileOut;
	cin >> conversion;
	cin >> fileIn;
	cin >> fileOut;

    //open the in file
    cout << "Attempting to open: " << fileIn << endl;
    ifstream inFile;
    openFileIn(inFile, fileIn);
    //process file
    if (conversion == "-m"){
    processFileM(inFile, fileOut);
    } else{
    processFileT(inFile, fileOut);
    }
    //close files
    inFile.close();

    
    
    return 0;
}

void openFileIn(ifstream& inFile, string fname){
inFile.open(fname);
if (inFile.is_open()){
    cout << "Successfully opened file" << endl;
}
else {
    cout << "Failed to open file" << endl;
    exit(-1);
}
}
void openFileOut(ofstream& outFile, string fname){
outFile.open(fname);
if (outFile.is_open()){
    cout << "Successfully opened file" << endl;
}
else {
    cout << "Failed to open file" << endl;
    exit(-1);
}
}


void processFileM(ifstream& inFile, string fileOut){
    ofstream outFile;
    cout << "Attempting to open: " << fileOut << endl;
    openFileOut(outFile, fileOut);
    string line;
    char currentChar;
    int charValue;
    int numCharacters = 0;

	
    string morseStrings[91];
    morseStrings['A'] = ".-";
    morseStrings['B'] = "-...";
	morseStrings['C'] = "-.-.";
	morseStrings['D'] = "-..";
	morseStrings['E'] = ".";
	morseStrings['F'] = "..-.";
	morseStrings['G'] = "--.";
	morseStrings['H'] = "....";
	morseStrings['I'] = "..";
	morseStrings['J'] = ".---";
	morseStrings['K'] = "-.-";
	morseStrings['L'] = ".-..";
	morseStrings['M'] = "--";
	morseStrings['N'] = "-.";
	morseStrings['O'] = "---";
	morseStrings['P'] = ".--.";
	morseStrings['Q'] = "--.-";
	morseStrings['R'] = ".-.";
	morseStrings['S'] = "...";
	morseStrings['T'] = "-";
	morseStrings['U'] = "..-";
	morseStrings['V'] = "...-";
	morseStrings['W'] = ".--";
	morseStrings['X'] = "-..-";
	morseStrings['Y'] = "-.--";
	morseStrings['Z'] = "--..";
	morseStrings['1'] = ".----";
	morseStrings['2'] = "..---";
	morseStrings['3'] = "...--";
	morseStrings['4'] = "....-";
	morseStrings['5'] = ".....";
	morseStrings['6'] = "-....";
	morseStrings['7'] = "--...";
	morseStrings['8'] = "---..";
	morseStrings['9'] = "----.";
	morseStrings['0'] = "-----";
	
    while(!inFile.eof()){
        //read line by line
 
    	getline(inFile, line);
    	if (inFile.good()){
    		for (int j = 0; j < line.size(); j++){
    			if (line[j] == ' '){
    				outFile << " ";
    			} else{
    			currentChar = line[j];
            		//cout << currentChar << endl;
            		charValue = currentChar;
            			if ((charValue > 96) && (charValue < 123)){
            				charValue -= 32;
            				}
           	 				//for (char c : word) {
     	  	 				//cout << c << endl;
       		 				//}
            			numCharacters++;
            			outFile << morseStrings[charValue];
            			outFile << " ";
    			}
    			}
    		outFile << "\n";
    	}

    	}
		
	outFile.close();
    cout << "Total characters converted successfully: " << numCharacters << endl;
    exit(-1);
	}

void processFileT(ifstream& inFile, string fileOut){
    ofstream outFile;
    cout << "Attempting to open: " << fileOut << endl;
    openFileOut(outFile, fileOut);
    string line;
    string letter;
	int numCharacters = 0;
	int asciiNum = 0;
	int letterComplete = 0;
	
	string morseStrings[91];
	morseStrings['A'] = ".-";
    morseStrings['B'] = "-...";
	morseStrings['C'] = "-.-.";
	morseStrings['D'] = "-..";
	morseStrings['E'] = ".";
	morseStrings['F'] = "..-.";
	morseStrings['G'] = "--.";
	morseStrings['H'] = "....";
	morseStrings['I'] = "..";
	morseStrings['J'] = ".---";
	morseStrings['K'] = "-.-";
	morseStrings['L'] = ".-..";
	morseStrings['M'] = "--";
	morseStrings['N'] = "-.";
	morseStrings['O'] = "---";
	morseStrings['P'] = ".--.";
	morseStrings['Q'] = "--.-";
	morseStrings['R'] = ".-.";
	morseStrings['S'] = "...";
	morseStrings['T'] = "-";
	morseStrings['U'] = "..-";
	morseStrings['V'] = "...-";
	morseStrings['W'] = ".--";
	morseStrings['X'] = "-..-";
	morseStrings['Y'] = "-.--";
	morseStrings['Z'] = "--..";
	morseStrings['1'] = ".----";
	morseStrings['2'] = "..---";
	morseStrings['3'] = "...--";
	morseStrings['4'] = "....-";
	morseStrings['5'] = ".....";
	morseStrings['6'] = "-....";
	morseStrings['7'] = "--...";
	morseStrings['8'] = "---..";
	morseStrings['9'] = "----.";
	morseStrings['0'] = "-----";
	
    while(!inFile.eof()){

		//read line by line
    	getline(inFile, line);
    	if (inFile.good()){

            	//read each character in the string line that was acquired from getline
            	for (int j = 0; j < line.size(); j++) {//THIS MIGHT BE THE PROBLEM
            	//if you hit a space
            	if (line[j] == ' '){
            			//if the prior character was not a space, update letterComplete
            			if (letterComplete == 0){
            				for (int i = 0; i<91; i++){
            					if (morseStrings[i] == letter){
            						asciiNum = i;
            						numCharacters++;
            						outFile << char(asciiNum);
            						letter = "";
            						letterComplete = 0;
            						}
            				letterComplete = 1;
            			} 
            			}
            			//if prior character was a space, that means there were two spaces
            			//put a space between words
            			else if (letterComplete == 1){
            				outFile << " ";
            				letterComplete = 0;
            			}
            		} 
            		//if you hit a - or .
     	  	 		else if (line[j] == '-' || line[j] == '.'){
     	  	 			letterComplete = 0;
     	  	 			letter += line[j];
     	  	 			}  
     	  	 		}
     	  	 	outFile << "\n";
            	}
    	}
  
    outFile.close();
    cout << "Total characters converted successfully: " << numCharacters << endl;
    exit(-1);
	}
