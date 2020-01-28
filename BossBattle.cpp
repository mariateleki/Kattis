//
//  main.cpp
//  CSCE489
//
//  Created by Maria Teleki on 1/15/19.
//  Copyright © 2019 Maria Teleki. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;


int main(){
    //ifstream cin; cin.open("ants.in");
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int a = -1; cin >> a;
    if(a == 1 || a == 2){
        cout << "1" << endl;
    }else{
        cout << a-2 << endl;
        
    }
    
    
    return 0;
}





