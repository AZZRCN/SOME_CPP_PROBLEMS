#include <bits/stdc++.h>
using namespace std;
class KthLargest {
private:
    std::multiset<int, std::greater<int>> elementSet; // 降序排列的 multiset

public:
    KthLargest(const std::vector<int>& elements) {
        for (int elem : elements) {
            elementSet.insert(elem); // 插入元素，O(log n)
        }
    }

    // 查询第k大的元素
    int query(int k) {
        if (k < 0 || k >= elementSet.size()) {
            throw std::out_of_range("k is out of range");
        }
        auto it = elementSet.begin();
        std::advance(it, k); // 移动迭代器到第k大的元素，O(k)
        return *it;
    }

    // 删除第k大的元素
    void remove(int k) {
        if (k < 0 || k >= elementSet.size()) {
            throw std::out_of_range("k is out of range");
        }
        auto it = elementSet.begin();
        std::advance(it, k); // 移动迭代器到第k大的元素，O(k)
        elementSet.erase(it); // 删除元素，O(log n)
    }

    // 打印当前元素（用于调试）
    void print() {
        for (int elem : elementSet) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    std::vector<int> elements = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    KthLargest kthLargest(elements);

    std::cout << "Initial elements: ";
    kthLargest.print();

    std::cout << "2nd largest element: " << kthLargest.query(1) << std::endl;

    kthLargest.remove(1);
    std::cout << "After removing 2nd largest element: ";
    kthLargest.print();


    std::cout << "2nd largest element: " << kthLargest.query(1) << std::endl;

    kthLargest.remove(1);
    std::cout << "After removing 2nd largest element: ";
    kthLargest.print();

    std::cout << "New 2nd largest element: " << kthLargest.query(1) << std::endl;

    return 0;
}