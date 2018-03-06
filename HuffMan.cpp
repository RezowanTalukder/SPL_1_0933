#include<bits/stdc++.h>

using namespace std ;


struct Node
{
    char ch;
    int freq;
    Node *left, *right;
};

struct comp
{
    bool operator()(Node* l  , Node* r)
    {
        return l->freq  >  r->freq ;
    }
};

Node* getNode(char ch, int freq, Node* left, Node* right)
{
    Node* node = new Node();

    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;

    return node;
}

void Encode(Node* root , string str , unordered_map<char ,string>&hCode)
{
    if(root==nullptr)return ;
    if(!root->left && !root->right){
        hCode[root->ch] = str ;
    }
    Encode(root->left,str+"0",hCode) ;
    Encode(root->right,str+"1",hCode) ;
}

void Decode(Node* root, int &index, string str)
{
    if (root == nullptr) return ;

    if (!root->left && !root->right)
    {
        cout << root->ch;
        return;
    }

    index++;

    if (str[index] =='0'){
        Decode(root->left, index, str);
    }

    else{
        Decode(root->right, index, str);
    }
}


void HfManTree(string text)
{
    unordered_map<char , int> freq ;
    for(int i=0 ;i<text.length();i++){
        freq[i]++ ;
    }

    priority_queue<Node* , vector<Node*>,comp>pq ;

    for(auto pa = 0 ; pa<freq.size();++pa){
        pq.push(getNode(pa.first,pa.second,nullptr,nullptr)) ;
    }

    while(pq.size()!=1){
        Node *left = pq.top();
        pq.pop();

        Node *right = pq.top();
        pq.pop();

        int sum = left->freq + right->freq;
        pq.push(getNode('\0', sum, left, right));
    }

    Node* root = pq.top() ;

    unordered_map<char,string>hCode ;
    Encode(root,"" , hCode) ;

    for(auto pa =0 ;pa<hCode.size() ; ++pa ){
        cout<<pa.second<<" " ;
    }


}


int main()
{
    string text = "Huffman coding is a data compression algorithm.";
    buildHuffmanTree(text);
    return 0 ;
}
