#include <bits/stdc++.h>

using namespace std;

struct node{
    int cost;
};

class cmp{
    public:
    bool operator () (node &A, node &B){
        return A.cost > B.cost;
    }
};

int main()
{
    priority_queue <node, vector<node>, cmp > q;
    q.push({1, 10});
    q.push({2, 20});
    q.push({3, 15});

    cout << q.top().cost;
    return 0;
}
