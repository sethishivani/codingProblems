//Link:  https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/

// in this qn we keep checking when we reach the end of a path i.e. leaf we count the number of
//occurrences of each element then we see how many elements had odd count, that gives us the answer
// if the current path will give up a pseudo-palindrome path or not
void fn(TreeNode* root,vector<int> &count,int &total)
{
    if(root==NULL)
        return;
    if(root->left==NULL&&root->right==NULL)
    {
        count[root->val]+=1;
        int odd=0;
        for(int i=1;i<10;i++)
        {
            if(count[i]%2==1)
                odd++;
        }
        if(odd<=1)
            total+=1;
        count[root->val]-=1;
        return;
    }
    count[root->val]+=1;
    fn(root->left,count,total);
    fn(root->right,count,total);
    count[root->val]-=1;
}
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> count(10,0);
        int total=0;
        fn(root,count,total);
        return total;
    }
};
