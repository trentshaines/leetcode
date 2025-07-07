using namespace std;

#include <string>
#include <unordered_map>

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_ct;
        for(const auto c: t){
            t_ct[c]++;
        }
        int t_size = t_ct.size();

        size_t n {s.size()};
        size_t r {0};

        int start = -1, res = n+1; 
        // Maintain a sliding window that satisfies all of t's counts.
        for (size_t l = 0; l < n; ++l) {
            // let l represent the includsive left bound.
            if (l > 0){
                if(t_ct.count(s[l-1]) != 0 && t_ct[s[l-1]]++ == 0)
                    ++t_size;
            }

            // Make the window valid.
            // r is the exclusive bound, and can end up at n.
            while(t_size && r < n){
                if(t_ct.count(s[r]) != 0 && --t_ct[s[r]] == 0)
                    --t_size;
                ++r;
            }

            if(r == n && t_size)
                break;

            if(r-l < res){
                start = l;
                res = r-l;
            }
        }

        return start == -1 ? "" : s.substr(start, res);
    }
};