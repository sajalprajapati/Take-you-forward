ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        // Priority queue to store the nodes, sorted by their value
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        // Push the head of each non-empty list into the priority queue
        for(int i = 0; i < lists.size(); i++)
        {
            if(lists[i])
            {
                pq.push({lists[i]->val, lists[i]});
            }
        } 

        // Dummy node to act as the head of the merged list
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        // Merge the nodes into one sorted list
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            // Attach the node to the merged list
            temp->next = it.second;
            temp = temp->next;

            // If there is a next node, push it into the priority queue
            if(it.second->next)
            {
                pq.push({it.second->next->val, it.second->next});
            }
        }    

        // Return the merged list, excluding the dummy head
        return dummyNode->next;
    }