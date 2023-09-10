#include <iostream>
#include "Tire.h"

int main() {

    // TreeNode<int> a;
    Trie* trie = new Trie();
    trie->insert("apple");
    cout << trie->startsWith("app") << endl;
    // cout << sizeof(a.chirldren) / sizeof(a.chirldren[0]) << endl;

    return 0;
}