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
private:
    string serializeSolution1(TreeNode *root) {
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
    TreeNode* deserializeSolution1(string data) {
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
    void serializeSolution2Helper(TreeNode *root, string &ans) {
        if(root == nullptr) {
            ans.append("#,");
            return;
        }
        ans.append(to_string(root->val)).push_back(',');
        serializeSolution2Helper(root->left, ans);
        serializeSolution2Helper(root->right, ans);
    }
    string serializeSolution2(TreeNode *root) {
        string ans{""};
        serializeSolution2Helper(root, ans);
        return ans;
    }
    void deserializeSolution2Helper(TreeNode *parent, istringstream &iss, bool isLeft) {
        string value;
        getline(iss, value, ',');
        if(value == "#") return;
        if(isLeft) {
            parent->left = new TreeNode(stoi(value));
            deserializeSolution2Helper(parent->left, iss, true);
            deserializeSolution2Helper(parent->left, iss, false);
        } else {
            parent->right = new TreeNode(stoi(value));
            deserializeSolution2Helper(parent->right, iss, true);
            deserializeSolution2Helper(parent->right, iss, false);
        }
    }
    TreeNode* deserializeSolution2(string data) {
        TreeNode parent;
        istringstream iss(data);
        deserializeSolution2Helper(&parent, iss, true);
        return parent.left;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // return serializeSolution1(root);
        return serializeSolution2(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // return deserializeSolution1(data);
        return deserializeSolution2(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));