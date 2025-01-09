bool isCircular(Node* head){
    if(head==NULL){
        return true;
    }
    int val=head->data;
    Node* fast=head;
    Node* slow=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            if(slow->data==val){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return false;
}
