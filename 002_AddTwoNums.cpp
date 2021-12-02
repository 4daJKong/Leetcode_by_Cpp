#include <iostream>
#include <list>
#include <map>
#include <string>
#include <algorithm>

using namespace std;


 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution{

    public:

        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            //ListNode *list_res = new ListNode;
            //list_res -> next = nullptr;
            
            int carry = 0;
            ListNode head = ListNode(0);
            ListNode *temp = &head;
            while (l1 || l2 || carry)
            {
                if (l1)
                {
                    carry = carry + l1->val;
                    l1 = l1 ->next;
                }
                if (l2)
                {
                    carry = carry + l2->val;
                    l2 = l2 ->next;
                }
                temp -> next = new ListNode(carry % 10);
                temp = temp -> next;                
                carry = carry / 10;
                
            }
            return head.next;       
    }
};

void ListNode_output(ListNode * list_input)
{
    while(list_input){
        cout << list_input->val << ' ';
        list_input = list_input->next;
    } 
    cout << endl;
}

int main()
{
    /*l1*/
    ListNode *l1_1 = new ListNode;
    l1_1 -> val = 2;
    l1_1 -> next = nullptr;
   
    ListNode *l1_2 = new ListNode;
    l1_2 -> val = 4;
    l1_2 -> next = nullptr;
    
    ListNode *l1_3 = new ListNode;
    l1_3 -> val = 3;
    l1_3 -> next = nullptr;

    l1_1 -> next = l1_2;
    l1_2 -> next = l1_3;

    /*l2*/
    ListNode *l2_1 = new ListNode;
    l2_1 -> val = 5;
    l2_1 -> next = nullptr;
   
    ListNode *l2_2 = new ListNode;
    l2_2 -> val = 6;
    l2_2 -> next = nullptr;
    
    ListNode *l2_3 = new ListNode;
    l2_3 -> val = 4;
    l2_3 -> next = nullptr;

    l2_1 -> next = l2_2;
    l2_2 -> next = l2_3;
        
    Solution Sol1;
    ListNode_output(Sol1.addTwoNumbers(l1_1, l2_1));    
    

    return 0;
}