class Solution {
public:
    ListNode* deleteMiddle(ListNode* head)

    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
       if (head == nullptr || head->next == nullptr) {
        // If the list is empty or has only one node, return nullptr after deleting the single node
        delete head;
        return nullptr;
    }
    
    ListNode* previous = nullptr;
    ListNode* slower = head;
    ListNode* faster = head;

    while (faster != nullptr && faster->next != nullptr) {
        previous = slower;
        slower = slower->next;
        faster = faster->next->next;
    }  

    // Remove the middle node
    if (previous != nullptr) {
        previous->next = slower->next;
    }
    delete slower;

    return head;
    }
};