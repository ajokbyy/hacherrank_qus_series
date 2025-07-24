// ----------------------------------------code - if we got a long array then we have to make a tail-----------------------------------------------------------
#include <iostream>
using namespace std;
class Node{
public:
int data;
Node *next;
Node(int value){
value = data;
next = nullptr;
}
}
void InseartAtEnd(Node* &head, Node* tail, int val){
Node* newNode = newNode(val);
if(!head){
head = newNode;
tail = newNode;
}
else{
tail->next = newNode;
tail = newNode;
}
}
int main(){
Node*head = nullptr;
Node*tail = nullptr;
int arr[] = {10, 20, 30 ,40, 50};
int n = arr.size();

for(int i=0; i<n; i++){
InseartAtEnd(head, tail, arr[i]);
}
//print the linklist

while(head != nullptr){
cout<<head -> data<<"";
head = head-> next;
}
}

// -----------------------------------------------code - if we got a small array -------------------------------------------------------------------------------
struct Node{
int data;
Node *next;
Node(int val){
data = val;
next = nullptr;
}
}
// funtion of insertion
void insertAtEnd(Node* &head, int val){
Node* newNode = newNode(val);
if(head == nullptr){
head = newNode;
return;
}
Node* temp = head;
while(temp -> next != nullptr){
temp = temp ->next;
}
temp -> next = newNode;
}
int main(){
Node*head = nullptr;
insertAtEnd(head, 10);
// print the node
while(head != nullptr){
cout<<head -> data<<"";
head = head-> next;
}
}
--------------------------------------------------------------------------***--------------------------------------------------------------------------------
