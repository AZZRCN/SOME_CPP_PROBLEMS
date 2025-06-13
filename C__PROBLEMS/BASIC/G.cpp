// #include <bits/stdc++.h>
// using namespace std;
// vector<int> us2v(const unordered_set<int>& us){
//     vector<int> r;
//     for(int i : us){r.push_back(i);}
//     sort(r.begin(),r.end());
//     return r;
// }
// void outv(const vector<int>& v){
//     for(int i : v){printf("%d ",i);}
// }
// void space(){putchar(' ');}
// void enter(){putchar('\n');}
// class unsafe_g{
//     public:
//     unordered_set<int>points;
//     unordered_map<int,unordered_set<int>>in;//xxx的入
//     unordered_map<int,unordered_set<int>>out;//xxx的出
//     vector<int> getin(const int& x){
//         // return ((in.find(x)==in.end())?(vector<int>()):(us2v(in.find(x)->second)));
//         return us2v(in.find(x)->second);
//     }
//     vector<int> getout(const int& x){
//         // return ((out.find(x)==out.end())?(vector<int>()):(us2v(out.find(x)->second)));
//         return us2v(out.find(x)->second);
//     }
//     void connect(const int& f,const int& t){
//         out.find(f)->second.insert(t);
//         in.find(t)->second.insert(f);
//     }
//     void insp(const int& x){
//         points.insert(x);
//         // if(out.find(f)==out.end()){out.insert(make_pair(f,unordered_set<int>()));}
//         // if(in.find(t)==in.end()){in.insert(make_pair(t,unordered_set<int>()));}
//         out.insert(make_pair(x,unordered_set<int>()));
//         in.insert(make_pair(x,unordered_set<int>()));
//     }
//     bool hasp(const int& x){
//         return points.find(x)!=points.end();
//     }
//     bool cango(const int& f,const int& t){
//         return out[f].find(t)!=out[f].end();
//     }
//     bool near(const int& f,const int& t){
//         return cango(f,t)||cango(t,f);
//     }
// };
// unsafe_g _g;
// int main(){
//     _g.insp(10);
//     _g.insp(20);
//     _g.insp(30);
//     _g.connect(10,20);
//     _g.connect(20,30);
//     _g.connect(10,30);
//     cout << _g.near(30,10);
// }


// #include <bits/stdc++.h>
// using namespace std;

// vector<int> us2v(const unordered_set<int>& us) {
//     vector<int> r(us.begin(), us.end());
//     sort(r.begin(), r.end());
//     return r;
// }

// void outv(const vector<int>& v) {
//     for (int i : v) printf("%d ", i);
// }

// class unsafe_g {
// public:
//     unordered_set<int> points;
//     unordered_map<int, unordered_set<int>> in;
//     unordered_map<int, unordered_set<int>> out;
//     int edges_num = 0;

//     void connect(int f, int t) {
//         auto& f_out = out[f];
//         auto& t_in = in[t];
//         if (f_out.insert(t).second) {
//             t_in.insert(f);
//             edges_num++;
//         }
//     }

//     void insp(int x) {
//         points.insert(x);
//         out.insert({x, unordered_set<int>()});
//         in.insert({x, unordered_set<int>()});
//     }

//     bool hasp(int x) const {
//         return points.find(x) != points.end();
//     }

//     bool cango(int f, int t) const {
//         auto it = out.find(f);
//         return it != out.end() && it->second.find(t) != it->second.end();
//     }

//     bool near(int f, int t) const {
//         return cango(f, t) || cango(t, f);
//     }

//     vector<int> getin(int x) const {
//         auto it = in.find(x);
//         return it != in.end() ? us2v(it->second) : vector<int>();
//     }

//     vector<int> getout(int x) const {
//         auto it = out.find(x);
//         return it != out.end() ? us2v(it->second) : vector<int>();
//     }

//     void remove_point(int x) {
//         if (!hasp(x)) return;
//         edges_num -= out[x].size() + in[x].size();
//         for (int t : out[x]) in[t].erase(x);
//         for (int f : in[x]) out[f].erase(x);
//         points.erase(x);
//         out.erase(x);
//         in.erase(x);
//     }

//     void disconnect(int f, int t) {
//         auto it = out.find(f);
//         if (it != out.end() && it->second.erase(t)) {
//             in[t].erase(f);
//             edges_num--;
//         }
//     }

//     vector<int> get_all_points() const {
//         return us2v(points);
//     }

//     vector<pair<int, int>> get_all_edges() const {
//         vector<pair<int, int>> edges;
//         for (const auto& p : out) {
//             int f = p.first;
//             for (int t : p.second) edges.emplace_back(f, t);
//         }
//         sort(edges.begin(), edges.end());
//         return edges;
//     }

//     size_t in_degree(int x) const {
//         auto it = in.find(x);
//         return it != in.end() ? it->second.size() : 0;
//     }

//     size_t out_degree(int x) const {
//         auto it = out.find(x);
//         return it != in.end() ? it->second.size() : 0;
//     }

//     void clear() {
//         points.clear();
//         in.clear();
//         out.clear();
//         edges_num = 0;
//     }

//     size_t size_points() const { return points.size(); }
//     int size_edges() const { return edges_num; }
// };

// int main() {
//     unsafe_g _g;
//     _g.insp(10);
//     _g.insp(20);
//     _g.insp(30);
//     _g.connect(10, 20);
//     _g.connect(20, 30);
//     _g.connect(10, 30);
//     cout << _g.near(30, 10) << endl; // 输出0，因为没有边30→10
//     cout << "Edges: " << _g.size_edges() << endl; // 3
//     // _g.remove_point(20);
//     cout << "Edges after remove 20: " << _g.size_edges() << endl; // 1
//     vector<pair<int, int>> edges = _g.get_all_edges();
//     cout << "Remaining edges: ";
//     for (auto& e : edges) cout << "(" << e.first << "," << e.second << ") "; // (10,30)
//     return 0;
// }
// #include <iostream>
// #include <unordered_map>
// #include <unordered_set>
// #include <vector>
// using namespace std;
// class graph_int{
//     using us = unordered_set<int>;
//     template<typename _Ty>using um = unordered_map<int,_Ty>;
//     #define __connect(a,b) a##b
//     #define have(map,x) map.find(x)!=map.end()
//     #define unhave(map,x) map.find(x)==map.end()
//     #define pass ;
//     #define _find(map,x,operator,_do) if(operator(map,x)){\
//             _do;\
//         }\
//         else{
//     #define find_end \
//         }
//     //点,出边,入边

//     us points;um<us> out;um<us> in;
//     void add(int p){_find(points,p,have,return);points.insert(p);find_end;}
//     void remove(int p){_find(points,p,unhave,return);points.erase(p);find_end;}
//     void connect(int f,int t){
//         add(f);
//         add(t);
//         _find(out,f,unhave,);
//         _find(out[f],t,)
//         find_end;
//     }
// };