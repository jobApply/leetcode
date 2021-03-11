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
// reverse front N linked list
ListNode *succussor = nullptr;

ListNode *reverseN(ListNode *head,int n){
    if (n==1){
        succussor = head->next;
        return head;
    }
    ListNode *last = reverseN(head->next,n-1);
    head->next->next = head;
    head->next= succussor;
    return last;
}

// revervse linked list between left and right
ListNode *reverseBetween(ListNode *head, int left, int right) {
    if(left==1)
        return reverseN(head,right);
    head->next=reverseBetween(head->next,left-1,right-1);
    return head;
}

int main() {
    ListNode *a, *b, *c, *d;
    a = new ListNode;
    b= new ListNode;
    c = new ListNode;
    d = new ListNode;
    a->val = 5, b->val = 4, c->val = 3, d->val = 2;
    a->next = b, b->next = c, c->next = d;
    cout<<"original list";
    for (ListNode *test = a; test != nullptr; test = test->next) {
        cout<<test->val;
    }
    cout<<endl<<"reverse list:";
    ListNode *abc =reverseBetween(a,2,3) ;

    for (ListNode *test = abc; test != nullptr; test = test->next) {
        cout<<test->val;
    }
    return 0;
}
