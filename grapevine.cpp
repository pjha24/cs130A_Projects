//Paritosh Jha
//CS 130A - Walking through Grapevine- Kattis- project 1
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int main(){
    int numofPeople, connections, days;
    cin >> numofPeople >> connections >> days;

    vector<int> skepticism;                                         //storing skepticism levels
    
    skepticism.assign(numofPeople,0);

    unordered_map<string, int> boxNum;                              //name = key, boxNum = i. box Num = index of skept vector
    string key;
    int skepLevel; 
    for(int i = 0; i < numofPeople; i++){
        cin >> key >> skepLevel;
        skepticism[i] = skepLevel;
        boxNum[key] = i;
    }
    /*
    cout<<"testing map key/values: " <<endl;
    for (auto x : boxNum){
        cout<< x.first << " " << x.second <<endl;
    }
    cout<<"testing skepticism vector: " <<endl;
    for(int i = 0; i < skepticism.size(); i++){
        cout<<"at index " << i <<" skepLevel is " << skepticism[i] <<endl;
    }
    */
   vector<vector<int> > adjList;
   adjList.assign(numofPeople, vector<int>());
   string name1, name2;
   for(int i = 0; i < connections; i++){
        cin >> name1 >> name2;
        adjList[boxNum[name1]].push_back(boxNum[name2]);
        adjList[boxNum[name2]].push_back(boxNum[name1]);
        //cout<< "adding " << boxNum[name2] << " to " << boxNum[name1] << " adjacency list" ;
        //cout<< "adding " << boxNum[name1] << " to " << boxNum[name2] << " adjacency list" ;
   }
    /*
   cout<<"testing adjList " <<endl;
   for(int i = 0; i < adjList.size();i++){
        cout<<"Adjacency List: " << i << endl;
        for(int j = 0; j < adjList[i].size(); j++){
            cout <<adjList[i][j] << " " ;           
        }
        cout<< endl;
   }
   */
  string originator;
  cin >> originator; 

  vector<int> heard;                                         //keep track of who has heard rumor 
  heard.assign(numofPeople,0);

  int numHeard = 0;
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > minheap;  // priority queue. Priority determined by box num
    minheap.push({0, boxNum[originator]});                                                     //need pair to be able to hold dayCount. Running BFS
    heard[boxNum[originator]] = 1;

    while (!minheap.empty()) {
        auto [dayCount, bn] = minheap.top();
        //cout<< "dayCount: " << dayCount << " and bn: " << bn << endl;
        minheap.pop();
        if (dayCount >= days) break;
        for (int x : adjList[bn]) {
            if (!heard[x]) {
                heard[x] = 1;
                numHeard++;
            }
            skepticism[x]--;
            if (skepticism[x] == 0) {
                minheap.push({dayCount + 1, x});
            }
        }
    }
    cout << numHeard << endl;

    return 0;
}