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
