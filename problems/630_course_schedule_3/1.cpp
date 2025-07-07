#include <queue>
#include <vector>
#include <algorithm>

class Solution {
public:
    int scheduleCourse(std::vector<std::vector<int>>& courses) {    
        // sort by max duration (implicit...)
        std::priority_queue<std::vector<int>> heap;

        // sort by end time.
        auto compare = [](const std::vector<int>& a, const std::vector<int>& b){
            return a[1] < b[1];
        };
        std::sort(courses.begin(), courses.end(), compare);

        // we want to keep the absolute minimum total duration, and we can assume we can take everything up to end time
        int totalTime = 0;
        for(auto& course: courses){
            totalTime += course[0];
            heap.push(course); // Add course to heap
            if(totalTime > course[1]){
                auto top = heap.top(); heap.pop();
                totalTime -= top[0];
            }
        }
    
        return heap.size();
    }
};