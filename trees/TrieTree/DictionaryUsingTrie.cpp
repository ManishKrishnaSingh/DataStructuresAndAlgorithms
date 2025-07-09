#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    bool EndOfWord;
    string meaning;
    unordered_map<char,node*> children;

    node() {
        this->meaning = "";
        this->EndOfWord = false;
    }
} Node;

Node* insert(Node* root, string word, string meaning)
{
    if(root == nullptr)
    {
        root = new Node();
    }

    Node* curr = root;
    for (char& ch : word)
    {
        if (curr->children.find(ch) == curr->children.end())
        {
            curr->children[ch] = new Node();
        }
        curr = curr->children[ch]; 
    }

    curr->EndOfWord = true;
    curr->meaning = meaning;

    return root;
}

string FindMeaning(Node* root, string word)
{
    if(root != nullptr)
    {
        Node* curr = root;
        for (char& ch : word)
        {
            curr = curr->children[ch];
            if (curr == nullptr)
            {
                return "";
            }
        }

        if (curr->EndOfWord)
        {
            return curr->meaning;
        }
    }

    return "";
}

int main()
{
    Node* dictionary = nullptr;
    dictionary = insert(dictionary, "Bee",  "Buzz");
    dictionary = insert(dictionary, "Cat",  "Meow");
    dictionary = insert(dictionary, "Dog",  "Bark");
    dictionary = insert(dictionary, "Lion", "Roar");
    dictionary = insert(dictionary, "Bird", "Chirp");

    cout<<"Meaning Of 'Lion' = "<<FindMeaning(dictionary,"Lion");

    return 0;
}
