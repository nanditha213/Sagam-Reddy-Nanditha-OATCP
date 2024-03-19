// YOGI SHIVA MAHADEV
#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
#define des(s) set<ll> s
#define dem(mp) map<ll,ll> mp
#define sr(v) sort(v.begin(),v.end(),greater<ll>())
#define rr(v) sort(v.begin(),v.end())
int binpow(int a, int b){if (b==1){return a;}else if (b==0){return 1;}ll one = binpow(a,b/2);if (b%2==0){return one*one;}else{return a*one*one;}}
using namespace std;
#define MOD 1000000007
void fillPrefixSum(int arr[], int n, int prefixSum[])
{
prefixSum[0] = arr[0];
for (int i = 1; i < n; i++)
prefixSum[i] = prefixSum[i - 1] + arr[i];
}
ll gcd(ll x, ll y)
{
if (y == 0)
{
return x;
}
return gcd(y, x % y);
}
ll fact(ll n)
{
ll res = 1;
for (int i = 2; i <= n; i++)
res = res * i;
return res;
}
void SieveOfEratosthenes(int n)
{
bool prime[n + 1];
memset(prime, true, sizeof(prime));
for (int p = 2; p * p <= n; p++) {
if (prime[p] == true) {
for (int i = p * p; i <= n; i += p)
prime[i] = false;
}
}
for (int p = 2; p <= n; p++)
if (prime[p])
cout << p;
}
long long get_hash(string s){
ll h=0;
for(char c : s){
h = (h * 31 + (c - 'a' + 1))%MOD;
return h;
}
}
bool comp (char s1, char s2)
{
return tolower(s1)<tolower(s2);
}
long long lower_bound(vector<ll> &v, long long element){
ll lo = 0;
ll hi = v.size()-1;
while((hi-lo) > 1){
ll mid = (lo+hi)/2;
if(v[mid]<element){
lo=mid+1;
}
else{
hi=mid;
}
}
if(v[lo]>=element){
return lo;
}
if(v[hi]>=element){
return hi;
}
else{
return -1;
}
}
long long upper_bound(vector<ll> &v, long long element){
ll lo = 0;
ll hi = v.size()-1;
while((hi-lo) > 1){
ll mid = (lo+hi)/2;
if(v[mid]<=element){
lo=mid+1;
}
else{
hi=mid;
}
}
if(v[lo]>element){
return lo;
}
if(v[hi]>element){
return hi;
}
else{
return -1;
}
}
long long square_root(long long n){
double eps = 1e-6;
ll lo=1;
ll hi=n;
ll mid;
while(hi-lo > eps){
mid = (lo+hi)/2;
if(mid*mid < n){
lo = mid;
}
else{
hi = mid;
}
}
return lo;
}
int isBalanced(string s){
unordered_map<char, int> symbol = {{'(', -1}, {')', 1}};
stack<char> st;
for(char bracket : s){
if(symbol[bracket]<0){
st.push(bracket);
}
else{
if(st.empty()){
return -1;
}
else{
char top = st.top();
st.pop();
if(symbol[top]+symbol[bracket]!=0){
return -1;
}
}
}
}
if(st.empty()){
return 0;
}
else{
return -1;
}
}
class DisjointSet {
vector<int> rank, parent, size;
public:
DisjointSet(int n) {
rank.resize(n+1, 0);
parent.resize(n+1);
size.resize(n+1);
for(int i = 0;i<=n;i++) {
parent[i] = i;
size[i] = 1;
}
}
int findUPar(int node) {
if(node == parent[node])
return node;
return parent[node] = findUPar(parent[node]);
}
void unionByRank(int u, int v) {
int ulp_u = findUPar(u);
int ulp_v = findUPar(v);
if(ulp_u == ulp_v) return;
if(rank[ulp_u] < rank[ulp_v]) {
parent[ulp_u] = ulp_v;
}
else if(rank[ulp_v] < rank[ulp_u]) {
parent[ulp_v] = ulp_u;
}
else {
parent[ulp_v] = ulp_u;
rank[ulp_u]++;
}
}
void unionBySize(int u, int v) {
int ulp_u = findUPar(u);
int ulp_v = findUPar(v);
if(ulp_u == ulp_v) return;
if(size[ulp_u] < size[ulp_v]) {
parent[ulp_u] = ulp_v;
size[ulp_v] += size[ulp_u];
}
else {
parent[ulp_v] = ulp_u;
size[ulp_u] += size[ulp_v];
}
}
};
// KMP Algorithm string matching
int main()
{
    int n, m, pairs(0);
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cin >> m;
    int b[m];

    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(a, a + n);
    sort(b, b + m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (abs(a[i] - b[j]) < 2)
            {
                b[j] = 1000;
                pairs++;
                break;
            }

    cout << pairs << endl;
    return 0;
}
