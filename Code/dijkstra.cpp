#include<bits/stdc++.h>
using namespace std;

// Go from source to every other node with minimum cost

int main()
{

    cout<<"Enter number of vertices and edges : ";
    int n , e;
    cin>>n>>e;

    vector< vector< pair<int,int> >>adj(n+1);
    for(int i=0;i<e;i++)
    {
        cout<<"Enter edge and weight: ";
        int u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    vector<int>dis(n+1,1e9);
    int src = 1;
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;

    dis[src] = 0;
    pq.push({0,src}); // dis src

    while(!pq.empty())
    {
        int dist = pq.top().first;
        int prev = pq.top().second;

        pq.pop();

        for(auto it:adj[prev])
        {
            int next = it.first;
            int nextDis = it.second;

            if(dis[next] > dis[prev] + nextDis)
            {
                dis[next] = dis[prev] + nextDis;
                pq.push({dis[next],next});
            }
        }
    }

    for(auto it:dis)
        cout<<it<<" ";

}