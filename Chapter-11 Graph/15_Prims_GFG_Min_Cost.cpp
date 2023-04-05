#include <bits/stdc++.h>
using namespace std;

//Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int N, vector<vector<int>> adj[])
{
    int parent[N + 1];

    int key[N + 1];

    bool mstSet[N + 1];

    for (int i = 0; i <= N; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    parent[0] = -1;
    pq.push({0, 0});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        mstSet[u] = true;

        for (auto it : adj[u])
        {
            int v = it[0];
            int weight = it[1];
            if (mstSet[v] == false && weight < key[v])
            {
                parent[v] = u;
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        if (key[i] != INT_MAX)
            sum += key[i];
    }
    return sum;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);

            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        cout << spanningTree(V, adj) << "\n";
    }

    return 0;
}

/*
I/p ->
1   
3 3
0 2 1
0 1 5
1 2 3

O/p -> 4

*/