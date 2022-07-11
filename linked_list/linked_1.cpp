/*
    Add 2 number
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

void insertAtHead(Node* &head , int insert){
    Node* temp = new Node(insert);
    if(head == NULL){
        head = temp;
        return;
    }
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &head , int insert){
    Node* ele = new Node(insert);
    if(head == NULL){
        head = ele;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = ele;
    ele->next = NULL;
}

void printLinkedList(Node* &head){
    cout<<"null"<<endl;
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void reverseAList(Node* &head){
    if(head->next == NULL){
        return;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* future = head; 

    while(curr!=NULL){
        future = future->next;
        curr->next = prev;
        prev = curr;
        curr = future;
    }
    head = prev;

    //wooh reversed
}

void AddTwoNumbers(Node* &head1 , Node* &head2)
{
    //add 2 numbers 
    // thsi is again wrong I dont know why ?? lets see
 
    Node* head = new Node(-1);
    Node* headret = head;
    reverseAList(head1);
    reverseAList(head2);
    printLinkedList(head1);
    printLinkedList(head2);
    int carry=0;
    while (head1 != NULL && head2 != NULL)
    {
        int a1 = head1->data;
        int a2 = head2->data;
        cout<<a1<<a2<<endl;
        int sum = a1+a2+carry;
        carry  = sum/10;
        int dataNode = sum%10;
        Node* insertdataNode = new Node(dataNode);
        cout<<insertdataNode->data<<" ";
        head->next = insertdataNode;
        head1 = head1->next;
        head2 = head2->next;
        head = head->next;

    }
    while(head1 != NULL && head2 == NULL){
        int sum = carry + head1->data;
        carry = sum/10;
        int dataNode = sum%10;
        Node* newNode = new Node(dataNode);
        head->next = newNode;
        head = head->next;
        head1 = head1->next;
    }

    while(head1 == NULL && head2 != NULL)
    {
        int sum = carry + head2->data;
        carry = sum/10;
        int dataNode = sum%10;
        head->next = new Node(dataNode);
        head2 = head2->next;
        head = head->next;
    }

    if(head1 == NULL && head2 == NULL && carry !=0){
        Node* newnode = new Node(carry);
        head->next = newnode;
        
    }
    printLinkedList(headret->next);
}

Node* reverseMyList(Node* &head , int k)
{
    //iteratively reverse my list
    //reverse linked list in k nodes
    if(head == NULL){
        return NULL;
    }
    
    Node* prev = NULL;
    Node* curr = head;
    Node* futu = head;
    int cnt = 0;
    while (cnt<k && curr != NULL)
    {
        cnt++;
        futu = curr->next;
        curr->next = prev;
        prev = curr;
        curr = futu;
    }
    head->next = reverseMyList(futu ,k);
    return prev;
    
}

//LC - 143 
//many methods are possible just choose the best one out of them 
void ReorderList(Node* head)
{
    // assumption duplicates doesnt exists 
    /*
    stack<int> OrderMaintain;

    Node* temp = head;
    while(temp != NULL)
    {
        cout<<"no"<<" ";
        OrderMaintain.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    Node* futu = head;

    while(temp->data != OrderMaintain.top() && temp->next->data != OrderMaintain.top())
    {
        cout<<"yes"<<" ";
        futu = temp->next;
        Node* newNode = new Node(OrderMaintain.top());
        OrderMaintain.pop();
        temp->next = newNode;
        newNode->next = futu;
        temp = futu;
    }    
    if(temp->next->data == OrderMaintain.top())
    {
        temp = temp->next;
    }
    temp->next = NULL;
    printLinkedList(head);
    */

   Node * temp = head;
    stack<Node* > OrderMaintain;
     while(temp != NULL)
    {
        cout<<"no"<<" ";
        OrderMaintain.push(temp);
        temp = temp->next;
    }

    temp = head;
    Node* futu = head;

    while(temp!= OrderMaintain.top() && temp->next!= OrderMaintain.top())
    {
        cout<<"yes"<<" ";
        futu = temp->next;
        Node* newNode = OrderMaintain.top();
        temp->next = OrderMaintain.top();
        OrderMaintain.pop();
        newNode->next = futu;
        temp = futu;
    }    
    if(temp->next == OrderMaintain.top())
    {
        temp = temp->next;
    }
    temp->next = NULL;
    printLinkedList(head);
}



int main(){
    Node* head = NULL;
    insertAtTail(head , 2);
    insertAtTail(head , 3);
    insertAtTail(head , 4);
    insertAtTail(head , 9);
    insertAtTail(head , 5);
    insertAtTail(head , 4);
    insertAtTail(head , 9);
    // insertAtTail(head , 6);
    cout<<"linked list ";
    printLinkedList(head);
    // printLinkedList(head);
    
    // Node* head3 = NULL;
    
    // insertAtTail(head3 , 9);
    // insertAtTail(head3 , 9);
    // insertAtTail(head3 , 9);
    // insertAtTail(head3 , 4);
    // printLinkedList(head3);
    // cout<<"adding 2 numbers "<<endl;
    // AddTwoNumbers(head , head3);

    // Node* reversed = reverseMyList(head , 2);
    // printLinkedList(reversed);
    cout<<"reorder list";
    ReorderList(head);
    cout<<"listed";
    return 0;
}