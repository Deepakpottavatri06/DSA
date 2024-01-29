#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;


class graph{
    public:
    vector <int> vertices; // for storing the vertices - no use of this in any function for now
    unordered_map< int , list<int>> adjList;

    void addedge(int u , int v , bool direction ){
        adjList[u].push_back(v);
        if(direction == 0){
            adjList[v].push_back(u);
        }
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

};
int main() {
    cout<<"Enter no of nodes :" << endl;
    int n;
    cin >> n;
    graph g;
    cout << "Enter the nodes :"<<endl;
    for(int i = 0 ; i < n ; i++){
        int vertex;
        cin>> vertex;
         g.vertices.push_back(vertex);
    }

    cout<<"Enter no of edges : "<< endl;
    int e;
    cin>>e;
    for (int i = 0; i < e; i++)
    {   int u,v;
        cin >> u >> v;
        g.addedge(u,v,0);
    }
    
    g.print_adjL();
    

    return 0;
}