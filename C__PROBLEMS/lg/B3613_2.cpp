#include <bits/stdc++.h>
using namespace std;

// 首先定义pair的哈希函数
namespace std {
    template <>
    struct hash<pair<int, int>> {
        size_t operator()(const pair<int, int> &p) const {
            return hash<int>()(p.first) ^ hash<int>()(p.second);
        }
    };
}

enum {
    BOTH = 3,    // 双向边
    FORWARD = 1, // 单向边：from -> to
    BACK = 2     // 单向边：to -> from
};

class un_g {
private:
    // 点所连接的边
    unordered_map<int, unordered_set<int>> datas; // 每个点的邻接表（存储出边）
    // 边的状态（使用 unordered_set 存储边的存在性）
    unordered_set<pair<int, int>> edges; // 存储边的存在性

public:
    // 插入点
    inline void insert_point(const int &x) {
        if (datas.find(x) == datas.end()) {
            datas.insert(make_pair(x, unordered_set<int>()));
        }
    }

    // 插入边
    void connect(const int &from, const int &to, const int &mode) {
        insert_point(from);
        insert_point(to);
        if (mode & FORWARD) {
            datas[from].insert(to);
        }
        if (mode & BACK) {
            datas[to].insert(from);
        }
        edges.insert(make_pair(from, to)); // 记录边的存在
    }

    // 删除边
    void delete_edge(const int &from, const int &to) {
        edges.erase(make_pair(from, to)); // 删除边的记录
        datas[from].erase(to); // 从出边中删除
        datas[to].erase(from); // 从入边中删除
    }

    // 删除点及其相关的边
    void delete_point(const int &x) {
        if (datas.find(x) != datas.end()) {
            // 删除与该点相关的边
            for (int neighbor : datas[x]) {
                delete_edge(x, neighbor);
            }
            // 删除该点的所有出边
            datas.erase(x);
        }
    }

    // 获取某点的出边
    const unordered_set<int> get_out_edges(const int &from) {
        return datas[from];
    }

    // 获取某点的入边
    unordered_set<int> get_in_edges(const int &to) {
        unordered_set<int> in_edges;
        for (const auto &edge : edges) {
            if (edge.second == to) {
                in_edges.insert(edge.first); // edge.first 是指向入边的起点
            }
        }
        return in_edges;
    }

    // 获取某点的所有相关边（入边 + 出边）
    unordered_set<int> get_all_edges(const int &point) {
        unordered_set<int> all_edges = get_out_edges(point);
        unordered_set<int> in_edges = get_in_edges(point);
        all_edges.insert(in_edges.begin(), in_edges.end());
        return all_edges;
    }
};

// 将 unordered_set 转为 vector 并排序
vector<int> us2v(const unordered_set<int> &x) {
    vector<int> r;
    for (int i : x) {
        r.push_back(i);
    }
    sort(r.begin(), r.end());
    return r;
}

// 测试代码
int main() {
    un_g graph;

    // 插入点
    graph.insert_point(1);
    graph.insert_point(2);
    graph.insert_point(3);

    // 插入边
    graph.connect(1, 2, BOTH);  // 双向边
    graph.connect(2, 3, FORWARD); // 单向边：2 -> 3

    // 获取出边
    unordered_set<int> out_edges = graph.get_out_edges(2);
    vector<int> sorted_out_edges = us2v(out_edges);
    cout << "Out edges from 2: ";
    for (int i : sorted_out_edges) {
        cout << i << " ";
    }
    cout << endl;

    // 获取入边
    unordered_set<int> in_edges = graph.get_in_edges(3);
    vector<int> sorted_in_edges = us2v(in_edges);
    cout << "In edges to 3: ";
    for (int i : sorted_in_edges) {
        cout << i << " ";
    }
    cout << endl;

    // 获取所有相关边
    unordered_set<int> all_edges = graph.get_all_edges(2);
    vector<int> sorted_all_edges = us2v(all_edges);
    cout << "All edges of 2: ";
    for (int i : sorted_all_edges) {
        cout << i << " ";
    }
    cout << endl;

    // 删除边
    graph.delete_edge(1, 2);

    // 删除点
    graph.delete_point(3);

    return 0;
}