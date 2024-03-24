#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool asteroidsDestroyed(int mass, vector<int> &asteroids) {
    sort(asteroids.begin(), asteroids.end());
    int n = asteroids.size();

    unsigned long long int check = mass;

    for (int i = 0; i < n; i++) {
        if (check >= asteroids[i]) {
            check += asteroids[i];
        } else {
            return false;
        }
    }

    return true;
}

int main() {
    vector<int> asteroids = {1, 2, 3, 4, 5};
    int mass = 3;

    bool result = asteroidsDestroyed(mass, asteroids);

    if (result) {
        cout << "All asteroids can be destroyed." << endl;
    } else {
        cout << "All asteroids cannot be destroyed." << endl;
    }

    return 0;
}