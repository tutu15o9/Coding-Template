#include <bits/stdc++.h>
using namespace std;
#define int long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define umap unordered_map;
#define uset unordered_set;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
int mpow(int base, int exp);
const int mod = 1000000007;

void solve()
{
	string S;
	unordered_map<char,vi> indexSet;

	priority_queue<pii> charCount;
	for(int i = 0;i<26;i++){
		charCount.push({0,i});
	}
	cin >> S;
	vector<int> cnt(26,0);
	for(int i = 0;i<S.length();i++){
		cnt[S[i]-'a']++;
		indexSet[S[i]].push_back(i);
	}

	for(int i = 0;i<26;i++){
		charCount.push({cnt[i],i});
	}


	while(!charCount.empty()){
		pii top1 = charCount.top();

		charCount.pop();
		if(charCount.empty()){
			cout<<"IMPOSSIBLE"<<endl;
			return;
		}
		pii top2 = charCount.top();
		charCount.pop();

		int ind1 = indexSet[top1.S + 'a'][indexSet[top1.S+ 'a'].size()-1];
		int ind2 = indexSet[top2.S + 'a'][indexSet[top2.S+ 'a'].size()-1];
		indexSet[top1.S+ 'a'].pop_back();
		indexSet[top2.S+ 'a'].pop_back();

		S[ind1] = top2.S + 'a';
		S[ind2] = top1.S + 'a';

		charCount.push({top1.first-1,top1.S});
		charCount.push({top2.first-1,top2.S});
	}
	cout<<S<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	// deb(t);

	while (t--)
	{
		solve();
	}
	return 0;
}

int mpow(int base, int exp)
{
	base %= mod;
	int result = 1;
	while (exp > 0)
	{
		if (exp & 1)
			result = ((int)result * base) % mod;
		base = ((int)base * base) % mod;
		exp >>= 1;
	}
	return result;
}
