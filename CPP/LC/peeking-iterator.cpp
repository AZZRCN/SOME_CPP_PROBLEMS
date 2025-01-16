
#include <bits/stdc++.h>
using namespace std;
// 下面是 Iterator 接口的定义，已经为你定义好了。
// **不要** 修改 Iterator 接口的定义。
class Iterator {
	struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	// 返回迭代中的下一个元素。
	int next();
	// 如果迭代还有更多元素，则返回 true。
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    Iterator*i;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // 在这里初始化任何成员。
	    // **不要** 保存 nums 的副本并直接操作它。
	    // 你应该只使用 Iterator 接口的方法。
	    i = new Iterator(nums);
	}
    // 返回迭代中的下一个元素，但不推进迭代器。
	int peek() {
        return Iterator(*i).next();
    }
	// hasNext() 和 next() 应该与 Iterator 接口的行为相同。
	// 如果需要，可以重写它们。
	int next() {
	    return i->next();
	}
	bool hasNext() const {
        return i->hasNext();
	}
};