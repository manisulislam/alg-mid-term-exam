#include<bits/stdc++.h>
using namespace std;

//typedef pair
typedef pair<int , int> pii;

//range
const int N = 1e3+5;

//adjacency list
vector<pii>ad;

int main(){
    int e;
    cin>>e;
    for(int i=0; i<e; i++){
        int a, b;
        cin>>a>>b;
        ad.push_back({a,b});

    }
    
    //sort
    sort(ad.begin(), ad.end());

    //printing the ad
    for(auto d: ad){
        cout<<d.first<<" "<<d.second<<endl;
    }

    return 0;
}