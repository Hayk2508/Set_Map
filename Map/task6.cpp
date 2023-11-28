#include <iostream>
#include <map>

class Trie {
    class TrieNode {
    public:
        std::map<char, TrieNode *> children;
        bool isEndOfWord;

        TrieNode() {
            isEndOfWord = false;
        }
    };

    TrieNode *root;

public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {


    }

    void insert(const std::string &word) {
        TrieNode *current = root;
        for (char ch: word) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }

    bool startsWith(const std::string &prefix) {
        TrieNode *tmp = root;
        for (char x : prefix) {
            if (tmp->children.find(x) == tmp->children.end()) {
                return false;
            }
            tmp = tmp->children[x];
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("Hello");
    trie.insert("Hey");
    trie.insert("World");

    std::cout << trie.startsWith("Hell") << std::endl; // Output: true
    std::cout << trie.startsWith("abc") << std::endl;  // Output: false
    std::cout << trie.startsWith("Wo") << std::endl;  // Output: true
}