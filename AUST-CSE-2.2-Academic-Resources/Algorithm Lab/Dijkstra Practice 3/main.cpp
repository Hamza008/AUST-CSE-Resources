#include <bits/stdc++.h>
using namespace std;

int vertex, edge;
const int inf = 9999;

struct node{
    int cost, weight[100], parent;
    bool isConnected[100];

    node(){
        cost=inf;
        parent=-1;
    }
}G[100];

class cmp{
public:
    bool operator()(const int& a, const int& b){
        return G[a].cost>G[b].cost;
    }
};

priority_queue<int, vector<int>, cmp > q;

void Dijkstra(int source){
    for(int i=1; i<=vertex; i++){
        if(G[source].isConnected[i]==true && G[i].cost>(G[source].weight[i]+G[source].cost)){
            G[i].cost=G[source].weight[i]+G[source].cost;
            G[i].parent=source;
            q.push(i);
        }
    }
    if(q.empty()){
        return;
    }
    int n = q.top();
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
    Dijkstra(s);

    cout << "\nCost : " << G[d].cost;

    cout << "\nPath : ";
    int i = d;
    stack<int> stk;
    while(i!=-1){
        stk.push(i);
        i = G[i].parent;
    }
    while(!stk.empty()){
        cout << stk.top() << " -> ";
        stk.pop();
    }
    return 0;
}
