#include <iostream>

using namespace std;

typedef struct listNode {
    int data;
    listNode *next;
    listNode(int value){
        data = value;
        next = nullptr;
    }
}ListNode;

typedef struct treeNode {
    int data;
    treeNode *left, *right;
    treeNode(int value){
        this->data = value;
        left = right = nullptr;
    }
}TreeNode;

void printLinkedList(ListNode* node){
    ListNode* curr = node;
    while(curr != nullptr){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
}

int countListNode(ListNode* node){
    int count = 0;
    ListNode* curr = node;
    while(curr != nullptr){
        count = count+1;
        curr = curr->next;
    }
    return count;
}

void printInOder(TreeNode* node){
    if(node != nullptr){
        printInOder(node->left);
        cout<<node->data<<" ";
        printInOder(node->right);
    }
}

void printPreOder(TreeNode* node){
    if(node != nullptr){
        cout<<node->data<<" ";
        printPreOder(node->left);
        printPreOder(node->right);
    }
}

TreeNode* listToBST(ListNode** headref, int n){
    if(n <= 0){
        return nullptr;
    }

    int mid = n >> 1;
    TreeNode* left = listToBST(headref, mid);

    TreeNode *root = new TreeNode((*headref)->data);
    root->left = left;

    (*headref) = (*headref)->next;
    root->right = listToBST(headref, n-mid-1);

    return root;
}

int main(){
    ListNode* head = new ListNode(7);
    head->next = new ListNode(6);
    head->next->next = new ListNode(5);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = new ListNode(1);

    cout<<"[Sorted Linked List]: ";
    printLinkedList(head);

    int n = countListNode(head);
    TreeNode *root = listToBST(&head, n);

    cout << "\nIn Order[BinaryTree]: ";
    printInOder(root);
    cout << "\nPreOrder[BinaryTree]: ";
    printPreOder(root);

    return 0;
}

