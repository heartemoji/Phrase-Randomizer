/*
    Tom Amaral
    1/31/2018
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;


vector<string> directInput();
vector<string> fromFile();
void save(vector<string> lines);

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

    random_shuffle(lines.begin(), lines.end());

    for(string l : lines){
        cout << l << endl;
    }

    cout << endl;
    string answer;
    cout << "Would you like to save this result? (y/n): ";
    cin >> answer;
    
    if(answer == "y")
        save(lines);
    

    cout << "Have a nice day!" << endl;

    return 0;
}

vector<string> directInput(){
    vector<string> lines;

    string line;

    cout << "Enter some lines! ('Q' when finished!)" << endl;

    while(getline(cin, line) && line != "Q"){
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
    
    ifstream infile(filePath);

    if(infile.fail()){
        cout << "File not found: " << filePath;
        return lines;
    }

    while(getline(infile, line)){
        cout << line << endl;
        lines.push_back(line);
    }
    
    infile.close();

    return lines;
    
}

void save(vector<string> lines){

    cout << "Enter a name for the file: ";
    string name;
    cin >> name;
    
    ofstream linesOut(name);

    for(string line : lines){
        linesOut << line << endl;
    }

    linesOut.close();
}