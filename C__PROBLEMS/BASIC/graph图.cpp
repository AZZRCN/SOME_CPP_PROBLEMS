#include <unordered_map>
#include <unordered_set>
#include <memory>

template <typename ValType>
class Graph {
private:
    struct Node {
        ValType val;
        explicit Node(const ValType& v) : val(v) {}
    };

    // 核心数据结构
    std::unordered_map<ValType, std::unique_ptr<Node>> nodes_;
    std::unordered_map<Node*, std::unordered_set<Node*>> out_edges_;  // 出边表
    std::unordered_map<Node*, std::unordered_set<Node*>> in_edges_;   // 入边表

    Node* _get_node(const ValType& val) const {
        auto it = nodes_.find(val);
        return it != nodes_.end() ? it->second.get() : nullptr;
    }

public:
    // 节点操作
    bool add_node(const ValType& val) {
        if (nodes_.count(val)) return false;
        nodes_.emplace(val, std::make_unique<Node>(val));
        return true;
    }

    bool remove_node(const ValType& val) {
        auto it = nodes_.find(val);
        if (it == nodes_.end()) return false;

        Node* target = it->second.get();

        // 处理出边
        if (out_edges_.count(target)) {
            for (auto& neighbor : out_edges_[target]) {
                in_edges_[neighbor].erase(target);
            }
            out_edges_.erase(target);
        }

        // 处理入边
        if (in_edges_.count(target)) {
            for (auto& neighbor : in_edges_[target]) {
                out_edges_[neighbor].erase(target);
            }
            in_edges_.erase(target);
        }

        nodes_.erase(it);
        return true;
    }

    // 边操作
    bool add_edge(const ValType& from, const ValType& to) {
        Node* src = _get_node(from);
        Node* dst = _get_node(to);
        if (!src || !dst) return false;

        out_edges_[src].insert(dst);
        in_edges_[dst].insert(src);
        return true;
    }

    bool remove_edge(const ValType& from, const ValType& to) {
        Node* src = _get_node(from);
        Node* dst = _get_node(to);
        if (!src || !dst) return false;

        bool removed = out_edges_[src].erase(dst);
        if (removed) {
            in_edges_[dst].erase(src);
            if (out_edges_[src].empty()) out_edges_.erase(src);
            if (in_edges_[dst].empty()) in_edges_.erase(dst);
        }
        return removed;
    }

    // 查询操作
    bool contains_node(const ValType& val) const {
        return nodes_.count(val);
    }

    bool contains_edge(const ValType& from, const ValType& to) const {
        Node* src = _get_node(from);
        Node* dst = _get_node(to);
        return src && dst && out_edges_.count(src) && out_edges_.at(src).count(dst);
    }
};
Graph<int>g;
int main(){
    g.add_node(1);
    g.add_node(2);
    g.add_edge(1,2);
}