#include <iostream>
#include "bits/stdc++.h"
using namespace std;
int graph[1300][130][65] = {0};
bool visited[1300][130][65] = {false};
int m, n, l, t;

int X[6] = {1, 0, 0, -1, 0, 0};
int Y[6] = {0, 1, 0, 0, -1, 0};
int Z[6] = {0, 0, 1, 0, 0, -1};

struct Node{
    int x, y, z;
};

int bfs(int x, int y, int z){
    visited[x][y][z] = true;
    int cnt = 1;
    queue<Node> myQueue;
    myQueue.push({x, y, z});

    while (!myQueue.empty()){
        int width = myQueue.size();

        for (int i = 0; i < width; ++i) {
            auto cur = myQueue.front();
            myQueue.pop();

            for (int j = 0; j < 6; ++j) {
                int newX = cur.x + X[j];
                int newY = cur.y + Y[j];
                int newZ = cur.z + Z[j];

                if (visited[newX][newY][newZ] == false && graph[newX][newY][newZ] == 1 && newX >= 0 && newX < m && newY >= 0 && newY < n && newZ >= 0 && newZ < l){
                    visited[newX][newY][newZ] = true;
                    cnt++;
                    myQueue.push({newX, newY, newZ});
                }
            }
        }
    }

    if (cnt >= t)
        return cnt;
    else
        return 0;
}

int dfs(int x, int y, int z, int level){
    if (level > 50)
        return 0;

    int cnt = 1;
    visited[x][y][z] = true;

    for (int i = 0; i < 6; ++i) {
        int newX = x + X[i];
        int newY = y + Y[i];
        int newZ = z + Z[i];

        if (visited[newX][newY][newZ] == false && graph[newX][newY][newZ] == 1 && newX >= 0 && newX < m && newY >= 0 && newY < n && newZ >= 0 && newZ < l)
            cnt += dfs(newX, newY, newZ, level + 1);
    }

    return cnt;
}

int main() {
    scanf("%d%d%d%d", &m, &n, &l, &t);

    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                scanf("%d", &graph[j][k][i]);
            }
        }
    }

    int sum = 0;

    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                if (graph[j][k][i] == 1 && visited[j][k][i] == false){
                    int cnt = dfs(j, k, i, 1);
                    if (cnt >= t)
                        sum += cnt;
                }
            }
        }
    }

    printf("%d", sum);
    return 0;
}
