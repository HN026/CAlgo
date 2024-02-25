#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class DisjointSet {
  public:
    vector<int> size;
    vector<int> parent;
    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUltimateParent(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findUltimateParent(parent[node]);
    }

    void UnionBySize(int u, int v) {
        int ulparent_u = findUltimateParent(u);
        int ulparent_v = findUltimateParent(v);

        if (ulparent_u == ulparent_v)
            return;

        if (size[ulparent_u] < size[ulparent_v]) {
            parent[ulparent_u] = ulparent_v;
            size[ulparent_v] += size[ulparent_u];
        } else {
            parent[ulparent_v] = ulparent_u;
            size[ulparent_u] += size[ulparent_v];
        }
    }

    void reset(int node) {
        parent[node] = node;
        size[node] = 1;
    }
};

static bool compare(const vector<int> &a, const vector<int> &b) {
    return a[2] < b[2];
}

vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson) {
    DisjointSet ds(n);
    ds.UnionBySize(0, firstPerson);

    sort(meetings.begin(), meetings.end(), compare);

    int e = meetings.size();
    int i = 0;
    while (i < e) {
        int currentTime = meetings[i][2];
        set<int> currPeople;
        while (i < e && meetings[i][2] == currentTime) {
            int u = meetings[i][0];
            int v = meetings[i][1];
            ds.UnionBySize(u, v);
            currPeople.insert(u);
            currPeople.insert(v);
            i++;
        }

        for (auto &person : currPeople) {
            if (ds.findUltimateParent(person) != ds.findUltimateParent(firstPerson))
                ds.reset(person);
        }
    }

    vector<int> result;
    for (int i = 0; i < n; i++) {
        if (ds.findUltimateParent(i) == ds.findUltimateParent(firstPerson))
            result.push_back(i);
    }

    return result;
}

int main() {
    vector<vector<int>> meetings = {{1, 2, 5}, {2, 3, 8}, {1, 5, 10}};
    int n = 6;
    int firstPerson = 1;

    vector<int> result = findAllPeople(n, meetings, firstPerson);

    cout << "People who know the secret: ";
    for (int person : result) {
        cout << person << " ";
    }
    cout << endl;

    return 0;
}