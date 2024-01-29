#include<iostream>
#include<queue>
#include<algorithm>
#include<unordered_map>
#include<list>
#include<set>
using namespace std;

class graph{
    public:
    vector <int> vertices;
    unordered_map<int , set<int>> adjList;
    // set and list both can be used in representation of adj list 
    // but set stores the elements in increasing sorted. 

     void addedge(int u , int v , bool direction ){
        // v=-1 that means u is a isolated node in (un)directed graph or a node in connected directed graph which is not directed to any other node
        if(v != -1){
            adjList[u].insert(v);

            if(direction == 0){
            adjList[v].insert(u);
            }
            if(!isVertexInList(u)){
            vertices.push_back(u);
        }
            if(!isVertexInList(v)){
            vertices.push_back(v);
            }
        }
        else{
            adjList[u];
            if(!isVertexInList(u)){
            vertices.push_back(u);
        }
        } 
        
    }

    bool isVertexInList(int v) {
        auto it = find(vertices.begin(), vertices.end(), v);
        return it != vertices.end();
    }

     void print_adjL(){
        for(auto i : adjList){
            cout<< i.first << " -> ";
            for(auto j : i.second){
                cout<< j << " ";
            }
            cout << endl;
        }
    }

    void DFS(int vertex , unordered_map<int , bool> & visited){
        if(!visited[vertex]){
            cout<< vertex << " ";
            visited[vertex] = true;
        }

        for(auto i : adjList[vertex]){
            if(!visited[i]){
                DFS(i,visited);
            }
        }
        
    }


}
;

int main() {
      graph g;

    g.addedge(0,2,0);
    g.addedge(1,2,0);
    g.addedge(1,3,0);
    g.addedge(1,4,0);
    g.addedge(3,2,0);
    g.addedge(3,4,0);
    g.addedge(3,5,0);
    

    unordered_map<int , bool > vist;
    for( int i=0; i < g.vertices.size();i++){
        vist[g.vertices[i]] = false;
    }

    g.DFS(0,vist);
    

    return 0;
}