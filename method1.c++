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


#include <iostream>
#include <string>
#include <map>

using namespace std;
class Solution {
    map<Node*, Node*> mapPtr;
    map<Node*, Node*>::iterator iter;
    
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)return NULL;
        
        Node* ptrCurrent_out=new Node();
        
        //getNodeValue   
        ptrCurrent_out->val = head->val;
        //insert pair to map
        mapPtr.insert(pair<Node*, Node*>( head , ptrCurrent_out));
        //getNodeNext    
        ptrCurrent_out->next =copyRandomList(head->next);
        
        //getNodeRandom
        if(head->random==NULL) ptrCurrent_out->random=NULL;
        else{
        iter = mapPtr.find(head->random);
        ptrCurrent_out->random  = iter->second;
        }
        return ptrCurrent_out;

    }
    
    
};