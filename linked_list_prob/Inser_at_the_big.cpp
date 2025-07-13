// ---------------------------------------------------*****------------------------------------------------------------------
// here we are writhing this code to - Insertion at the Bigning and then triversion of Linled List 


class Node{
public:
int data;
Node *next;
Node(int Value){
data = value;
next = NULL;
}
};
int main(){
Node *Head;
Head = NULL;

int arr[] = {20, 30, 40 ,2, 33, 1}
 for(int i=0; i<size.arr[]; i++){
if(Head = Null){
Head = new Node(arr[i]);
}
else{
Node* temp;
temp = new Node(arr[i]);
temp -> next = head;
head = temp;
}
}
Node *temp = Head;
while(temp){
cout<<temp-> data<<" ";
temp = temp -> next;
};
