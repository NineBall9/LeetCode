/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static const auto _____ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        return helper(l1, l2, 0);
    }
    
    ListNode* extraResolver(ListNode* node, int extra) {
        if (!node) {
            if (extra) {
                return new ListNode(extra);
            }
            return nullptr;
        }
        
        int sum = node->val + extra;
        int nextValue = sum % 10;
        int nextExtra = sum / 10;
        
        node->val = nextValue;
        node->next = extraResolver(node->next, nextExtra);
        
        return node;
    }
    
    ListNode* helper(ListNode* l1, ListNode* l2, int extra) {
        if (!l1 && !l2) {
            if (extra) {
                return new ListNode(extra);
            }
            return nullptr;
        }
        if (!l1) return extraResolver(l2, extra);
        if (!l2) return extraResolver(l1, extra);
        
        assert(l1 && l2);
        
        int sum = l1->val + l2->val + extra;
        int nextExtra = sum / 10;
        int nextValue = sum % 10;
            
        ListNode* node = new ListNode(nextValue);
        node->next = helper(l1->next, l2->next, nextExtra);
        
        return node;
    }
};
