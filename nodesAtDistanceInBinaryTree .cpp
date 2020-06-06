//Link : https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1/?track=amazon-trees&batchId=192


class solver
{
private:

public:
    // this fn is used to print all the nodes at k distance down from this node
    void KDistanceDown(Node* root, int k,vector <int>& sol)
    {

        if(root==NULL)
            return;
        // cout<<k<<'\t'<<root->data<<endl;
        if(k==0)
        {
            // cout<<"hello\n";
            sol.push_back(root->data);
            return;
        }
        KDistanceDown(root->left,k-1,sol);
        KDistanceDown(root->right,k-1,sol);
    }
    //This fn is used to find the node equal to target
    // 1. if the current node is equal to target then we print node at distance k from this node using KDistanceDown
    // 2. return value is -1 or dist-1 depending upon if the target was found or not. if we recieve return value from left call next call is made to right
    // else if the return value is recieved from right call next call is made to left depending upon dist left.
    int check(Node* root, int target , int k, vector <int>& sol)
    {

        if(root==NULL)
            return -1;
        if(root->data==target)
        {
            KDistanceDown(root,k,sol);
            return k-1;
        }
        int ld,rd;
        ld=check(root->left,target ,k,sol);
        if(ld!=-1)
        {
            if(ld==0)
            {
                sol.push_back(root->data);
                return -1;
            }
            KDistanceDown(root->right,ld-1,sol);
            return ld-1;
        }
        rd=check(root->right,target ,k,sol);
        if(rd!=-1)
        {
            if(rd==0)
            {
                sol.push_back(root->data);
                return -1;
            }
            KDistanceDown(root->left,rd-1,sol);
            return rd-1;
        }
        return -1;
    }
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        vector <int> sol;
        check(root,target ,k,sol);
        sort(sol.begin(),sol.end());
        return sol;
    }
};
