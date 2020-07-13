//Link:  https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1

Node* LCA(Node* root,int a, int b)
{
    if(root==NULL)
        return NULL;
    if(root->data==a||root->data==b)
        return root;
    Node* lt=LCA(root->left,a,b);
    Node* rt=LCA(root->right,a,b);
    if(lt!=NULL&&rt!=NULL)
        return root;
    if(lt==NULL)
        return rt;
    return lt;
}
int findDepth(Node* root, int a,int dep)
{
    if(root==NULL)
        return -1;
    if(root->data==a)
        return dep;
    int lt=findDepth(root->left,a,dep+1);
    if(lt!=-1)
        return lt;
    int rt=findDepth(root->right,a,dep+1);
    return rt;
}
int findDist(Node* root, int a, int b) {
    Node* lca=LCA(root,a,b);
    // cout<<lca->data<<endl;
    int d1=findDepth(lca,a,0);
    int d2=findDepth(lca,b,0);
    return d1+d2;
}
