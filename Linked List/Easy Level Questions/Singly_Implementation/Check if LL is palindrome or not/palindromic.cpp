/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *reversing(ListNode *head)
    {
        ListNode *previous=nullptr;
        ListNode *current=head;

        while(current!=nullptr)
        {
            ListNode *next=current->next;
            current->next=previous;
            previous=current;
            current=next;
        }

        return previous;
    }
    bool isPalindrome(ListNode* head) 
    {
      //first we will find the middle point using the floyd cycle finding
      //algorithm.....

      ListNode *slow=head;
      ListNode *fast=head;

      while(fast!=nullptr and fast->next!=nullptr)
      {
        slow=slow->next;
        fast=fast->next->next;
      }

      ListNode *rev=reversing(slow);

      while(rev!=nullptr)
      {
        if(head->val!=rev->val)
        {
            return false;
        }

        head=head->next;
        rev=rev->next;
      }    
      return true;
    }
};