#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

class Solution {
    unordered_map<string, vector<char>> transitions;
    unordered_set<string> failedRows;

    // -------- Row Backtrack --------
    // Build the next row above `base` one character at a time (left -> right).
    // When a full next row is built, hand it to level backtrack.
    bool rowBacktrack(const string& base, int i, string& next) {
        // If we've filled next row (length = base.size() - 1), try to solve from it.
        if (i == (int)base.size() - 1) {
            return levelBacktrack(next);
        }

        // Look up allowed tops for pair base[i..i+1].
        auto it = transitions.find(base.substr(i, 2));
        if (it == transitions.end()) {
            // No transitions for this pair -> this partial next row is a dead branch.
            return false;
        }

        for (char c : it->second) {
            next.push_back(c);
            if (rowBacktrack(base, i + 1, next)) return true;  // short-circuit on success
            next.pop_back();
        }
        return false;  // none of the choices at position i worked
    }

    bool levelBacktrack(const string& base) {
        // If we're already at the top, success.
        if (base.size() == 1) return true;

        // If this row is known to fail, prune immediately.
        if (failedRows.count(base)) return false;

        // Generate all possible next rows above `base` and recurse.
        string next;
        bool ok = rowBacktrack(base, 0, next);

        // If no next-row leads to a solution, remember that `base` is bad.
        if (!ok) failedRows.insert(base);
        return ok;
    }

public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        transitions.clear();
        failedRows.clear();

        // Build pair->tops map.
        transitions.reserve(allowed.size());
        for (const auto& a : allowed) {
            transitions[a.substr(0, 2)].push_back(a[2]);
        }

        return levelBacktrack(bottom);
    }
};
