#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int key) : val(key), left(nullptr), right(nullptr) {}
};

class CBTInserter
{
    vector<TreeNode*> bTree;

  public:
    CBTInserter(TreeNode* root)
    {
        bTree.push_back(root);
        for(int i=0; i<bTree.size(); ++i)
        {
            if (bTree[i]->left != nullptr){
                bTree.push_back(bTree[i]->left);
            }
            if (bTree[i]->right != nullptr){
                bTree.push_back(bTree[i]->right);
            }
        }
    }

    int insert(int value)
    {
        int n = bTree.size();
        bTree.push_back(new TreeNode(value));

        if (n%2 == 1)
        {
            bTree[(n-1)/2]->left = bTree[n];
        }
        else
        {
            bTree[(n-1)/2]->right = bTree[n];
        }
        
        //return parent node value
        return bTree[(n-1)/2]->val;
    }

    TreeNode* get_root()
    {
        return bTree[0];
    }
};

int main(){
    cout<<"Complete BT Inserter";

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);

    CBTInserter cBTInserter(root);

    cout<<"\nInserted => "<<cBTInserter.insert(3); // 1
    cout<<"\nInserted => "<<cBTInserter.insert(4); // 2
    cout<<"\nTreeRoot => "<<cBTInserter.get_root()->val;

    return 0;
}