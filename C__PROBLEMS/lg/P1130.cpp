#include <bits/stdc++.h>
using namespace std;
template<size_t degs>
class auto_vector {
private:std::vector<auto_vector<degs-1>> data;
public:auto_vector() = default;
    void __malloc(const std::vector<int>& dims) {
        if (dims.size() != degs) {throw std::runtime_error("Dimension mismatch");}
        data.resize(dims[0]);
        std::vector<int> next_dims(dims.begin() + 1, dims.end());
        for (auto& v : data) {v.__malloc(next_dims);}
    }
    auto_vector<degs-1>& operator[](size_t idx) {
        if (idx >= data.size()) {throw std::out_of_range("Index out of range");}
        return data[idx];
    }
    const auto_vector<degs-1>& operator[](size_t idx) const {
        if (idx >= data.size()) {throw std::out_of_range("Index out of range");}
        return data[idx];
    }
};
template<>
class auto_vector<1> {
private:std::vector<int> data;
public:auto_vector() = default;
    void __malloc(const std::vector<int>& dims) {
        if (dims.size() != 1) {throw std::runtime_error("Dimension mismatch");}
        data.resize(dims[0]);
    }
    int& operator[](size_t idx) {
        if (idx >= data.size()) {throw std::out_of_range("Index out of range");}
        return data[idx];
    }
    const int& operator[](size_t idx) const {
        if (idx >= data.size()) {throw std::out_of_range("Index out of range");}
        return data[idx];
    }
};
int main(){
	int n,m,t;
	cin >> n >> m;
	auto_vector<2> v;
	v.__malloc({m,n});
	auto_vector<2> a;
	a.__malloc({m,n});
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			// cin >> v[i][j];
			scanf("%d",&v[i][j]);
		}
	}
	for(int i = 0; i < m; i++){
		a[i][0] = v[i][0];
	}
	for(int j = 1; j < n; j++){
		a[0][j]=v[0][j]+min(a[0][j-1],a[m-1][j-1]);
		for(int i = 1; i < m; i++){
			a[i][j] = v[i][j]+min(a[i][j-1],a[i-1][j-1]);
		}
	}
	int maxn = 0x7fffffff;
	for(int i = 0; i < m; i++){
		maxn = min(maxn,a[i][n-1]);
	}
	cout << maxn;
}