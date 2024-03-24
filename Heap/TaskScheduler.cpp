#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

int leastInterval(vector<char> &tasks, int n) {
    unordered_map<char, int> counts;
    for (char task : tasks) {
        counts[task]++;
    }

    priority_queue<pair<int, char>> pq;
    for (auto it : counts) {
        pq.push({it.second, it.first});
    }

    int alltime = 0;
    int cycle = n + 1;
    while (!pq.empty()) {
        int time = 0;
        vector<pair<int, char>> tmp;
        for (int i = 0; i < cycle; i++) {
            if (!pq.empty()) {
                tmp.push_back(pq.top());
                pq.pop();
                time++;
            }
        }
        for (auto it : tmp) {
            if (--it.first) {
                pq.push(it);
            }
        }
        alltime += !pq.empty() ? cycle : time;
    }
    return alltime;
}

int main() {
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;
    int result = leastInterval(tasks, n);
    cout << "The least number of intervals is: " << result << endl;
    return 0;
}