#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include <unordered_map>
using namespace std;

#define EMPTY_STRING ""

// tree node
struct Node
{
    char ch;
    int freq;
    Node *left, *right;
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

// Comparison object to be used to order the heap
struct comp
{
    bool operator()(Node* l, Node* r)
    {
        // the highest priority item has the lowest frequency
        return l->freq > r->freq;
    }
};

// Utility function to check if Huffman Tree contains only a single node
bool isLeaf(Node* root) {
    return root->left == nullptr && root->right == nullptr;
}

// Traverse the Huffman Tree and store Huffman Codes in a map.
void encode(Node* root, string str, unordered_map<char, string> &huffmanCode)
{
    if (root == nullptr) {
        return;
    }

    // found a leaf node
    if (isLeaf(root)) {
        huffmanCode[root->ch] = (str != EMPTY_STRING) ? str : "1";
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

// Traverse the Huffman Tree and decode the encoded string
void decode(Node* root, int &index, string str)
{
    if (root == nullptr) {
        return;
    }

    // found a leaf node
    if (isLeaf(root)) {
        cout << root->ch;
        return;
    }

    index++;

    if (str[index] == '0') {
        decode(root->left, index, str);
    } else {
        decode(root->right, index, str);
    }
}

ofstream file1("tree.txt");
void printBT(const std::string& prefix, const Node* node, bool isLeft)
{

    if( node != nullptr )
    {
        file1 << prefix;

        file1 << (isLeft ? "---" : "---" );

        // print the value of the node
        file1 << node->freq << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "|   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "|   " : "    "), node->right, false);
    }
}

void printBT(const Node* node)
{
    printBT("", node, false);
}

void buildHuffmanTree(string text)
{
    ifstream f(text);
    string line;
    if(getline(f, line)){

    }

    // base case: empty string
    if (line == EMPTY_STRING) {
        return;
    }

    // count frequency of appearance of each character
    // and store it in a map
    unordered_map<char, int> freq;
    for (char ch: line) {
        freq[ch]++;
    }

    // Create a priority queue to store live nodes of Huffman tree
    priority_queue<Node*, vector<Node*>, comp> pq;

    // Create a leaf node for each character and add it to pq

    for (auto pair: freq) {
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }


    while (pq.size() != 1)
    {
        // Remove the two nodes of the highest priority


        Node *left = pq.top(); pq.pop();
        Node *right = pq.top();    pq.pop();

        // Create a new internal node with two nodes


        int sum = left->freq + right->freq;
        pq.push(getNode('\0', sum, left, right));
    }

    // root stores pointer to the root of Huffman Tree
    Node* root = pq.top();
    printBT(root);
    // Traverse the Huffman Tree and store Huffman Codes

    unordered_map<char, string> huffmanCode;
    encode(root, EMPTY_STRING, huffmanCode);


    ofstream file("charcode.txt");
    for (auto pair: huffmanCode) {
        file << pair.first << "\t" << pair.second << '\n';
    }
    file.close();

    // Print encoded string
    string str;
    for (char ch: line) {
        str += huffmanCode[ch];
    }

    cout << str << endl;


}
void getCharCode(string a){
    ifstream charcode("charcode.txt");
    string line;
    while (getline(charcode, line)){
        string delimiter = "\t";
        string split[2];
        size_t pos = 0;
        string token;
        int x = 0;
        while ((pos = line.find(delimiter)) != string::npos) {
            token = line.substr(0, pos);
            split[x] = token;
            line.erase(0, pos + delimiter.length());
            x++;
        }
        split[x] = line;
        if (split[0] == a){
            cout << split[0] +" "+ split[1] <<endl;

        }
    }
}
void copyTree() {
    ifstream t("tree.txt");
    ofstream t1("tree1.txt");
    string line;
    while (getline(t, line)) {
        t1 << line << endl;
    }
}
void printTree(){
    ifstream t("tree1.txt");
    string line;
    while (getline(t, line)){
        cout << line << endl;
    }
}

// Huffman coding algorithm
int main(int argc, char *argv[])
{
    std::string argv1(argv[1]);

    if (argv1 =="-i") {
        std::string argv3(argv[3]);
        if (argv3 =="-encode"){
            std::string argv2(argv[2]);
            string text = argv2;
            buildHuffmanTree(text);
            copyTree();
        }
    }
    if (argv1 =="-s") {
        std::string argv2(argv[2]);
        getCharCode(argv2);
    }
    if (argv1 =="-l") {
        printTree();
    }

    return 0;
}