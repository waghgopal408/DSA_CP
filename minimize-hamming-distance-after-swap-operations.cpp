//1722
//Approach - (DSU + map)
//T.C : O(n + m*alpha(n)), alpha(n) = inverse Ackermann function.
//S.C : O(n)
class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int getParent(int x){
        if(parent[x] == x) return x;
        parent[x] = getParent(parent[x]);
        return parent[x];
    }

    void Union(int u, int v){
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
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        
        int n = source.size();
        parent.resize(n+1,0);
        rank.resize(n+1,0);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }

        //union of allowed swaps
        for(int i=0;i<allowedSwaps.size();i++){
            int u = allowedSwaps[i][0], v = allowedSwaps[i][1];
            Union(u,v);
        }

        // coustom data structure to solve problem
        unordered_map<int, unordered_map<int, int>> groupFreq;
        for(int i=0;i<n;i++){
            int curr = source[i];
            int parent = getParent(i);
            groupFreq[parent][curr]++;
        }

        int dist = 0;
        for(int i=0;i<n;i++){
            int parent = getParent(i);
            // int curr = source[i];

            if(groupFreq[parent][target[i]] > 0){
                groupFreq[parent][target[i]]--;
            }else{
                dist++;
            }
        }
        return dist;

    }
};