 ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
      if (head == nullptr) {
        return nullptr;
    }

    ListNode* fast = head;
    for (int i = 0; i < n; i++) {
        if (fast == nullptr) {
            return nullptr; // n is greater than the length of the list
        }
        fast = fast->next;
    }

    // If fast is nullptr, n is exactly the length of the list, we need to remove the head
    if (fast == nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    ListNode* slow = head;
    ListNode* previous = nullptr;

    while (fast != nullptr) {
        previous = slow;
        slow = slow->next;
        fast = fast->next;
    }

    if (previous != nullptr) {
        previous->next = slow->next;
    }
    delete slow;
    return head;
    }