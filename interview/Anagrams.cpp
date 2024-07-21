#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> //.

void solve() {
    size_t n; std::cin >> n;
    
    std::vector<std::string> v;
    for(size_t i = 0; i < n; i++) {
        std::string s; std::cin >> s;
        v.push_back(s);
    }
    
    std::array<int32_t, 26> freq;
    std::map<std::array<int32_t, 26>, int32_t> mp;
    for(size_t i = 0; i < n; i++) {
        std::fill(freq.begin(), freq.end(), 0);
        for(char& ch: v[i]) ++freq[ch - 'a'];
        ++mp[freq]; 
    }
    
    int32_t ans = 0;
    std::map<std::array<int32_t, 26>, int32_t> :: iterator it;
    for(it = mp.begin(); it != mp.end(); it++) {
        ans = std::max(ans, it->second);
    }
    std::cout << ans;
}

signed main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);
    
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif
    
    int tst = 1;
    while(tst--) solve();
                
    return 0;
}

// g++ -std=c++20 <filename>.cpp
