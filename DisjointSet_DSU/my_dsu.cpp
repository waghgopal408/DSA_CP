#include "dsu.h"
int main(){
    // allowedSwaps = [[1,2],[2,3],[4,5],[6,7],[5,6],[3,7]]
    // 0 1 2 3 4 5 6 7

    int n = 7;
    DSU dsu(n);

    dsu.Union(1,2);
    dsu.Union(2,3);
    dsu.Union(4,5);
    dsu.Union(6,7);
    dsu.Union(5,6);
    if(dsu.findParent(3) == dsu.findParent(7)){
        cout<<"same\n";
    }else cout<<"not same\n";
    
    dsu.Union(3,7);

    if(dsu.findParent(3) == dsu.findParent(7)){
        cout<<"same\n";
    }else cout<<"not same\n";
    
    return 0;

}