#include <string>
#include <vector>
#include <set>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> queue;

    char command; int num;
    for (int i = 0; i < operations.size(); i++)
    {
        istringstream ss(operations[i]);
        ss >> command >> num;
        if (command == 'I') queue.insert(num);
        else if (!queue.empty())
        {
            if (num == 1) queue.erase(--queue.end());
            else queue.erase(queue.begin());
        }
    }
    if (queue.empty()) return { 0,0 };
    else return { *(--queue.end()), *(queue.begin()) };
}