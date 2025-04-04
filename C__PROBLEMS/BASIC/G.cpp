#include <bits/stdc++.h>
using namespace std;
vector<int> us2v(const unordered_set<int>& us){
    vector<int> r;
    for(int i : us){r.push_back(i);}
    sort(r.begin(),r.end());
    return r;
}
void outv(const vector<int>& v){
    for(int i : v){printf("%d ",i);}
}
void space(){putchar(' ');}
void enter(){putchar('\n');}
class unsafe_g{
    public:
    unordered_set<int>points;
    unordered_map<int,unordered_set<int>>in;//xxx的入
    unordered_map<int,unordered_set<int>>out;//xxx的出
    vector<int> getin(const int& x){
        // return ((in.find(x)==in.end())?(vector<int>()):(us2v(in.find(x)->second)));
        return us2v(in.find(x)->second);
    }
    vector<int> getout(const int& x){
        // return ((out.find(x)==out.end())?(vector<int>()):(us2v(out.find(x)->second)));
        return us2v(out.find(x)->second);
    }
    void connect(const int& f,const int& t){
        out.find(f)->second.insert(t);
        in.find(t)->second.insert(f);
    }
    void insp(const int& x){
        points.insert(x);
        // if(out.find(f)==out.end()){out.insert(make_pair(f,unordered_set<int>()));}
        // if(in.find(t)==in.end()){in.insert(make_pair(t,unordered_set<int>()));}
        out.insert(make_pair(x,unordered_set<int>()));
        in.insert(make_pair(x,unordered_set<int>()));
    }
    bool hasp(const int& x){
        return points.find(x)!=points.end();
    }
    bool cango(const int& f,const int& t){
        return out[f].find(t)!=out[f].end();
    }
    bool near(const int& f,const int& t){
        return cango(f,t)||cango(t,f);
    }
};
unsafe_g _g;
int main(){
    _g.insp(10);
    _g.insp(20);
    _g.insp(30);
    _g.connect(10,20);
    _g.connect(20,30);
    _g.connect(10,30);
    cout << _g.near(30,10);
}