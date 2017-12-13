#include <bits/stdc++.h>
const int yes=1;

using namespace std;

int vertex, edge, j, k;

struct node{
    int visit, connect[100];
    string food;
}G[100];

stack<node> s;

void DFS(node& v){
    v.visit = yes;
    for(int i=1; i<=vertex; i++){
        if(v.connect[i] == yes && G[i].visit != yes){
            DFS(G[i]);
        }
    }
    s.push(v);
}

void DFS_Util(){
    for(int i=1; i<=vertex; i++){
        if(G[i].visit != yes){
            DFS(G[i]);
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
        G[j].connect[k] = yes;
    }

    DFS_Util();

    while(!s.empty()){
        cout << s.top().food << " -> ";
        s.pop();
    }
    return 0;
}
