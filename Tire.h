#ifndef TIRE_H
#define TIRE_H

#include <string>
#include <vector>
using namespace std;

//  1 2 3 4 5 ... 26
//27 .. 

//  1     i
// 2 3  2i 2i+1

//  默认的树形节点定义如下所示
template<typename ValueType, int NUM = 2>
struct TreeNode {
    ValueType value_;
    TreeNode<ValueType, NUM>* chirldren[NUM];
};

//  前缀树节点有is_end_的标志
class Trie {
public:
    Trie() {
        is_end_ = false;
        memset(child_, 0, sizeof(child_));
    }
    
    void insert(string word) {
        Trie* node = this;
        for(int i=0; i<word.size(); i++) {
            if(node->child_[word[i]-'a'] == nullptr) {
                node->child_[word[i]-'a'] = new Trie();
            }
            node = node->child_[word[i]-'a'];
        }
        node->is_end_ = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(int i=0; i<word.size(); i++) {
            if(node->child_[word[i]-'a'] == nullptr) {
                return false;
            }
            node = node->child_[word[i]-'a'];
        }
        return node->is_end_;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(int i=0; i<prefix.size(); i++) {
            if(node->child_[prefix[i]-'a'] == nullptr) {
                // cout << "i:" << i << endl;
                return false;
            }
            node = node->child_[prefix[i]-'a'];
        }
        return true;
    }
private:
    bool is_end_;
    Trie* child_[26]; // 每个位置依次对应'a', 'b', ..., 'z'
};

#endif