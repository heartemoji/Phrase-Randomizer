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
    
    char selection;
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

    random_shuffle(lines.begin(), lines.end());

    cout << '\n';

    for(string l : lines){
        cout << l << '\n';
    }
}

void fromFile(){}