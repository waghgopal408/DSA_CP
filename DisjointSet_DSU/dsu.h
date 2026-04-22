// #include<iostream>
// #include<vector>
#include<bits/stdc++.h>
using namespace std;

class DSU{
    public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    int findParent(int x){
        if(parent[x] == x) return x;
        parent[x] = findParent(parent[x]);
        return parent[x];
    }

    void Union(int u, int v){
        int parentU = findParent(u), parentV = findParent(v);
        if(parentU == parentV) return;

        if(rank[parentU] < rank[parentV]){
            swap(parentU, parentV);
        }
        parent[parentV] = parentU;

        if(rank[parentU] == rank[parentV]){
            rank[parentU]++;
        }
        /* same logic with this code
        int pu = getParent(u), pv = getParent(v);
        if(pu == pv) return;

        if(rank[pu] == rank[pv]){
            parent[pu] = pv;
            rank[pv]++;
        }
        else if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }
        else{
            parent[pv] = pu;
        }
        */
    }
};

