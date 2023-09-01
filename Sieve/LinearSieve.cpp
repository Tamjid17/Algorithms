#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
#define endl '\n'
#define pb push_back

void linearSieve(int n){
	vector<int> isPrime(n+1, 0);
	vector<int> prime;
	isPrime[0] = isPrime[1] = 0;
	for(int i = 2; i <= n; i++){
		if(!isPrime[i]){
			isPrime[i] = i;
			prime.pb(i);
		}
		for(int j = 0; i*prime[j] <= n; j++){
			isPrime[i*prime[j]] = prime[j];
			if(prime[j] == isPrime[i])
				break;
		}
	}
	for(auto it: prime)
		cout << it << " ";
}
int main(){
	int t;
	cin >> t;
	linearSieve(t);
}