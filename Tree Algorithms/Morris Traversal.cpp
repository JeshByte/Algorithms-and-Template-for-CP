vector<int> inOrder(Node* root) {
    vector<int> res;
    Node* curr = root;

    while (curr != nullptr) {
        if (curr->left == nullptr) {
          

            res.push_back(curr->data);
            curr = curr->right;
        }
        else {
          

            Node* prev = curr->left;
            while (prev->right != nullptr &&
                                 prev->right != curr) {
                prev = prev->right;
            }


            if (prev->right == nullptr) {
                prev->right = curr;
                curr = curr->left;
            } 
            else {

                prev->right = nullptr;
                res.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return res;
}
