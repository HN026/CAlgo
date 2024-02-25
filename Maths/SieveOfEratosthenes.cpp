#include <iostream>
#include <vector>

using namespace std;

vector<int> sieveOfEratosthenes(int n) {
    vector<bool> prime(n+1, true);
    prime[0] = prime[1] = false;

    for (int p = 2; p*p <= n; p++) {
        if (prime[p] == true) {
            // Can also be kept as i = 2*p, it's an obtimisation
            for (int i = p*p; i <= n; i += p) 
                prime[i] = false;
        }
    }

    vector<int> primes;
    for (int p = 2; p <= n; p++)
        if (prime[p])
            primes.push_back(p);

    return primes;
}

int main() {
    int n = 30;
    cout << "Prime numbers less than or equal to " << n << " are: ";
    vector<int> primes = sieveOfEratosthenes(n);
    for (int prime : primes)
        cout << prime << " ";
    return 0;
}