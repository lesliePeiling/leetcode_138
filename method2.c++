/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/


using namespace std;
class Solution {
    
    
public:
    void addInBetweenNode(Node* head){
        while(head){
            Node* addNode =new Node();
            addNode->next =head->next;
            head->next    =addNode;
            addNode->val  = head->val;
            head          =addNode->next;
        }
    }
    
    
    void fillAddInBetweenNodeRandom(Node* head){
        while(head){
            if(head->random==NULL){
                head->next->random=NULL;   
            }else{
                head->next->random=head->random->next;}
            head=head->next->next;
        }
    }
    
    Node* DeletOriginalNode(Node* head){
        
        Node* out= head->next;
        while(head){ 
            
            Node* head_out= head->next->next;
            
            if(head->next->next){
                head->next->next=head->next->next->next;
            }
            head->next= head_out;
            
            head=head_out;
        }
        return out;
    }
    
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        addInBetweenNode(head);
        fillAddInBetweenNodeRandom(head);
        return DeletOriginalNode(head);

    }
    
    
};