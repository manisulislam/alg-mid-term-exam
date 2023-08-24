#include<bits/stdc++.h>
using namespace std;

//typedef pair
typedef pair<int, int>pii;
//range
const int N= 1e3+5;

//infinity range
const int INF=1e9+5;

//distance vector
vector<int>dist(N,INF);

//visited array
bool visited[N]; 

//adjacency list 
vector<pii>adj[N];

//dijkstra implementation
void dijkstra(int source){
    priority_queue<pii, vector<pii>, greater<pii>>pq;
    dist[source]=0;
    
    pq.push({dist[source], source});
    while(!pq.empty()){
        int u= pq.top().second;
        pq.pop();
        visited[u]=true;
        for(auto vPair: adj[u]){
            int v= vPair.first;
            int w= vPair.second;
            if(visited[v]) continue;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }



    }


}
int main(){
    int n, e;
    cin>>n>>e;
    for(int i=0; i<e; i++){
        int a, b, w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});

    }
    int s;
    cin>>s;
    dijkstra(s);
    int t;
    cin>>t;
    while(t--){
        int d, dw;
        cin>>d>>dw;
        if(dist[d]<=dw){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

    
    return 0;
}