#include <map>
#include <queue>
#include <iostream>

using namespace std;

typedef struct node {
    char data;
    int frequency;
    node *left, *right;
    node(char iKey, int iFrequency){
        this->data = iKey;
        this->frequency = iFrequency;
        this->left = this->right = nullptr;
    }
}Node;

class compare{
  public:
    bool operator()(Node* left, Node* right){
        return (left->frequency) > right->frequency;
    }
};

Node* buildHuffmanTree(string iStr){
    map<char, int> mFrequency;
    for(int i=0; i<iStr.size(); i++){
        mFrequency[iStr[i]]++;
    }

    priority_queue<Node*, vector<Node*>, compare> minHeap;
    for(auto iter=mFrequency.begin(); iter!=mFrequency.end(); ++iter){
        minHeap.push(new Node(iter->first, iter->second));
    }

    Node *node, *left, *right;
	while (minHeap.size()>1) {
	    left = minHeap.top(); minHeap.pop();
	    right = minHeap.top(); minHeap.pop();

	    node = new Node('$', left->frequency+right->frequency);
	    node->left = left;
	    node->right = right;

	    minHeap.push(node);
	}
	return minHeap.top();
}

void printHuffmanCodesTree(Node* root, string str){
    if (root != nullptr){
        if (root->data != '$'){
            cout<<root->data<<": "<<str<<"\n";
        }
        printHuffmanCodesTree(root->left,  str+"0");
        printHuffmanCodesTree(root->right, str+"1");
    }
}

void storeHuffmanCodes(Node* root, string str, map<char, string>& mCodes){
	if (root != nullptr){
	    if (root->data != '$'){
	        mCodes[root->data]=str;
	    }
	    storeHuffmanCodes(root->left,  str+"0", mCodes);
	    storeHuffmanCodes(root->right, str+"1", mCodes);
	}
}

string HuffmanEncode(Node* root, string iStr){
    map<char, string> mCodes;
    storeHuffmanCodes(root, "", mCodes);

    string strEncoded = "";
    for(int i=0; i<iStr.size(); i++){
        strEncoded += mCodes[iStr[i]];
    }
    return strEncoded;
}

string HuffmanDecode(Node* root, string iStr){
    string strDecoded = "";
    Node* curr = root;
    for(int i=0; i<iStr.size(); i++){
        if (iStr[i] == '0'){
            curr = curr->left;
        } else {
            curr = curr->right;
        }

        if (curr->left==nullptr and curr->right==nullptr){
            strDecoded += curr->data;
            curr = root;
        }
	}
	return strDecoded;
}

void HuffmanEncodeDecode(string iStr){
    Node* root=buildHuffmanTree(iStr);
    printHuffmanCodesTree(root, "");

    string strEncoded = HuffmanEncode(root, iStr);
    cout << "Encoded Data: ["<<strEncoded<<"]\n";

    string strDecoded = HuffmanDecode(root, strEncoded);
    cout << "Decoded Data: ["<<strDecoded<<"]\n";
}

int main(){
    string str="aabbbaaaabbb";

    HuffmanEncodeDecode(str);

    return 0;
}

