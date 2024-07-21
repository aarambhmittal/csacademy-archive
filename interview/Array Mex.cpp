int32_t mex(std::vector<int32_t>& v) {
    size_t sz = v.size();
    
    bool zero = false;
    for(int32_t& i: v) {
        if(i == 0) {
            zero = true; break;
        }
    }
    if(zero == false) return 0;
    
    for(size_t i = 0; i < sz; i++) {
        int32_t idx = std::abs(v[i]);
        
        if(idx < (int32_t)sz) {
            if(v[idx] == 0) {
                v[idx] = (int32_t)(sz + 1);
            }
            v[idx] = -std::abs(v[idx]);
        }
    }
    
    int32_t mex = 1;
    while((mex < (int32_t)sz) && (v[mex] < 0)) ++mex;
    return mex;
}
