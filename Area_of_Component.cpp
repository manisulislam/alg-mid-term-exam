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

//counting 
int cnt =0;
//dfs implementation
void dfs(int si, int sj){
    visited[si][sj]=true;
    cnt++;
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
    int mn=INT_MAX;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j] && g[i][j]=='.'){
                cnt=0;
                dfs(i,j);
                mn=min(mn,cnt);
            }

        }
    }
    if(cnt==0){
        cout<<"-1"<<endl;
    }
    else{
        cout<<mn<<endl;
    }
    return 0;
}