/*
    Tom Amaral
    1/31/2018
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main(){

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

    return 0;
}