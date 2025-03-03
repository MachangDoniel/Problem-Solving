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

 // using stack
class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            stack<int>st;
            ListNode* current=head;
            while(current!=nullptr){
                st.push(current->val);
                current=current->next;
            }
            ListNode* newHead=nullptr;
            if(st.empty()) return newHead;
            else {
                newHead=new ListNode(st.top());
                st.pop();
            }
            ListNode* temp=newHead;
            while(!st.empty()){
                ListNode* node=new ListNode(st.top());
                st.pop();
                temp->next=node;
                temp=node;
            }
            return newHead;
        }
    };


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

 // using 3 pointer
 class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            ListNode* prev=nullptr;
            ListNode* curr=head;
            ListNode* next=nullptr;
            while(curr!=nullptr){
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            return prev;
        }
    };


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

 // using recursion
class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            // base case
            if(head==nullptr || head->next==nullptr) return head;
            ListNode* newHead=reverseList(head->next);
            head->next->next=head;
            head->next=nullptr;
    
            return newHead;
        }
    };