//link : https://practice.geeksforgeeks.org/problems/maximum-difference-between-node-and-its-ancestor/1/?track=amazon-trees&batchId=192
// we need to calculate root-ancestor maximum diff so for that we will return min val from the left, right, current root.
int fn(Node* root, int &sol)
{
    if(root==NULL)
        return INT_MAX;
    if(root->left==NULL&&root->right==NULL)
        return root->data;
    int l,r;
    l=fn(root->left,sol);
    r=fn(root->right,sol);
    int tmp=min(l,r);
    sol=max(sol,root->data-tmp);
    return min(root->data,tmp);
}
int maxDiff(Node* root)
{
    int sol=INT_MIN;
    fn(root,sol);
    return sol;
}
