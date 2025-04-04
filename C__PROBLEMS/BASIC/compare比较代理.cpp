// 定义一个枚举类型，表示比较结果
enum class CompareResult {
    Greater,  // _Tp1 > _Tp2
    Equal,    // _Tp1 == _Tp2
    Less      // _Tp1 < _Tp2
};

// 比较函数，传入两个参数 _Tp1 和 _Tp2
template <typename _Tp1, typename _Tp2>
CompareResult proxy(const _Tp1& a, const _Tp2& b) {
    if (a > b) {
        return CompareResult::Greater;  // _Tp1 > _Tp2
    } else if (b > a) {
        return CompareResult::Less;     // _Tp2 > _Tp1
    } else {
        return CompareResult::Equal;   // _Tp1 == _Tp2
    }
}