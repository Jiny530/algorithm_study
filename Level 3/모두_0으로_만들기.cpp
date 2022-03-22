#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> wei;
bool compare(int a, int b)
{
    return wei[a] <= wei[b];
}

bool compare2(pair<int,int> a, pair<int, int> b)
{
    return a.second >= b.second;
}

// num이 0이 될때까지 반복 호출하는 재귀함수
int dfs(vector<vector<int>> tree, vector<int> a, vector<int>visit, int node, int weight, int depth)
{
    int min_count = 100000;
    // i는 node와 연결된 노드의 인덱스
    for (int i = 0; i < tree[node].size(); i++)
    {
        int count = 0;
        vector<int> temp = a;
        if (visit[i] == 1) continue;
        visit[i] = 1;
        int w = tree[node][i];
        if (a[w] < 0 && weight + a[w] >= 0)
        {
            count -= a[w] * depth;
            weight += a[w];
            temp[w] = 0;
        }
        else if (a[w] < 0 && weight + a[w] < 0)
        {
            count -= weight * depth;
            weight = 0;
        }

        // 무조건 dfs가 아니라 같은 depth의 노드도 봐야하는 bfs를 해야하는듯
        if (weight == 0) min_count = min(min_count, count);
        else {
            count += dfs(tree, temp, visit, w, temp[i]);
        }
        
        visit[i] = 0;


    }
    return count;
}
long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = 0;
    wei = a;
    vector<vector<int>> tree(wei.size(), vector<int>()); // 노드의 가중치와 연결된 에지들을 나타낼 트리
    int sum = 0;
    bool is_zero = true;

    for (int i = 0; i < wei.size(); i++)
    {
        sum += wei[i];
        if (wei[i] != 0) is_zero = false;
    }
    if (sum != 0) return -1;
    else if (is_zero) return 0;

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

    vector<pair<int, int>> weight(wei.size(), { 0,0 }); // 양수 노드의 인덱스와 가중치를 저장하여 가중치 순으로 정렬
    for (int i = 0; i < wei.size(); i++)
    {
        if (wei[i] <= 0) continue;
        weight.push_back({ i,wei[i] });
    }
    sort(weight.begin(), weight.end(), compare2);

    for (int i = 0; i < weight.size(); i++)
    {
        vector<int> visit(a.size(), 0);
        visit[weight[i].first] = 1;
        answer += dfs(tree, wei, visit, weight[i].first, weight[i].second, 1);
    }
    

    return answer;
}