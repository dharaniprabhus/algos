#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <limits>
#include <cstdint>

using namespace std;

// input : vecror A e.g. [3,4,5] representing mask of each lane segment
// assumprion : the mask values < 255 (8 bits)
// algo : dijistra to find the shortest path to the final segment

using Node = tuple<int,int,int>;
int dijistra(const vector<vector<bool>>& graph,int si,int sj){
    vector<vector<bool>> vis(graph.size(),vector<bool>(8,false));
    priority_queue<Node,vector<Node>,greater<Node>> pq;
    Node start{0,si,sj};
    pq.push(start);
    vector<int> dist(graph.size(),INT32_MAX);
    dist[0] = 0;
    while(!pq.empty()){
        int i, j, cdist;
        tie(cdist, i, j) = pq.top(); pq.pop();
        vis[i][j] = true;
        //last segment reached
        if (i == graph.size()-1){
            return dist[graph.size()-1];
        }
        int nextSeg = i + 1;
        int left = j - 1;
        int right = j + 1;
        int straight = j;
        if (nextSeg < graph.size()) {
            //left
            if (left >= 0 && graph[nextSeg][left] && !vis[nextSeg][left]) {
                pq.push({cdist + 1,nextSeg, left});
                if (dist[nextSeg] > cdist + 1) {
                    dist[nextSeg] = cdist + 1;
                }
            }
            //straight
            if (graph[nextSeg][straight] && !vis[nextSeg][straight]){
                pq.push({cdist,nextSeg,straight});
                if (dist[nextSeg] > cdist) {
                    dist[nextSeg] = cdist;
                }
            }
            //right
            if (right < 8 && graph[nextSeg][right] && !vis[nextSeg][right]) {
                pq.push({cdist + 1,nextSeg, right});
                if (dist[nextSeg] > cdist + 1) {
                    dist[nextSeg] = cdist + 1;
                }
            }
        }
    }
    return INT32_MAX;
}

void printGraph(const vector<vector<bool>>& graph){
    for(int i = 0; i<graph.size(); ++i){
        for(int j = 0; j<8; ++j){
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int minLaneSwitch(vector<int> &A) {
    vector<vector<bool>> graph(A.size(),vector<bool>(8,false));
    for(int i = 0; i<A.size(); ++i){
        int mask = A[i];
        for(auto j = 0; j<8; ++j){
            if (mask & (1<<j)){
                graph[i][j] = true;
            }
        }
    }
    printGraph(graph);
    int ans = INT32_MAX;
    for(int i = 0; i<8; ++i){
        if (graph[0][i]){
            ans = min(ans, dijistra(graph,0,i));
        }
    }
    return (ans == INT32_MAX) ? -1 : ans;
}


int main(){
    int n, val;
    vector<int> A;
    cin >> n;
    while(n--){
        cin >> val;
        A.push_back(val);
    }
    int ans = minLaneSwitch(A);
    cout << "Minimum lanes to switch : " << ans << "\n";
    return 0;
}
