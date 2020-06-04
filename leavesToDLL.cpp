//Link:  https://practice.geeksforgeeks.org/problems/leaves-to-dll/1/?track=amazon-trees&batchId=192

//we need to disconnect the leaves from the tree after turning them into the DLL.
//we keep storing the previous leaf in prev so that when we find next lea we make necessary edits for DLL
Node *fn(Node *root, Node **head_ref,Node **prev)
{
    if(root==NULL)
        return NULL;
    if(root->left==root->right&&root->right==NULL){
        // to disconnect a node from the tree we return a NULL from a leaf.
        if(*prev!=NULL)
            (*prev)->right=root;
        else
            *head_ref=root;
        root->left=*prev;
        *prev=root;
        return NULL;
    }
    root->left=fn(root->left,head_ref,prev);
    root->right=fn(root->right,head_ref,prev);
}
Node *convertToDLL(Node *root, Node **head_ref) {
    Node *prev=NULL;
    fn(root,head_ref,&prev);
    Node *tmp=*head_ref;
    return root;

}
