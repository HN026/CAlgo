#include <iostream>
#include <string>

using namespace std;

void stringSolve(int m, int a[]) {
    string coloring(m, 'B');
    int i = 1;
    while (a[i] == a[i - 1] && i < m) {
        i++;
    }

    if (i == m) {
        cout << "No" << endl;
        return;
    }

    for (int k = 0; k < i; k++)
        coloring[k] = 'R';
    cout << "Yes" << endl;
    cout << coloring << endl;
}

int main() {
    int n;
    cin >> n;
    while (n) {
        int m;
        cin >> m;
        int a[m];
        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }
        stringSolve(m, a);
        n--;
    }
    return 0;
}