class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return NULL;
        if(head->next == nullptr) return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr != nullptr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        head = prev;
        return head;
    }
};