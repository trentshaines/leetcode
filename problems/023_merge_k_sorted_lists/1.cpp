#include <queue>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        auto compareListNode = [](ListNode* a, ListNode* b){
            return a->val > b->val;
        };        

        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(compareListNode)> heap(compareListNode);

        for (const auto& list: lists){
            if(list)
                heap.push(list);
        }

        ListNode* dummyHead = new ListNode();
        ListNode* cur = dummyHead;

        while(!heap.empty()){
            auto top= heap.top();
            heap.pop();
            cur->next = top;
            if(top->next)
                heap.push(top->next);
            cur = cur->next;
        }

        return dummyHead->next;
    }
};