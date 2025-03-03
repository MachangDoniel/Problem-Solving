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
    
        void print(ListNode* head){
            while(head!=nullptr){
                cout<<head->val<<"->";
                head=head->next;
            }
            cout<<"nullptr"<<endl;
        }
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode* head;
            if(list1==nullptr) return list2;
            else if(list2==nullptr) return list1;
            if(list1->val<=list2->val){
                head=new ListNode(list1->val);
                list1=list1->next;
            }
            else {
                head=new ListNode(list2->val);
                list2=list2->next;
            }
            
            ListNode* current=head;
            while(list1!=nullptr && list2!=nullptr){
                if(list1->val<=list2->val){
                    ListNode* node=new ListNode(list1->val);
                    current->next=node;
                    current=node;
                    list1=list1->next;
                }
                else{
                    ListNode* node=new ListNode(list2->val);
                    current->next=node;
                    current=node;
                    list2=list2->next;
                }
            }
            if(list1!=nullptr){
                current->next=list1;
            }
            else{
                current->next=list2;
            }
            // print(head);
            return head;
        }
    };