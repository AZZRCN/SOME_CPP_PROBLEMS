/**
 * @brief 对指定范围内的元素进行累加操作。
 *
 * @tparam InputIt 输入迭代器类型
 * @tparam T 初始值和结果类型
 * @tparam BinaryOperation 二元操作符，默认为 std::plus<>
 *
 * @param first 开始迭代器
 * @param last 结束迭代器
 * @param init 初始值
 * @param op 可选操作符，默认是加法
 *
 * @return 累加后的结果
 */
template<class InputIt, class T, class BinaryOperation>
T accumulate(InputIt first, InputIt last, T init, BinaryOperation op);