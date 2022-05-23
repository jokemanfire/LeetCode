#include"global.h"


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Codec {
public:
    string R;
    int max;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        R += to_string(root->val);
        R += " ";
        if (root->left != nullptr)
            serialize(root->left);
        if (root->right != nullptr)
            serialize(root->right);     
        return R;

    }

    TreeNode * GetTree(vector<int>& Rs,int index)
    {
        if (index == Rs.size())
            return nullptr;
        else
        {
            TreeNode* t = new TreeNode(Rs[index]);
            int temp_max = max;
            max = t->val;
            if (index+1<Rs.size() && Rs[index+1] < t->val)
            {
                t->left = GetTree(Rs, index+1);
            }
            if (index + 1 > Rs.size() && Rs[index + 1] > t->val && Rs[index + 1] < max)
            {
                t->right = GetTree(Rs, index + 1);
            }

            max = temp_max;
            return t;

        }
       
       

            
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << data << endl;
        stringstream d;
        vector<int> Rs;
        int temp;
        d.str(data);
        while (d>>temp)
        {
            Rs.push_back(temp);
            cout << temp << endl;
        }
      
        TreeNode* root = GetTree(Rs, 0);

        return root;
    }
};

int main()
{
    TreeNode* n = new TreeNode(2);
    n->left = new TreeNode(1);
    n->right = new TreeNode(3);
    Codec * a = new Codec;
    string b = a->serialize(n);
    a->deserialize(b);
}

