/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};  */
void inorderhelper(Node* root, vector<int>&ans){
    if(root == nullptr){
        return;
    }
    inorderhelper(root->left, ans);
    ans.push_back(root->data);
    inorderhelper(root->right, ans);
    // return ans;
}
int findCeil(Node* root, int input) {
    // Your code here
    // inorder traversing 
    // Bruth fource 
    vector<int> ans;
    inorderhelper(root, ans);
    for(int i=0; i<ans.size(); i++){
        if(ans[i]==input){
            return ans[i];
        }
        else{
            if(ceil(input) == ans){
                return ans[i];
            }
        }
    }return -1;
}

// ------------------------------------------------------------kind of bruth force ------------------------------------------------------------------------------
