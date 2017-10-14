#include <bits/stdc++.h>
const int yes=1;

using namespace std;

int vertex, edge, j, k, connect[100][100], coun=0;
stack<int> s;

struct node{
    int visit;
    string food;
}G[100];

void DFS(int v){
    G[v].visit = yes;
    for(int i=1; i<=vertex; i++){
        if(connect[v][i] == yes && G[i].visit != yes){
            DFS(i);
        }
    }
    s.push(v);
}

void DFS_util(){
    for(int i=1; i<=vertex; i++){
        if(G[i].visit != yes){
            DFS(i);
        }
    }
}

int main()
{
    ifstream infile;
    infile.open("input.txt");
    infile >> vertex >> edge;

    string foods[] = {"Rice", "Fish", "Lenthis", "Meat", "Vegetables", "Desert", "Water"};

    for(int i=0; i<vertex; i++){
        G[i+1].food = foods[i];
    }


    for(int i=0; i<edge; i++){
        infile >> j >> k;
        connect[j][k] = yes;
    }

    DFS_util();

    while(!s.empty()){
        cout << G[s.top()].food << " -> ";
        s.pop();
    }
    return 0;
}
