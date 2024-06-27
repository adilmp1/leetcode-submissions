    string serialize(TreeNode* root) {
        if (!root)
            return "[]";
        vector<string> ans;
        ans.push_back("[");
        queue<TreeNode*> q;
        q.push(root);
        ans.push_back(to_string(root->val));
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                q.push(node->left);
                ans.push_back(to_string(node->left->val));
            } else
                ans.push_back("null");

            if (node->right) {
                q.push(node->right);
                ans.push_back(to_string(node->right->val));
            } else
                ans.push_back("null");
        }
        ans.push_back("]");
        string final = "[";
        final += ans[1];
        for (int i = 2; i < ans.size(); i++) {
            final += ",";
            final += ans[i];
        }
        final += "]";
        return final;
    }

    TreeNode* deserialize(string data) {
        data = data.substr(1, data.size() - 2);
        stringstream ss(data);
        string token;
        getline(ss, token, ',');
        queue<TreeNode*> q;
        try {
            TreeNode* root = new TreeNode(stoi(token));
            q.push(root);

            while (!q.empty()) {
                TreeNode* node = q.front();
                q.pop();
                getline(ss, token, ',');
                if (token == "null") {
                    node->left = NULL;
                } else {
                    node->left = new TreeNode(stoi(token));
                    q.push(node->left);
                }
                getline(ss, token, ',');
                if (token == "null") {
                    node->right = NULL;
                } else {
                    node->right = new TreeNode(stoi(token));
                    q.push(node->right);
                }
            }
            return root;
        } catch (const invalid_argument& e) {
            return NULL;
        } catch (const out_of_range& e) {
            return NULL;
        }
        return NULL;
    }
