#include<bits.h\studio>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(nullptr){

    }
};
ListNode* head = new ListNode(1);
head->next = new ListNode(2);