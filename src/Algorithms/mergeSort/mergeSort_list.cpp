struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *split(ListNode *head)
{
    ListNode *slow, *fast;
    slow = fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        if (fast != nullptr)
        {
            slow = slow->next;
        }
    }

    ListNode *temp = slow->next;
    slow->next = nullptr;
    return temp;
}

ListNode *merge(ListNode *first, ListNode *second)
{
    if (first == nullptr)
        return second;
    if (second == nullptr)
        return first;

    if (first->val < second->val)
    {
        first->next = merge(first->next, second);
        return first;
    }
    else
    {
        second->next = merge(first, second->next);
        return second;
    }
}

ListNode *mergeSort(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    // mergeSort
    ListNode *last = split(head);

    head = mergeSort(head);
    last = mergeSort(last);
    return merge(head, last);
}

int main()
{
    ListNode *arr = new ListNode(10);

    arr->next = new ListNode(23);
    arr->next->next = new ListNode(4);
    arr->next->next->next = new ListNode(12);
    arr->next->next->next->next = new ListNode(5);
    arr->next->next->next->next->next = new ListNode(1);

    arr = mergeSort(arr);

    delete arr->next->next->next->next->next;
    delete arr->next->next->next->next;
    delete arr->next->next->next;
    delete arr->next->next;
    delete arr->next;
    delete arr;

    return 0;
}