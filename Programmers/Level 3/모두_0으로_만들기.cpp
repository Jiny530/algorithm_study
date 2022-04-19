#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> wei;
vector<int> visit;
queue<pair<int,int>> connect;
 // 시간초과

bool compare(int a, int b)
{
    return wei[a] <= wei[b];
}
// num이 0이 될때까지 호출
int bfs(vector<vector<int>> tree, int weight)
{
    pair<int, int> pair = connect.front(); // 큐의 앞 원소 빼기
    int node = pair.first;
    int depth = pair.second;
    int count = 0;
    visit[node] = 1;

    if (tree[node].size() == 1) goto next;

    if (wei[node] < 0) // 가중치가 음수인 노드이면 원래노드와 연산
    {
        if (weight + wei[node] > 0)
        {
            count -= wei[node] * depth;
            weight += wei[node];
            wei[node] = 0;
        }
        else 
        {
            count -= weight * depth;
            wei[node] += weight;
            weight = 0;
            return count;
        }
    }

    // 0으로 만드려는 노드이거나 노드연산 후에도 weight가 0 이 아니면 연결된 노드를 큐에 넣고 계속해서 연산함
    for (int i = 0; i < tree[node].size(); i++)
    {
        if (visit[tree[node][i]] == 0) connect.push({ tree[node][i], depth + 1 });
    }
    
    next:
    count += bfs(tree, weight);
    return count;
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = 0;
    wei = a;
    vector<vector<int>> tree(wei.size(), vector<int>()); // 노드의 가중치와 연결된 에지들을 나타낼 트리
    int sum = 0;

    for (int i = 0; i < wei.size(); i++) sum += wei[i];
    if (sum != 0) return -1;

    // 각노드에 연결된 노드를 저장
    for (int i = 0; i < edges.size(); i++)
    {
        tree[edges[i][0]].push_back(edges[i][1]);
        tree[edges[i][1]].push_back(edges[i][0]);
    }

    // 에지가 1개인 노드는 바로 0으로 만들기
    for (int i = 0; i < wei.size(); i++)
    {
        if (tree[i].size() > 1) continue;
        answer += abs(wei[i]);
        wei[tree[i][0]] += wei[i];
        wei[i] = 0;
    }

    // 양수노드에 연결된 음수 노드를 가중치 큰 것부터 연산
    for (int i = 0; i < wei.size(); i++)
    {
        if (wei[i] <= 0) continue;
        sort(tree[i].begin(), tree[i].end(), compare);

        for (int j = 0; j < tree[i].size(); j++)
        {
            if (wei[tree[i][j]] >= 0 || wei[i] == 0) break; // 음수노드가 더이상 없거나 노드 가중치가 0이 되면 반복종료
            
            if (wei[i] + wei[tree[i][j]] <= 0) {
                wei[tree[i][j]] += wei[i];
                answer += wei[i];
                wei[i] = 0;
            }
            else {
                wei[i] += wei[tree[i][j]];
                answer -= wei[tree[i][j]];
                wei[tree[i][j]] = 0;
            }
        }
    }

    for (int i = 0; i < wei.size(); i++)
    {
        if (wei[i] <= 0) continue;
        vector<int> visited(a.size(), 0);
        visit = visited;

        queue<pair<int,int>> connected;
        connect = connected;

        connect.push({ i, 0});
        answer += bfs(tree, wei[i]);

    }
    

    return answer;
}