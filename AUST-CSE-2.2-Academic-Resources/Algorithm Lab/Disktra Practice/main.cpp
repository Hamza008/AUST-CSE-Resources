#include <bits/stdc++.h>
const int no = -1, inf = 9999;
int vertex, edge;
using namespace std;

struct node
{
    int cost = inf;
    int connect[100];
    node()
    {
        fill_n(connect, 100, no);
    }
} Graph[100];

class cmp
{
public:
    bool operator()(node &a, node &b)
    {
        return a.cost < b.cost;
    }
};

priority_queue<node, vector<node>, cmp > q;

void Dijkstra(node &source, node &destination)
{
    for(int i=1; i<=vertex; i++)
    {
        if(source.connect[i]!=no)
        {
            if(Graph[i].cost > (source.cost + source.connect[i]))
            {
                Graph[i].cost = source.cost + source.connect[i];
                q.push(Graph[i]);
            }
        }
    }
    node n = q.top();
    q.pop();
    if(n != destination)
    {
        Dijkstra(n, destination);
    }
}

int main()
{
    ifstream infile;
    infile.open("input.txt");
    int j, k, m;
    infile >> vertex >> edge;

    for(int i=0; i<edge; i++)
    {
        infile >> j >> k >> m;
        Graph[j].connect[k] = m;
    }

    Graph[1].cost = 0;
    Dijkstra(Graph[1], Graph[8]);
    cout << Graph[8].cost;
    return 0;
}
