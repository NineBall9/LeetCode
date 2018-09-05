/**
下面这种方法使用递归来实现的，我们知道递归其实也是用栈来保存每一个状态，那么也就可以实现从后往前取数字，我们首先统计出两个链
表长度，然后根据长度来调用递归函数，需要传一个参数差值，递归函数参数中的l1链表长度长于l2，在递归函数中，我们建立一个节点res，
如果差值不为0，节点值为l1的值，如果为0，那么就是l1和l2的和，然后在根据差值分别调用递归函数求出节点post，然后要处理进位，如
果post的值大于9，那么对10取余，且res的值自增1，然后把pos连到res后面，返回res，最后回到原函数中，我们仍要处理进位情况，参见代码如下：
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = getLength(l1), n2 = getLength(l2);
        ListNode *head = new ListNode(1);
        head->next = (n1 > n2) ? helper(l1, l2, n1 - n2) : helper(l2, l1, n2 - n1);
        if (head->next->val > 9) {
            head->next->val %= 10;
            return head;
        }
        return head->next;
    }
    int getLength(ListNode* head) {
        int cnt = 0;
        while (head) {
            ++cnt;
            head = head->next;
        }
        return cnt;
    }
    ListNode* helper(ListNode* l1, ListNode* l2, int diff) {
        if (!l1) return NULL;
        ListNode *res = (diff == 0) ? new ListNode(l1->val + l2->val) : new ListNode(l1->val);
        ListNode *post = (diff == 0) ? helper(l1->next, l2->next, 0) : helper(l1->next, l2, diff - 1);
        if (post && post->val > 9) {
            post->val %= 10;
            ++res->val;
        }
        res->next = post;
        return res;
    }
};
