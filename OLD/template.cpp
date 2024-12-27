#include <vector>
template<typename T>
bool AinB(const T& L, const std::vector<T>& R) {
	for (T k : R) {
		if (k == L) { return true; }
	}
	return false;
}
template<typename T>
void is(T L, T& R) {
	R = L;
}
template<typename PT,typename T>
void DP(PT project, int n, T& out) {
	if (n != 0) {
		DP(&project, n - 1, out);
	}
	else {
		is(project, out);
	}
}