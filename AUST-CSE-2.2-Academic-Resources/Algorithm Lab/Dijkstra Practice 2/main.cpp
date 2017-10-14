#include <bits/stdc++.h>
using namespace std;

int vertex, edge;
const int inf = 9999;

struct node{
    int cost, weight[100];
    bool isConnected[100];
    node* parent;

    node(){
        cost=inf;
    }
}G[100];

class cmp{
public:
    bool operator()(const node& a, const node& b){
        return a.cost>b.cost;
    }
};

priority_queue<node, vector<node>, cmp > q;

void Dijkstra(node& source){
    for(int i=1; i<=vertex; i++){
        if(source.isConnected[i]==true && G[i].cost>(source.weight[i]+source.cost)){
            G[i].cost=source.weight[i]+source.cost;
            q.push(G[i]);
        }
    }
    if(q.empty()){
        return;
    }
    node n = q.top();
    q.pop();
    Dijkstra(n);
}

int main()
{
    ifstream infile;
    infile.open("input.txt");
    infile >> vertex >> edge;

    int j, k, m;
    for(int i=1; i<=edge; i++){
        infile >> j >> k >> m;
        G[j].isConnected[k]=true;
        G[j].weight[k]=m;
    }

    int s, d;
    cout << "Source : ";
    cin >> s;
    cout << "\nDestination : ";
    cin >> d;

    G[s].cost=0;
    Dijkstra(G[s]);

    cout << "\nCost : " << G[d].cost;



    return 0;
}
