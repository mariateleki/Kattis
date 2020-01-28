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
#include <queue>
#include <stack>

using namespace std;

int main(){
    //ifstream cin; cin.open("guessthedatastructure_sample.in");
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n = -1;
    cin >> n;
    //for each test case
    while(!cin.eof()){
        //cout << "n: " << n << endl;
        
        stack<int> stack;
        queue<int> queue;
        priority_queue<int> pqueue;
        
        bool couldBeStack = true;
        bool couldBeQueue = true;
        bool couldBePqueue = true;
        
        //do things with each element
        for(int i = 0; i < n; i++){
            //cout << "i = " << i << endl;
            
            int command = -1; cin >> command; //cout << "command: " << command << "\t";
            int element = -1; cin >> element; //cout << "element: " << element << endl;
            
            if(command == 1){
                stack.push(element);
                queue.push(element);
                pqueue.push(element);
                
            }else if(command == 2){
                //2 things that can cause it to not be a stack, queue, pqueue: 1- we try to take it out and it's not the right thing (which also covers if we try to take out something that's not in there), 2-there's nothing to take out **actually have to do empty() before top() or erros
                
                if(couldBeStack == true){
                    if(stack.empty() == true){couldBeStack = false;}
                    else if(stack.top() != element){couldBeStack = false;}
                    else{stack.pop();}
                }
                if(couldBeQueue == true){
                    if(queue.empty() == true){couldBeQueue = false;}
                    else if(queue.front() != element){couldBeQueue = false;}
                    else{queue.pop();}
                }
                if(couldBePqueue == true){
                    if(pqueue.empty() == true){couldBePqueue = false;}
                    else if(pqueue.top() != element){couldBePqueue = false;}
                    else{pqueue.pop();}
                }
            }
        } //end for
        
        //cout << "couldBeStack = " << couldBeStack << "\n";
        //cout << "couldBeQueue = " << couldBeQueue << "\n";
        //cout << "couldBePqueue = " << couldBePqueue << "\n";
        
        if((couldBeStack == true) && (couldBeQueue == false) && (couldBePqueue == false)){
            cout << "stack" << endl;
        }
        else if((couldBeStack == false) && (couldBeQueue == true) && (couldBePqueue == false)){
            cout << "queue" << endl;
        }
        else if((couldBeStack == false) && (couldBeQueue == false) && (couldBePqueue == true)){
            cout << "priority queue" << endl;
        }
        else if(((couldBeStack == true) && (couldBeQueue == true) && (couldBePqueue == true))
                || ((couldBeStack == true) && (couldBeQueue == true) && (couldBePqueue == false))
                || ((couldBeStack == true) && (couldBeQueue == false) && (couldBePqueue == true))
                || ((couldBeStack == false) && (couldBeQueue == true) && (couldBePqueue == true))){
            cout << "not sure" << endl;
        }
        else if((couldBeStack == false) && (couldBeQueue == false) && (couldBePqueue == false)){
            cout << "impossible" << endl;
        }
        
        //clear these guys out before the next test case
        while(!stack.empty()){stack.pop();}
        while(!queue.empty()){queue.pop();}
        while(!pqueue.empty()){pqueue.pop();}
        
        //if we're at EOF we'll exit the while loop and end the program
        cin >> n;
    } //end while
    
    return 0;
}


