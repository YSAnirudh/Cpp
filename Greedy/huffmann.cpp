#include <iostream>
#include <map>
#include <set>
using namespace std;

struct Node {
    int freq;
    char c;
    Node* left;
    Node* right;
    Node() {}
    Node(int freq, char a):freq(freq), c(a), left(NULL), right(NULL) {}
    Node(int freq, char a, Node* left, Node* right) :freq(freq), c(a), left(left), right(right) {}
};

ostream& operator<<(ostream &out, const Node& a) {
    out << a.freq << a.c << flush;
    return out;
}

ostream& operator<<(ostream &out, Node& a) {
    out << a.freq << a.c << flush;
    return out;
}

class Huffmann {
private:
    struct cmp {
        bool operator()(const Node& a, const Node& b) {
            return a.freq <= b.freq;
        }
    };
    set<Node, cmp> a;
    void dfs(Node* head, string bitRep) {
        if (head == NULL) return;
        if (!head->left && !head->right) {
            cout << head->c << " = " << bitRep << endl;
        }
        if (head->left) {
            dfs(head->left, bitRep + "1");
        }
        if (head->right) {
            dfs(head->right, bitRep + "0");
        }
    }

    void printTree(Node* head) {
        if (head == NULL) {
            return;
        } else {
            cout << *head << endl;
            printTree(head->left);
            printTree(head->right);
        }
    }

    Node* makeTree() {
        if (a.size() == 0) return NULL;
        Node* head = NULL;
        while (this->a.size() != 1) {
            Node* root;
            root = new Node(-1, '$');
            root->left = new Node(a.begin()->freq, a.begin()->c, a.begin()->left, a.begin()->right);
            root->right = new Node((++a.begin())->freq, (++a.begin())->c, (++a.begin())->left, (++a.begin())->right);
            root->c = '$';
            root->freq = -1;

            a.erase(a.begin());
            a.erase(a.begin());
            a.insert(a.begin(), *root);

            if (a.size() == 1) {
                head = root;
            }
        }
        // for (auto i = a.begin(); i != a.end(); i++) {
        //     cout << i->c << i->freq << endl;
        // }
        return head;
    }

    void insert(int freq, char c) {
        a.insert(Node(freq, c));
    }
public:
    void encode() {
        int size, freq;
        char c;
        cout << "No of Nodes: ";
        cin >> size;
        for (int i = 0; i < size; i++) {
            cout << "Node " << i + 1 << endl;
            cout << "Char: ";
            cin >> c;
            cout << "Frequency: ";
            cin >> freq;
            while (freq < 1) {
                cout << "Freq shld be greater than 0." << endl;
                cin >> freq;
            }
            insert(freq, c);
        }
        cout << endl;
        cout << "Huffmann Codes: " << endl;
        dfs(makeTree(), "");
        return;
    }
};

int main() {
    Huffmann huff;
    huff.encode();
    // for (auto i = a.begin(); i != a.end(); i++) {
    //     cout << i->c << i->freq << endl;
    // }
}