#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
#define endl '\n'
#define pb push_back

int setBit(int &n, int num){
	return n | (1<<num);
}

bool checkBit(int n, int num){
	return n & (1<<num); 
}

void bitwiseSieve(int n){
	int prime[(n>>5)+1];
	memset(prime, 0, sizeof(prime));

	for(int i = 4; i <= n; i+=2){
		prime[i>>5] = setBit(prime[i>>5], i&31);
	}
	for(int i = 3; i*i <= n; i+=2){
		if(checkBit(prime[i>>5], i&31) == false){
			for(int j = i*i; j <= n; j += i){
				prime[j>>5] = setBit(prime[j>>5], j&31);
			}
		}
	}
	for(int i = 2; i <= n; i++)
		if(checkBit(prime[i>>5], i&31) == 0)
			cout << i << " ";
}
int main(){
	int t;
	cin >> t;
	bitwiseSieve(t);
}