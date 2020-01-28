//
//  main.cpp
//  ProblemSet0
//
//  Created by Maria Teleki on 1/15/19.
//  Copyright © 2019 Maria Teleki. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    int numberOfContestants = -1; // 1 <= N
    int numberOfHufflepuffProblems = -1; // P <= 1000
    cin >> numberOfContestants;
    cin >> numberOfHufflepuffProblems;
    
    string ignore = "";
    for(int i = 0; i < numberOfContestants; ++i){
        cin >> ignore;
    }
    
    cout << numberOfHufflepuffProblems; // because numberOfHugglepuffProblems = numberOfCarrot
    return 0;
}
