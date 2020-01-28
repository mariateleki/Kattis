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

using namespace std;

class unionFind{ //just going to use path compression for this union find, number of friends works similarly but not the same, so just going to go ahead and sub that in
private:
    vector<int> parent;
    //vector<int> depth;
    vector <int> nOfFriends;
public:
    unionFind(int nOfDisjointSets){
        parent = vector<int>(nOfDisjointSets,-1);
        //depth = vector<int>(nOfDisjointSets,0);
        nOfFriends = vector<int>(nOfDisjointSets,1);
        for(int i = 0; i < nOfDisjointSets; i++){parent[i] = i;}
    }
    
    int find(int i){
        if(parent[i] == i){return i;}
        else{
            return parent[i] = find(parent[i]);
        }
    }
    
    void unionSets(int a, int b){ //so now union works based on number of friends rather than depth, although depth did update more efficiently
        
        int fa = find(a);
        int fb = find(b);
        
        if(fa==fb) return;
        
        /*
        if(depth[fa] < depth[fb]){
            parent[fa] = fb;
            
            
        }else if(depth[fa] > depth[fb]){
            parent[fb] = fa;
            
        }else {
            parent[fa] = fb;
            depth[fb]++;
        }
         */
        
        if(nOfFriends.at(fa) >= nOfFriends.at(fb)){ //= doesn't matter, could join either way
            parent.at(fb) = fa;
            nOfFriends.at(fa) += nOfFriends.at(fb);
            //nOfFriends.at(fb) = nOfFriends.at(fa);
            
        }else{
            parent.at(fa) = fb;
            nOfFriends.at(fb) += nOfFriends.at(fa);
            //nOfFriends.at(fa) = nOfFriends.at(fb);
        }
        
        
        
    }
    
    bool inSameSet(int a, int b){return find(a) == find(b);}
    
    int getNOfFriends(int a) {
        
        return nOfFriends.at(a);
    }
};


int main(){
    //ifstream cin; cin.open("virtualfriends-1.in");
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    //number of test cases
    int testCases = -1; cin >> testCases;
    for(int t = 0; t < testCases; t++){
        
        int nOfFriendships = -1; cin >> nOfFriendships;
        unionFind uf (nOfFriendships+1);
        
        //map stuff so each name can get unique hash, check if
        map<string, int> namesToSets;
        
        for(int f = 0; f < nOfFriendships; f++){
            
            string friend1 = ""; cin >> friend1;
            string friend2 = ""; cin >> friend2;
            
            if(namesToSets.count(friend1) == 0){ //if friend1 is not in the map
                namesToSets[friend1] = int(namesToSets.size()); //then assign friend1 a set number
                //don't need to +-1 bc size goes 0, 1, 2,
            }
            if(namesToSets.count(friend2) == 0){ //if friend2 is not in the map
                namesToSets[friend2] = int(namesToSets.size()); //then assign friend2 a set number
                //don't need to +-1 bc size goes 0, 1, 2,
            }
            
            int friend1SetNumber = namesToSets[friend1];
            int friend2SetNumber = namesToSets[friend2];
            
            uf.unionSets(friend1SetNumber, friend2SetNumber); //join sets
            
            
            
            cout << uf.getNOfFriends(uf.find(friend1SetNumber)) << endl; //parent keeps track of number of friends (size of set)
            //need the find() bc only updating the root with the group's number of friends
            
            
        }//end of one friendship

        
        
    }//end of test case
    
    
    return 0;
}




