#include<bits/stdc++.h>
using namespace std;
//global n and m
int n,m;

//vector
vector<string>g;

//pair typedef
typedef pair<int,int>pii;

//range
const int N=1e3+3;

//visited array
bool visited[N][N];

//direction array
vector<pii>direct= {{-1,0},{1,0},{0,-1},{0,1}};

//validity check
bool isValid(int i,int j){
    return (i>=0 && i<n && j>=0 && j<m);
}

//component
vector<pii> cmp;
//dfs implementation
void dfs(int si, int sj){
    visited[si][sj]=true;
    cmp.push_back({si,sj});
    for(auto d: direct){
        int ni= si+ d.first;
        int nj= sj+ d.second;
        if(isValid(ni,nj) && !visited[ni][nj] && g[ni][nj]=='.'){
            dfs(ni,nj);
        }

    }

}
int main(){
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        string x;
        cin>>x;
        g.push_back(x);

    }
    
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         if(!visited[i][j] && g[i][j]=='.'){
               
    //             dfs(i,j);
              
    //         }

    //     }
    // }
    int Si, Sj;
    cin>>Si>>Sj;
    int di, dj;
    cin>>di>>dj;
    dfs(Si, Sj);
    if(visited[Si][Sj] && visited[di][dj]){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    
    return 0;
}