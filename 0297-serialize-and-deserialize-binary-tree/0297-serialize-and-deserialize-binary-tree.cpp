/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode *> qu;
        qu.push(root);
        string str{""};
        TreeNode *front;
        while(!qu.empty()) {
            front = qu.front(), qu.pop();
            if(front) {
                str.append(to_string(front->val)).push_back(',');
                qu.push(front->left);
                qu.push(front->right);
            } else {
                str.append("#,");
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data[0] == '#') return nullptr;
        istringstream iss(data);
        string value;
        getline(iss, value, ',');
        TreeNode *root = new TreeNode(stoi(value));
        queue<TreeNode *> qu;
        qu.push(root);
        TreeNode *front, *left, *right;
        while(!qu.empty()) {
            front = qu.front(), qu.pop();
            getline(iss, value, ',');
            if(value != "#") {
                front->left = new TreeNode(stoi(value));
                qu.push(front->left);
            }
            getline(iss, value, ',');
            if(value != "#") {
                front->right = new TreeNode(stoi(value));
                qu.push(front->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));