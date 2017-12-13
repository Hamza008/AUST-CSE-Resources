#include <bits/stdc++.h>

using namespace std;

struct node{
    int age;
};

class cmp{
    public:
    bool operator()(node const & a, node const & b){
        return a.age < b.age;
    }
};

int main()
{
    priority_queue<node, vector<node>, cmp > q;

    q.push({2});
    q.push({5});
    q.push({3});
    q.push({6});
    q.push({4});

    while(!q.empty()){
        cout << q.top().age << "\t";
        q.pop();
    }
    return 0;
}
