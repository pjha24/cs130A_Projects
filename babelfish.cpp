//Paritosh Jha
//CS 130A - Babelfish- Kattis- project 2
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
using namespace std;

int main(){
    string name, name2;
    vector<vector<pair<string, string> > > m(200000);

    while (true){
        getline (cin,name);
        if (name.empty()){
            //cout<< "its empty" <<endl;
            break;
        }
        stringstream ss(name);
        string names[2];
        ss >> names[0] >> names[1];

        // cout <<"x: " << names[0] << " y: " << names[1] <<endl;
        
        m[hash<string>()(names[1]) % 200000].push_back(make_pair(names[0], names[1]));

    }

    // for (int i = 0; i < m.size(); i++) {
    //     cout<< "in " << i << " th vector" <<endl;
    //     for (int j = 0; j < m[i].size(); j++) {
    //         cout<<"index: "<< j << " " << m[i][j].first << " " << m[i][j].second <<endl;
    //     }
    // }

    bool found;
    vector<string> answer;
    while(true){

        getline(cin, name2);
        if (name2.empty()) {
            break;
        }
        found = false;
        int y = hash<string>()(name2) % 200000;
        for (int i = 0; i < m[y].size(); i++) {
            if (m[y][i].second == name2) {
                found = true;
                answer.push_back(m[y][i].first);
                //cout << m[y][i].first;
                break;
            }    
        }
        if (!found){
            answer.push_back("eh");
            //cout<< "eh";
        }
    }
    //cout <<answer.size()<<endl;
    for(int i = 0; i <answer.size(); i++){
        cout << answer[i] << endl;
    }
    

    
//    // y = hash(names[1])
//     //m[hash].push

//     m[0].push_back(make_pair("dog","ogday"));
//     m[1].push_back(make_pair("cat","atcay"));
//     m[2].push_back(make_pair("pig","igpay"));
//     m[3].push_back(make_pair("froot","ootfray"));
//     m[4].push_back(make_pair("loops","oopslay"));

//     m[0].push_back(make_pair("fox", "foxy"));


//     int y = hash<string>()("ogday") % 200000;
//     cout << y << endl;

/* 

    General Algorithm: 
    string x, y;
    cin >> x >> y;

    hash(y); //get a value 

    //create a vector of vectors of pairs<string,string>

    go to hash(y) and store pair<x,y>;

    //iterate through all key / value pairs
    

    //hash the given string, go to that hash(string) vector index, iterate through pairs 
    */


    return 0;
}