/*
    Tom Amaral
    1/31/2018
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void directInput();
void fromFile();


int main(){

    cout << "Phrase Randomizer" << endl;
    cout << "Make a selection: " << endl;
    cout << "1. Direct Console Input" << endl;
    cout << "2. Read from a file" << endl;
    cout << ">>:";
    
    int selection;
    cin >> selection;

    switch(selection){
        case 1:
            directInput();
            break;

        case 2:
            break;

        default:
            cout << "Please enter a valid selection";
            break;
    }
    

    return 0;
}

void directInput(){
    vector<string> lines;

    string line;

    cout << "Enter some lines! (Ctrl-D to quit)" << '\n';

    while(getline(cin, line)){
        lines.push_back(line);
    }
    
    cout << endl;

    random_shuffle(lines.begin() + 1, lines.end());

    for(string l : lines){
        cout << l << '\n';
    }
}

void fromFile(){}