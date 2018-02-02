/*
    Tom Amaral
    1/31/2018
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>

using namespace std;


vector<string> directInput();
vector<string> fromFile();


int main(){

    cout << "Phrase Randomizer" << endl;
    cout << "Make a selection: " << endl;
    cout << "1. Direct Console Input" << endl;
    cout << "2. Read from a file" << endl;
    cout << ">>:";
    
    int selection;
    cin >> selection;

    vector<string> lines;

    switch(selection){
        case 1:
            lines = directInput();
            break;

        case 2:
            lines = fromFile();
            break;

        default:
            cout << "Please enter a valid selection";
            return 0;
        }
        
    cout << endl;
    
    if(lines.empty())
        return 1;

    random_shuffle(lines.begin() + 1, lines.end());

    for(string l : lines){
        cout << l << endl;
    }

    
        


    return 0;
}

vector<string> directInput(){
    vector<string> lines;

    string line;

    cout << "Enter some lines! (Ctrl-D to quit)" << endl;

    while(getline(cin, line)){
        lines.push_back(line);
    }
    
    return lines;
    
}

vector<string> fromFile(){

    cout << "Enter path to file: ";
    string filePath;
    cin >> filePath;

    vector<string> lines;
    string line;
    
    fstream infile(filePath, fstream::in);

    if(infile.fail()){
        cout << "File not found: " << filePath;
        return lines;
    }

    while(getline(infile, line)){
        lines.push_back(line);
    }
    
    infile.close();

    return lines;
    
}