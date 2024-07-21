int32_t longestParenthesisedSubstring(const std::string& S) {
    int32_t sz = S.size();
    int32_t l1, l2, i, j, z;
    l1 = l2 = -1;
    
    i = j = 0;
    z = 0;
    while(j < sz) {
        if(S[j] == ')') {
            if(z == 0) {
                l1 = std::max(l1, (j - 1) - i + 1);
                i = j + 1;
                j = i;
            }
            else {
                --z;
                if(z == 0) l1 = std::max(l1, j - i + 1);
                ++j;
            }
        }
        else {
            ++z;
            ++j;
        }
    }
    
    i = j = sz - 1;
    z = 0;
    while(j > -1) {
        if(S[j] == '(') {
            if(z == 0) {
                l2 = std::max(l2, i - (j + 1) + 1);
                i = j - 1;
                j = i;
            }
            else {
                --z;
                if(z == 0) l2 = std::max(l2, i - j + 1);
                --j;
            }
        }
        else {
          ++z; 
          --j;
        }
    }
    
    int32_t ans = std::max(l1, l2);
    return (ans == 0)? -1: ans;
}
