#include <map>
#include <queue>
#include <iostream>

using namespace std;

typedef struct node {
    int data;
    node *left;
    node *right;
    node(int key){
        data = key;
        left = right = nullptr;
    }
}Node;

void bstLeftView(Node* root){
    cout<<"\nLeft View  :=> ";
    if(root != nullptr){
        queue<Node*> queue({root});
        while (!queue.empty()){
            int n = queue.size();
            for(int i=1; i<=n; i++){
                Node* temp=queue.front();
                queue.pop();

                if (i==1){
                    cout<<" "<<temp->data;
                }

                if (temp->left!=nullptr){
                    queue.push(temp->left);
                }
                if (temp->right!=nullptr){
                    queue.push(temp->right);
                }
            }
        }
    }
}

void bstRightView(Node* root){
    cout<<"\nRight View :=> ";
    if(root != nullptr){
        queue<Node*> queue({root});
        while(!queue.empty()){
            int n = queue.size();
            while(n--) {
                Node* temp=queue.front();
                queue.pop();

                if (n==0){
                    cout<<" "<<temp->data;
                }

                if (temp->left!=nullptr){
                    queue.push(temp->left);
                }
                if (temp->right!=nullptr){
                    queue.push(temp->right);
                }
            }
        }
    }
}

void bstTopView(Node* root){
    cout<<"\nTop View   :=> ";
    if(root != nullptr){
        int distance;
        Node* curr=nullptr;

        map<int, int> m;
        queue<pair<Node*,int>> queue;

        queue.push({root,0});
        while(!queue.empty()) {
            auto front = queue.front();
            queue.pop();

            curr = front.first;
            distance = front.second;

            if (m.find(distance)==m.end()){
                cout<<" "<<curr->data;
                m[distance] = curr->data;
            }

            if(curr->left!=nullptr) {
                queue.push({curr->left, distance-1});
            }
            if(curr->right!=nullptr) {
                queue.push({curr->right, distance+1});
            }
        }
    }
}

void bstBottomView(Node* node, int distance, int level, auto &m){
    if (node != nullptr) {
        if (level >= m[distance].second){
            m[distance] = {node->data, level};
        }
        bstBottomView(node->left, distance-1, level+1, m);
        bstBottomView(node->right, distance+1, level+1, m);
    }
}

void bstBottomView(Node* root){
    cout<<"\nBottom View:=> ";
    map<int, pair<int, int>> m;
    bstBottomView(root, 0, 0, m);
    for(auto iter : m) {
        cout<<" "<< iter.second.first;
    }
}

int main(){
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(11);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(15);

    bstLeftView(root);
    bstRightView(root);

    bstTopView(root);
    bstBottomView(root);

    return 0;
}

