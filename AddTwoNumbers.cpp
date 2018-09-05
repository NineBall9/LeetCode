//第一次做，不能考虑指向空指针的情况
-------------


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * p1 = l1;
        ListNode * p2 = l2;
        if(p1 == NULL) return l2;
        if(p2 == NULL) return l1;
        while(p1 && p2){
            
            if(p1->val + p2->val < 10){
                p2 -> val += p1 -> val;
            }
            else{
                p2 -> val += p1 -> val - 10;
                p2 -> next -> val += 1;
            }
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        return l2;
    }
};




//第二次 可以解决问题，但是时间效率太低了
--------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head1 = l1;
        ListNode *head2 = l2;
        ListNode *temp = l1;
        ListNode *returnList = l1Longer(l1, l2) ? l1 : l2;
        ListNode *shortList = l1Longer(l1, l2) ? l2 : l1;
        bool full = false;
        while(returnList && shortList){
            if(full) returnList->val = returnList->val + shortList->val + 1;
            else returnList->val += shortList->val;
            if(returnList->val > 9){
                returnList->val = returnList->val % 10;
                full = true;
            }
            else full = false;
            temp = returnList;
            returnList = returnList->next;
            shortList = shortList->next;
        }
        if(!returnList && full){
            ListNode *newNode = new ListNode(0);
            newNode->val += 1;
            temp->next = newNode;
        }
        else if( returnList && full){
            returnList->val += 1;
            while(returnList->val > 9){
                if(returnList->next){
                    returnList->val = returnList->val % 10;
                    returnList->next->val += 1;
                    returnList = returnList->next;
                }
                else{
                    returnList->val = returnList->val % 10;
                    ListNode *addNew = new ListNode(0);
                    addNew->val += 1;
                    returnList->next = addNew;
                    returnList = returnList->next;
                }
            }
        }
        return l1Longer(l1, l2) ? head1 : head2;
    }
    bool l1Longer(ListNode *l1, ListNode *l2){
        int length1 = 0;
        int length2 = 0;
        while(l1){
            length1 += 1;
            l1 = l1->next;
        }
        while(l2){
            length2 += 1;
            l2 = l2->next;
        }
        return length1 >= length2 ? true : false;
    }
};



// 方法3  创建新的链表
----------------

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        int full = 0;
        while(l1 || l2){
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + full;
            if(sum > 9){
                full = 1;
                sum = sum % 10;
            }
            else full = 0;
            p->next = new ListNode(sum);
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            p = p->next;
        }
        if(full){
            p->next = new ListNode(1);
        }
        return head->next;
    }
};
