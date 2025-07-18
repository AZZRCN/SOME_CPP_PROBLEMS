#include <bits/stdc++.h>
using namespace std;

namespace TV {
    // 增强的排序规则枚举
    enum class SortRule {
        BIG,     // 降序
        SMALL,   // 升序
        ANY_KEEP_ORDER,  // 不比较但保持原始顺序
        ANY_REVERSE_ORDER // 不比较但反转原始顺序
    };

    template <typename... Types>
    class types_vector {
    private:
        std::tuple<Types...> data;
        size_t original_order; // 用于记录原始顺序
    public:
        types_vector() : original_order(0) {}
        
        template <size_t Index>
        auto& g() { return std::get<Index>(data); }
        
        template <size_t Index>
        const auto& g() const { return std::get<Index>(data); }

        void set_order(size_t order) { original_order = order; }
        size_t get_order() const { return original_order; }

    public:
        template<SortRule... Rules>
        class simple_sort {
        public:
            bool operator()(const types_vector& a, const types_vector& b) const {
                return compare<0, Rules...>(a, b);
            }
            
        private:
            template<size_t Index, SortRule Rule, SortRule... Rest>
            bool compare(const types_vector& a, const types_vector& b) const {
                const auto& aVal = a.g<Index>();
                const auto& bVal = b.g<Index>();
                
                if constexpr (Rule == SortRule::BIG) {
                    if (aVal != bVal) return aVal > bVal;
                } 
                else if constexpr (Rule == SortRule::SMALL) {
                    if (aVal != bVal) return aVal < bVal;
                }
                else if constexpr (Rule == SortRule::ANY_REVERSE_ORDER) {
                    return a.get_order() > b.get_order();
                }
                return compare<Index + 1, Rest...>(a, b);
            }
            
            // 终止条件
            template<size_t Index>
            bool compare(const types_vector& a, const types_vector& b) const {
                // 所有字段都相等时，保持原始顺序
                return a.get_order() > b.get_order();
            }
        };
    };
}

int main() {
    using namespace TV;
    int n;
    cin >> n;
    vector<types_vector<int, int, int, string>> students(n);
    for (int i = 0; i < n; i++) {
        auto& s = students[i];
        cin >> s.g<3>() >> s.g<0>() >> s.g<1>() >> s.g<2>();
        s.set_order(i);
    }
    sort(students.begin(), students.end(), 
        types_vector<int, int, int, string>::simple_sort<
            SortRule::SMALL,
            SortRule::SMALL,
            SortRule::SMALL,
            SortRule::ANY_KEEP_ORDER>());
    
    for (const auto& s : students) {
        cout << s.g<3>() << '\n';
    }
    
    return 0;
}