#include <bits/stdc++.h>
using namespace std;

void SieveOfEratosthenes(int n)
{
	bool prime[n + 1];
    for(int i=0;i<n+1;i++){
        prime[i]=true;
    }

	for (int p = 2; p * p <= n; p++) {
		if (prime[p] == true) {
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}

	for (int p = 2; p <= n; p++)
		if (prime[p])
			cout << p << " ";
}

void SieveOfEratosthenes(int n)
{
    int primes[n+1];
    primes[0] = 1;
    for (int i = 3; i*i <= n; i += 2) {
        if (primes[i / 2] == 0) {
            for (int j = 3 * i; j <= n; j += 2 * i)
                primes[j / 2] = 1;
        }
    }
}

int main()
{
	int n = 30;
	cout << "Following are the prime numbers smaller "
		<< " than or equal to " << n << endl;
	SieveOfEratosthenes(n);
	return 0;
}
