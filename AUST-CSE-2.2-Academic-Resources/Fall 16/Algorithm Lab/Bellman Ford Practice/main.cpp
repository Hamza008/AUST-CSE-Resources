#include <bits/stdc++.h>
using namespace std;

int vertex, edge;
const int inf = 9999;

struct node
{
    int cost, parent, weight[100];
    bool isConnected[100];
    node()
    {
        cost=inf;
        parent=-1;
    }
} G[100];

bool BellmanFord()
{
    int value;
    bool isValueChanged;
    for(int i=1; i<=vertex; i++)
    {
        isValueChanged = false;
        for(int j=1; j<=vertex; j++)
        {
            for(int k=1; k<=vertex; k++)
            {
                if(G[j].isConnected[k]==true)
                {
                    value=G[j].cost + G[j].weight[k];
                    if(G[k].cost>value)
                    {
                        if(i==vertex)
                        {
                            return false;
                        }
                        else
                        {
                            G[k].cost=value;
                            G[k].parent=j;
                            isValueChanged=true;
                        }
                    }
                }
            }
        }
        if(isValueChanged==false)
        {
            return true;
        }
    }
    return true;
}

int main()
{
    ifstream infile;
    infile.open("input.txt");
    infile >> vertex >> edge;

    int j, k, m;
    for(int i=1; i<=edge; i++)
    {
        infile >> j >> k >> m;
        G[j].isConnected[k]=true;
        G[j].weight[k]=m;
    }

    cout << "Source : ";
    int s, d;
    cin >> s;
    cout << "Destination : ";
    cin >> d;

    G[s].cost=0;
    if(BellmanFord()==true)
    {
        cout << "\nCost : " << G[d].cost;
        cout << "\nPath : ";
        int i=d;
        stack<int> stk;
        while(i!=-1){
            stk.push(i);
            i=G[i].parent;
        }
        while(!stk.empty()){
            cout << stk.top() << "->";
            stk.pop();
        }
    }else{
        cout << "Negetive Cycle";
    }

    return 0;
}
