// g++ -std=c++11 -O2 -Wall CompetitiveResources.cpp -o crs

#include <bits/stdc++.h>

#define PRINT(arr) cout << #arr << ": "; for(ull n : arr) cout << n << " "; cout << endl;
#define PRINT_SGN(arr) cout << #arr << ": "; for(ll n : arr) cout << n << " "; cout << endl;
#define PRINT2(arr) for(vector<ull> v : arr) {for(ull n : v) cout << n << " "; cout << endl;} cout<<endl;
#define ord(c) c-'0'
#define len(s) s.size()

typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<int, int> vii;

using namespace std;

ull fib(ull n, vector<ull>& memo){
   // PRINT(memo,n)
   if (n==0){memo[n] = 0;return 0;}
   if (n==1) {memo[n] = 1;return 1;}
   if (memo[n]!=-1) return memo[n];
   memo[n] = fib(n-1,memo) + fib(n-2,memo);
   return memo[n];
}

ull nCr(ull n, ull r){
   ull final = 1;
   for (ull i = n; i>n-r; i--){
      final *= i;
   }
   for (ull k = r; k>0; k--){
      final /= k;
   }
   return final;
}

ull nPr(ull n, ull r){
   ull final = 1;
   for (ull i = n; i>n-r; i--){
      final *= i*(i-(n-r));
   }
   for (ull k = r; k>0; k--){
      final /= k;
   }
   return final;
}

ull nCr(ull n, ull r, vector<vector<ull>>& memo){
   // PRINT2(memo);
   if (n==0) {return 0;}
   if (n==1) {memo[n][r] = 1;return 1;}
   if (r==n) {memo[n][r] = 1;return 1;}
   if (r==0) {memo[n][r] = 1;return 1;}
   if (memo[n][r]) return memo[n][r];
   memo[n][r] = nCr(n-1,r-1,memo) + nCr(n-1,r,memo);
   return memo[n][r];
}

ull gcd(ull a, ull b){
   ull mx = 0, mn = 0;
   mn = min(a,b);
   mx = max(a,b);
   if (!mn) return mx;
   return gcd(mx%mn,mn);
}

ull fac(ull n){
   if (n==1 || n==0) return 1;
   return n*fac(n-1);
}

void subsets(vector<ull>& nums){
   bitset<9> bits;
   for (ull i = 0; ; i++){
      bits = i;
      cout << bits << endl;
      if (bits.count()==bits.size()) break;
   }
}

void stl(){
   vector<ll> tester{20,389,4,-2,-56,39,9,48,92,4,9,-39};
   set<ll> set_tester;
   for (ll i : tester) set_tester.insert(i);
   PRINT_SGN(tester)
   sort(tester.begin(),tester.end());
   PRINT_SGN(set_tester)
   PRINT_SGN(tester)


   cout << "Lower Bound:" << *lower_bound(tester.begin(),tester.end(),21) << endl;
   cout << "Lower Bound:" << *lower_bound(tester.begin(),tester.end(),21) << endl;
}


void map_solve(){
   map<string,int> shapes;
   shapes["Tetrahedron"] = 4;
   shapes.insert(make_pair("Cube",6));
   shapes.insert(make_pair("Octahedron",8));
   shapes.insert(make_pair("Dodecahedron",12));
   shapes.insert(make_pair("Icosahedron",20));
}



int main(){

#ifndef ONLINE_JUDGE
   FILE* f_in = freopen("input.txt","r",stdin);
   // FILE* fout = freopen("output.txt","w",stdout);
#endif

   ios::sync_with_stdio(0);
   cin.tie(0);

   // Recursive Fibonacci Sequence Using Memoization
   // vector<ull> memo(100,-1);
   // for(ll k = 0; k<100; k++)cout << k << " " << fib(k,memo) << endl;

   // Iterative Permutations and Combinations
   // ull n = 6,r = 2;
   // cout << nPr(n,r) << " " << nCr(n,r) << endl;

   // Recursive Combinations with Memoization (Pascal Triangle)
   // ull n = 6, r = 3;
   // vector<vector<ull>> memo(n+1,vector<ull> (n+1,0));
   // cout << "ANS: " << nCr(n,r,memo) << endl;

   // Greatest Common Divisor of Two Numbers gcd(a,b)
   // ull a = 34,b = 51;
   // cout << "gcd(" << a << "," << b << ") = " <<gcd(a,b) << endl;

   // Recursive Factorial Of a Number N!
   // ull n = 5;
   // cout << "fac: " << fac(n) << endl;

   // Generating bit string sequences for sets
   // vector<ull> nums{10,20,32,43,69,22,18,75,38};
   // subsets(nums);

   // Data Structures and Algorithms from the Standard Template Libraru
   stl();

   return 0;
}