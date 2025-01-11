Node *removeLoop(Node *head)
{
    Node* fast=head;
    Node* slow=head;
    bool isCycle=false;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            isCycle=true;
            break;
        }
    }
    if(isCycle){
        fast=head;
        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        Node* temp=fast;
        while(fast->next!=temp){
            fast=fast->next;
        }
        fast->next=NULL;
    }
    return head;
}
