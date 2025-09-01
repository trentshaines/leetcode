#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
    private:
        bool tryBuildRows(string& base, unordered_map<string, vector<char>>& up, string& cur, unordered_set<string>& failed){
            // if (failed.contains(base))
            //     return false;

            // If we built a row, try build the rest of the pyramid.
            if (cur.size() == base.size() - 1){
                // If we finished the pyramid, return true.
                if (cur.size() == 1)
                    return true;

                // If this row has already failed, give up.
                if (failed.contains(cur))
                    return false;

                // Try build the rest of the pyramid.
                string nextRow = "";
                auto canBuildRest = tryBuildRows(cur, up, nextRow, failed);

                // If it worked, it's an answer.
                if (canBuildRest) {
                  return true;
                }

                // If it failed, add to failed.
                else {
                    failed.insert(cur);
                    return false;
                }
            }

            // Test build every valid current row based on last row. Backtrack
            // should we use another function? Might be cleaner to do row backtrack + pyramid backtrack.
            bool canBuild = false;
            int l = cur.size();
            if( up[base.substr(l, 2)].empty())
                return false;
            for (char x: up[base.substr(l, 2)]){
                // consider all row assignments
                cur.push_back(x);
                canBuild |= tryBuildRows(base, up, cur, failed);
                cur.pop_back();
            }

            return canBuild;
        }

    public:
        bool pyramidTransition(string bottom, vector<string>& allowed) {
            // Is there ANY assignment of pyramid such that everything is in allowed
            // base <= 6, so there are at most 15 open spots, each with 6 possibilities. 
            // so we shouldn't do it that way.
            // DP to build each level?
            // Each bottom two defines a possible transition to a single one on the level above.
                // So it's backtracking + DP. but is there any DP? each sequence is different if we end up backtracking?
                // Well one thing that can be shared is the end of the sequence failing.
                // specifically, if we determine a particular row won't lead to the right answer, we can cache is as a pruned path.
            string cur_row = "";
            unordered_map<string, vector<char>> map_up;
            for(auto& a: allowed){
                map_up[a.substr(0,2)].push_back(a[2]);
            }

            unordered_set<string> failed_rows;
            return tryBuildRows(bottom, map_up, cur_row, failed_rows);
        }
    };