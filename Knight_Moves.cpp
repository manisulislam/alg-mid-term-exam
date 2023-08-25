#include<bits/stdc++.h>
using namespace std;
//global n and m
int n,m;

//typedef pair
typedef pair <int, int>pii;
//range
const int N=105;



//distance
int dist[N][N];

//visited
bool visited[N][N];

//direction
vector<pii>direct={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};

//validity check
bool isValid(int i,int j){
    return (i>=0 && i<n && j>=0 && j<m);
}
//bfs implementation
void bfs(int si, int sj){
    queue<pii>q;
    q.push({si,sj});
    dist[si][sj]=0;
    visited[si][sj]=true;
    while(!q.empty()){
        pii u= q.front();
        int i=u.first;
        int j= u.second;
        q.pop();

        for(auto d: direct){
        int ni= i+ d.first;
        int nj= j+ d.second;
        if(isValid(ni,nj) && !visited[ni][nj]){
            q.push({ni,nj});
            visited[ni][nj]=true;
            dist[ni][nj]=dist[i][j]+1;
        }

    }
    }
   


}
int main(){
    int t;
    cin>>t;
    while(t--){
        
        cin>>n>>m;
        int ki,kj;
        cin>>ki>>kj;
        int qi,qj;
        cin>>qi>>qj;
   
        //reset
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                visited[i][j]=false;
                dist[i][j]=-1;
            }
        }

        bfs(ki,kj);
        if(dist[qi][qj]==-1){
            cout<<"-1"<<endl;
        }
        else{
            cout<<dist[qi][qj]<<endl;
        }
        
    }
    return 0;
}