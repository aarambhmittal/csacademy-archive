#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> //.

size_t N, M;
int32_t dp[3001][3001][2];
std::vector<std::pair<int32_t, int32_t>> prof, stud, temp;

void solve() {
    std::cin >> N >> M;
    prof.resize(N);
    temp.resize(M);
    
    for(size_t i = 0; i < N; i++) std::cin >> prof[i].first >> prof[i].second;
    for(size_t i = 0; i < M; i++) std::cin >> temp[i].first >> temp[i].second;
    
    std::sort(prof.begin(), prof.end());
    std::sort(temp.begin(), temp.end());
    
    for(std::pair<int32_t, int32_t>& t: temp) {
        while(!stud.empty() && (stud.back().second <= t.second)) {
            stud.pop_back();
        }
        stud.push_back(t);
    }
    M = stud.size();
    
    for(size_t i = 0; i <= N; i++)
        for(size_t j = 0; j <= M; j++)
            dp[i][j][0] = dp[i][j][1] = 1e9;
    
    dp[1][0][0] = prof[0].first + prof[0].second;
    dp[0][1][1] = stud[0].first + stud[0].second;
    
    for(size_t i = 0; i <= N; i++) {
        for(size_t j = 0; j <= M; j++) {
            if(i == 0 && j == 0) continue;
            
            if(i + 1 <= N) {
                int32_t t1 = std::max(dp[i][j][0], prof[i].first) + prof[i].second;
                int32_t t2 = std::max(dp[i][j][1], prof[i].first) + prof[i].second;
                dp[i + 1][j][0] = std::min({dp[i + 1][j][0], t1, t2});
            }
            
            if(j + 1 <= M) {
                int32_t t1 = std::max(dp[i][j][0], stud[j].first) + stud[j].second;
                int32_t t2 = std::max(dp[i][j][1], stud[j].first + stud[j].second);
                dp[i][j + 1][1] = std::min({dp[i][j + 1][1], t1, t2});
            }
        }
    }
    
    std::cout << std::min(dp[N][M][0], dp[N][M][1]);
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
