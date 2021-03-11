//
// Created by Jolen on 2021/3/11.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
};

// reverse linked list through iteration
ListNode *reverse(ListNode *head, ListNode *last) {
    ListNode *pre, *cur, *nxt;
    pre = nullptr, cur = head, nxt = head;
    while (cur != last) {
        nxt = nxt->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    return pre;
}
//reverse  linked list through recursion
ListNode *reverse_cursion(ListNode *head, ListNode *last) {
    if(head==last or head->next==last)
        return head;
    ListNode *newhead = reverse_cursion(head->next,last);
    head->next->next=head;
    head->next= nullptr;
    return newhead;
}

//reverse k group linked list through recursion
ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *aa, *bb;
    aa = head, bb = head;
    for (int i = 0; i < k; i++) {
        if (bb == nullptr)
            return head;
        bb = bb->next;
    }
    ListNode *newhead = reverse_cursion(aa, bb);
    cout<<newhead->val<<endl;
    aa->next = reverseKGroup(bb, k);
    return newhead;
}

int main() {
    ListNode *a, *b, *c, *d;
    a = new ListNode;
    b = new ListNode;
    c = new ListNode;
    d = new ListNode;
    a->val = 5, b->val = 4, c->val = 3, d->val = 2;
    a->next = b, b->next = c, c->next = d;
    cout << "original list";
    for (ListNode *test = a; test != nullptr; test = test->next) {
        cout << test->val;
    }
    cout << endl << "reverse list:";
    ListNode *abc = reverseKGroup(a, 2);
    for (ListNode *test = abc; test != nullptr; test = test->next) {
        cout << test->val;
    }
    return 0;
}