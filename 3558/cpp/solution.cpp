#include <vector>
#include <algorithm>

using namespace std;

class EdgeCompare{
public:
    const bool operator()(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
};

class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++){
            if (edges[i][1] < edges[i][0]){
                edges[i] = {edges[i][1], edges[i][0]};
            }
        }
        sort(edges.begin(), edges.end(), EdgeCompare());
        int n = edges.size() + 1;
        vector<int> depth = vector<int>(n, __INT32_MAX__);
        int max_depth = 0;
        depth[0] = 0;
        for (vector<int> edge: edges){
            depth[edge[1] - 1] = depth[edge[0] - 1] +1;
            max_depth = max(max_depth, depth[edge[1]-1]);
        }

        long long int res = 1;
        for (int i = 1; i < max_depth; i++){
            res = res*2;
            res = res % (1000000007);
        }
        
        return res;
    }
};