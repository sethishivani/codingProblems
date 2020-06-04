//Link:  https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1/?track=amazon-trees&batchId=192

// the DLL is build in 2 parts:
//1. create a linked list with left pointers set using inorder traversal
//2. create DLL, first from root go to right-most node that will be the last node in DLL. Now from there making use of already set
//left ptrs for traversal set the right ptrs as well.
void lt(Node *root,Node **prev)
{
    if(root==NULL)
        return;
    lt(root->left,prev);
    root->left=*prev;
    *prev=root;
    lt(root->right,prev);
}
void rt(Node *root, Node **head_ref)
{
    Node *ptr=root;
    while(ptr->right!=NULL)
        ptr=ptr->right;
    Node *prev=ptr->left;
    while(prev!=NULL)
    {
        prev->right=ptr;
        ptr=prev;
        prev=prev->left;
    }
    *head_ref=ptr;
}
void bToDLL(Node *root, Node **head_ref)
{
    Node *prev=NULL;
    lt(root,&prev);
    rt(root,head_ref);
}
