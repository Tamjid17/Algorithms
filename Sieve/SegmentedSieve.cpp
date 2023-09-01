#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
#define endl '\n'
#define pb push_back

vector<ll> primes;
void simple(ll h){
	bool flag [h+1];
	flag[0] = flag[1] = false;
	for(int i = 2; i <= h; i++)
		flag[i] = true;
	for(int i = 2; i*i < h; i++){
		if(flag[i]){
			primes.push_back(i);
			for(int j = i*i; j <= h; j += i)
				flag[j] = false; 
		}
	}
}
int main(){
	ll l, h;
	cin >> l >> h;
	simple(h);
	bool isPrime[h-l+1];
	for(int i = 0; i < h-l+1; i++)
		isPrime[i] = true;
	if(l == 1)
		isPrime[0] = false;
	for(ll i = 0; primes[i]*primes[i] <= h; i++){
		ll a = primes[i];
        //cout << a << endl;
		ll b = a*a;
		if(b < l){
			b = ((l+a-1)/a)*a;
		}
		for(ll j = b; j <= h; j += a){
			isPrime[j-l] = false;
		}
	}
	for(ll i = l; i <= h; i++){
		if(isPrime[i-l])
			cout << i << " ";
	}
}