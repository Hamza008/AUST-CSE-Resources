#include <bits/stdc++.h>
const int yes = 1, no = 0;

using namespace std;

int vertex, edge, j, k, coun=0;

struct node
{
    int visit;
} G[100];

void DFS(int v, int c[][100], stack<int>& s, queue<int>& q)
{
    q.push(v);
    G[v].visit = yes;
    for(int i=1; i<=vertex; i++)
    {
        if(c[v][i] == yes && G[i].visit != yes)
        {
            DFS(i, c, s, q);
        }
    }
    s.push(v);
}

void DFS_util(int c[][100], stack<int>& s, queue<int>& q)
{
    for(int i=1; i<=vertex; i++)
    {
        if(G[i].visit != yes)
        {
            DFS(i, c, s, q);
        }
    }
}

void visitFalse()
{
    for(int i=1; i<=vertex; i++)
    {
        G[i].visit = no;
    }
}

int main()
{
    ifstream infile;
    infile.open("input.txt");
    infile >> vertex >> edge;

    int connect[100][100], reConnect[100][100];
    stack<int> s1, s2;
    queue<int> q1, q2;

    for(int i=0; i<edge; i++)
    {
        infile >> j >> k;
        connect[j][k] = yes;
        reConnect[k][j] = yes;
    }

    DFS_util(connect, s1, q1);

    visitFalse();

    int i;
    while(!s1.empty())
    {
        i=s1.top();
        if(G[i].visit != yes)
        {
            DFS(i, reConnect, s2, q2);
            cout << "\nComponents: ";
            while(!q2.empty())
            {
                cout << q2.front() << " ";
                q2.pop();
            }
        }

        s1.pop();
    }
    return 0;
}
