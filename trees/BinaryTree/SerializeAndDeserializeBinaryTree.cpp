#include <bits/stdc++.h>

using namespace std;

typedef struct node
{
    int data;
    node *left;
    node *right;
    node(int key)
    {
        this->data = key;
        this->left=this->right=nullptr;
    }
}Node;

void InOrderTraversal(Node* node)
{
    if(node != nullptr)
    {
        InOrderTraversal(node->left);
        cout<<" "<<node->data;
        InOrderTraversal(node->right);
    }
}

void serialize(Node* root, ostringstream& out)
{
    if (root != nullptr)
    {
        out << root->data << ' ';
        serialize(root->left, out);
        serialize(root->right, out);
    }
    else
    {
        out << "# ";
    }
}

string serialize(Node* root)
{
    ostringstream out;
    serialize(root, out);
    return out.str();
}

Node* deserialize(istringstream& in)
{
    string key;
    in >> key;
    if (key == "#")
    {
        return nullptr;
    }

    Node* root = new Node(stoi(key));
    root->left = deserialize(in);
    root->right = deserialize(in);
    return root;
}

Node* deserialize(string data)
{
    istringstream in(data);
    return deserialize(in);
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);
    cout<<"Tree [in-order] ="; InOrderTraversal(root);

    string str = serialize(root);
    cout<<"\nSerialized Tree = "<<str;

    Node* xroot = deserialize(str);
    cout<<"\nTree [in-order] ="; InOrderTraversal(xroot);

    return 0;
}