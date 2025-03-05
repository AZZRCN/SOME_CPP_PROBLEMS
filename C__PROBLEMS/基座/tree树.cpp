#include <iostream>
#include <unordered_map>
#include <vector>
#include <stdexcept>
#include <bits/stdc++.h>
using namespace std;
// 树节点结构
struct Node {
    int _val;         // 节点的值
    Node* father;     // 指向父节点的指针

    Node(int val, Node* father = nullptr) : _val(val), father(father) {}
};

// 树结构
class Tree {
private:
    std::unordered_map<int, Node*> valToNodeMap;               // _val 到 Node* 的映射
    std::unordered_map<int, std::vector<Node*>> valToChildrenMap; // _val 到子节点列表的映射

    // 递归删除节点及其子节点
    void removeRecursive(Node* node) {
        if (!node) return;

        // 递归删除所有子节点
        for (Node* child : valToChildrenMap[node->_val]) {
            removeRecursive(child);
        }

        // 从父节点的子节点列表中移除当前节点
        if (node->father) {
            auto& siblings = valToChildrenMap[node->father->_val];
            siblings.erase(std::remove(siblings.begin(), siblings.end(), node), siblings.end());
        }

        // 从映射中删除当前节点
        valToNodeMap.erase(node->_val);
        valToChildrenMap.erase(node->_val);

        // 释放内存
        delete node;
    }

public:
    // 插入一个节点
    void insert(int val, int fatherVal = -1) {
        if (valToNodeMap.find(val) != valToNodeMap.end()) {
            throw std::invalid_argument("Node with this value already exists");
        }

        Node* fatherNode = nullptr;
        if (fatherVal != -1) {
            if (valToNodeMap.find(fatherVal) == valToNodeMap.end()) {
                throw std::invalid_argument("Father node does not exist");
            }
            fatherNode = valToNodeMap[fatherVal];
        }

        Node* newNode = new Node(val, fatherNode);
        valToNodeMap[val] = newNode;

        // 更新父节点的子节点列表
        if (fatherNode) {
            valToChildrenMap[fatherNode->_val].push_back(newNode);
        }
    }

    // 查找一个节点
    Node* find(int val) {
        if (valToNodeMap.find(val) == valToNodeMap.end()) {
            return nullptr;
        }
        return valToNodeMap[val];
    }

    // 查找某个节点的子节点
    std::vector<Node*> findChildren(int val) {
        if (valToChildrenMap.find(val) == valToChildrenMap.end()) {
            return {};
        }
        return valToChildrenMap[val];
    }

    // 删除一个节点及其所有子节点
    void remove(int val) {
        if (valToNodeMap.find(val) == valToNodeMap.end()) {
            throw std::invalid_argument("Node does not exist");
        }

        Node* nodeToRemove = valToNodeMap[val];
        removeRecursive(nodeToRemove);
    }

    // 打印树结构（从某个节点开始）
    void printFromNode(int val) {
        if (valToNodeMap.find(val) == valToNodeMap.end()) {
            throw std::invalid_argument("Node does not exist");
        }
        Node* current = valToNodeMap[val];
        while (current != nullptr) {
            std::cout << current->_val;
            if (current->father != nullptr) {
                std::cout << " -> ";
            }
            current = current->father;
        }
        std::cout << std::endl;
    }

    // 打印整个树结构
    void printTree() {
        for (const auto& pair : valToNodeMap) {
            std::cout << "Node " << pair.first << " -> Father: ";
            if (pair.second->father != nullptr) {
                std::cout << pair.second->father->_val;
            } else {
                std::cout << "nullptr";
            }
            std::cout << ", Children: ";
            for (Node* child : valToChildrenMap[pair.first]) {
                std::cout << child->_val << " ";
            }
            std::cout << std::endl;
        }
    }

    // 析构函数，释放所有节点
    ~Tree() {
        for (const auto& pair : valToNodeMap) {
            delete pair.second;
        }
    }
};

int main() {
    Tree tree;

    // 插入节点
    tree.insert(1);        // 根节点
    tree.insert(2, 1);     // 2 的父节点是 1
    tree.insert(3, 1);     // 3 的父节点是 1
    tree.insert(4, 2);     // 4 的父节点是 2
    tree.insert(5, 2);     // 5 的父节点是 2
    tree.insert(6, 3);     // 6 的父节点是 3

    // 打印树结构
    std::cout << "Tree structure:" << std::endl;
    tree.printTree();

    // 查找节点
    Node* node = tree.find(4);
    if (node != nullptr) {
        std::cout << "Found node with value 4, father is " << (node->father ? node->father->_val : -1) << std::endl;
    }

    // 查找子节点
    std::vector<Node*> children = tree.findChildren(2);
    std::cout << "Children of node 2: ";
    for (Node* child : children) {
        std::cout << child->_val << " ";
    }
    std::cout << std::endl;

    // 打印从某个节点开始的路径
    std::cout << "Path from node 4 to root:" << std::endl;
    tree.printFromNode(4);

    // 删除节点
    tree.remove(2);
    std::cout << "After removing node 2:" << std::endl;
    tree.printTree();

    return 0;
}