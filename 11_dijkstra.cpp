#include <iostream>
#include <unordered_map>
#include <set>
#include <list>
#include <utility>
#include <vector>
#include <climits>
using namespace std;

class graph
{
    unordered_map<int, list<pair<int, int>>> adjlist; // its a weighted undirectional graph ex: u --> (v,w)
    int edges;
    int vert;

public:
    graph(int e, int v)
    {
        edges = e;
        vert = v;
    }
    void addedge(int u, int v, int w)
    {
        adjlist[u].push_back(make_pair(v, w));
        adjlist[v].push_back(make_pair(u, w));
    }

    void display()
    {
        for (auto i : adjlist)
        {
            cout << i.first << "--> ";
            for (auto j : adjlist[i.first])
            {
                cout << j.first << " " << j.second << "(w)  ";
            }
            cout << endl;
        }
    }

    unordered_map<int, int> dijkstra(int source)
    {
        unordered_map<int, int> dist(vert);
        for (auto i : adjlist)
        {
            dist[i.first] = INT_MAX;
        }
        dist[source] = 0;
        set<pair<int, int>> st; // pair --> (weight , vert)
        st.insert(make_pair(0, source));
        while (!st.empty())
        {
            auto top = *(st.begin());
            int topnode = top.second;
            st.erase(st.begin());

            for (auto i : adjlist[topnode])
            {
                if (dist[topnode] + i.second < dist[i.first])
                {
                    // i.second represnts weight between the top and i.first
                    auto record = st.find(make_pair(dist[i.first], i.first));
                    if (record != st.end())
                    { // indicates there already exists a pair with same node with different distance
                        st.erase(record);
                    }
                    dist[i.first] = dist[topnode] + i.second;
                    st.insert(make_pair(dist[i.first], i.first));
                }
            }
        }

        return dist;
    }
};

int main()
{
    graph g1(7, 5);
    // g1.addedge(0,1,3);
    // g1.addedge(0,2,5);
    // g1.addedge(0,3,4);
    // g1.addedge(1,3,2);
    // g1.addedge(2,3,3);
    g1.addedge(0, 1, 7);
    g1.addedge(0, 2, 1);
    g1.addedge(0, 3, 2);
    g1.addedge(1, 2, 3);
    g1.addedge(1, 3, 5);
    g1.addedge(1, 4, 1);
    g1.addedge(3, 8, 7);

    // g1.display();
    unordered_map<int, int> v = g1.dijkstra(0);
    cout << "nodes : ";
    for (auto i : v)
    {
        cout << i.first << " ";
    }
    cout << endl;
    cout << "dists : ";
    for (auto i : v)
    {
        cout << i.second << " ";
    }

    return 0;
}