#include <bits/stdc++.h>
using namespace std;

class node {
public:
    node* father;
    int depth;
    int data;
    bitset<32> flag;
    node() {}
};

vector<node> build(vector<int>& v) {
    vector<node> dat;
    dat.resize(v.size() + 1);
    for (int i = 1; i < v.size(); i++) {
        dat[i].data = v[i];
        dat[i].father = &dat[i / 2];
    }
    dat[0].father = nullptr;
    return dat;
}
void init_bitset(vector<node>& v) {
    for (int i = 1; i < v.size(); i++) {
        v[i].flag = i;
    }
}
size_t rcount0(size_t l,size_t r){
    size_t ans = 0;
    l|=r;
    if(!(l&0xffffffff)){ans+=32;l>>=32;}
    if(!(l&0xffff)){ans+=16;l>>=16;}
    if(!(l&0xff)){ans+=8;l>>=8;}
    if(!(l&0xf)){ans+=4;l>>=4;}
    if(!(l&0x3)){ans+=2;l>>=2;}
    if(!(l&0x1)){ans+=1;l>>=1;}
    return ans;
}
node* locate(node* p1,node* p2,vector<node>& v){
    if(p1==p2){
        return p1;
    }
    return &v[(p1->data&p2->data)&(0xffffffff<<(rcount0(p1->data,p2->data)))];
}

void init_lca(vector<node>& v) {
    for (int i = 1; i < v.size(); i++) {
        node* current = &v[i];
        int depth = 0;
        while (current->father!=nullptr) {
            current = current-> father;
            depth++;
        }
        v[i].depth = depth;
    }
}

node* lca(node* p1, node* p2) {
    if (p1->depth < p2->depth) {
        swap(p1, p2);
    }

    int diff = p1->depth - p2->depth;
    for (int i = 0; i < 32; i++) {
        if (diff & (1 << i)) {
            p1 = p1->father;
        }
    }

    if (p1 == p2) {
        return p1;
    }

    for (int i = 31; i >= 0; i--) {
        if (p1->father && p2->father && p1->father->flag[i] != p2->father->flag[i]) {
            p1 = p1->father;
            p2 = p2->father;
        }
    }

    return p1->father;
}