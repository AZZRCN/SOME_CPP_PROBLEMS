#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
class RWNode
{
public:
    unordered_set<RWNode*> outs;
    unordered_set<RWNode*> ins;
    int key;
    bool depend()
    {
        return ins.size() != 0;
    }
    void connet_out(RWNode* O)
    {
        O->ins.insert(this);
        this->outs.insert(O);
    }
    void connet_in(RWNode* O)
    {
        O->outs.insert(this);
        this->ins.insert(O);
    }
    RWNode() {};
    RWNode(int key) { this->key = key; };
    bool operator==(const RWNode& O) const
    {
        return key == O.key;
    }
};
class RWEdge
{
public:
    RWNode* from;
    RWNode* to;
    int w;
    void conect(RWNode* from, RWNode* to, int w = 0)
    {
        this->from = from;
        this->to = to;
        this->w = w;
    }
    RWEdge(RWNode* from, RWNode* to, int w = 0)
    {
        this->from = from;
        this->to = to;
        this->w = w;
    }
};

class Equal
{
public:
    bool operator()(const RWEdge& L, const RWEdge& R) const { return L.from == R.from && L.to == R.to && L.w == R.w; }
};

class Hash
{
public:
    int operator()(const RWEdge& O) const { return hash<RWNode*>()(O.from) ^ hash<RWNode*>()(O.to) ^ hash<int>()(O.w); }
};

class Rgraph
{
public:
    int blocks = 0;
    unordered_map<int, RWNode> nodes;
    unordered_set<RWEdge, Hash, Equal> edges;
    RWNode* insert_node(int name)
    {
        unordered_map<int, RWNode>::iterator p = nodes.find(name);
        if (p != nodes.end())
        {
            return &p->second;
        }
        RWNode p2(name);
        nodes.insert(make_pair(name, p2));

        blocks++;

        return &nodes[name];
    }
    void connect_node(int from, int to, int w = 0)
    {

        if (!isconnect_block(from, to))
        {
            blocks--;
        }

        RWNode* fromp = insert_node(from);
        RWNode* top = insert_node(to);
        edges.insert(RWEdge(fromp, top, w));
        fromp->connet_out(top);
        top->connet_in(fromp);
    }
    void del_node(int name)
    {
        unordered_map<int, RWNode>::iterator p = nodes.find(name);
        if (p == nodes.end())
            return;
        RWNode q = p->second;
        for (RWNode* k : q.outs)
        {
            del_edge(q.key, k->key);
        }
        for (RWNode* k : q.ins)
        {
            del_edge(k->key, q.key);
        }
        nodes.erase(p);
        blocks--;
    }
    void del_edge(int from, int to)
    {
        RWNode* fromp = insert_node(from);
        RWNode* top = insert_node(to);
        del_edge(RWEdge(fromp, top));
    }
    void del_edge(RWEdge O)
    {
        unordered_set<RWEdge, Hash, Equal>::iterator p = edges.find(O);
        p->from->outs.erase(p->to);
        p->to->ins.erase(p->from);
        if (p != edges.end())
            edges.erase(p);
        RWNode from = *O.from;
        RWNode to = *O.to;

        if (!isconnect_block(from, to))
        {
            blocks++;
        }
    }
    bool isconnect(int from, int to)
    {
        unordered_set<int> vis;
        RWNode fromq = *insert_node(from);
        RWNode toq = *insert_node(to);
        queue<RWNode> q;
        q.push(fromq);
        while (!q.empty())
        {
            fromq = q.front();
            if (fromq == toq)
            {
                return true;
            }
            q.pop();
            for (RWNode* t : fromq.outs)
            {
                if (vis.find(t->key) != vis.end())
                {
                    continue;
                }
                vis.insert(t->key);
                q.push(*t);
            }
        }
        return false;
    }
    bool isconnect_block(int from, int to)
    {
        RWNode fromq = *insert_node(from);
        RWNode toq = *insert_node(to);
        return isconnect_block(fromq, toq);
    }
    bool isconnect_block(RWNode fromq, RWNode toq)
    {
        unordered_set<int> vis;
        queue<RWNode> q;
        q.push(fromq);
        while (!q.empty())
        {
            fromq = q.front();
            if (fromq == toq)
            {
                return true;
            }
            q.pop();
            for (RWNode* t : fromq.outs)
            {
                if (vis.find(t->key) != vis.end())
                {
                    continue;
                }
                vis.insert(t->key);
                q.push(*t);
            }
            for (RWNode* t : fromq.ins)
            {
                if (vis.find(t->key) != vis.end())
                {
                    continue;
                }
                vis.insert(t->key);
                q.push(*t);
            }
        }
        return false;
    }
};