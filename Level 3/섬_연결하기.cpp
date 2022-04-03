#include <string>
#include <vector>

using namespace std;
int greedy(int min, vector<int>* cost, vector<vector<int>>nodes, vector<int> visit) {

    int select = 0;
    for (int i = 1; i < (*cost).size(); i++)
    {
        if (visit[i]) continue;
        if (nodes[min][i] < (*cost)[i]) (*cost)[i] = nodes[min][i];
        if ((*cost)[i] < (*cost)[select]) select = i;
    }

    return select;
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    vector<int> cost(n, 200000000);
    vector<int> visit(n, 0);
    vector<vector<int>> nodes(n, vector<int>(n, 200000000));

    for (int i = 0; i < costs.size(); i++)
    {
        nodes[costs[i][0]][costs[i][1]] = costs[i][2];
        nodes[costs[i][1]][costs[i][0]] = costs[i][2];
    }

    int min = 0;
    for (int i = 1; i < n; i++) // 맨 처음 노드부터 시작
    {
        cost[i] = nodes[0][i];
        if (cost[i] < cost[min]) min = i;
    }
    answer += cost[min];

    for (int i = 0; i < n - 2; i++)
    {
        visit[min] = 1;
        min = greedy(min, &cost, nodes, visit);
        answer += cost[min];
    }

    return answer;
}