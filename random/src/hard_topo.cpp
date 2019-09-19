#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

struct Node{
    int idx;
    std::vector<Node*> outgoing; 
};

class Graph{
    public:
        Graph(){};
        
        void add_node(Node *node){
            nodes.push_back(node);
        };

        std::vector<Node*> topological_sort();

    private:
        std::vector<Node*> nodes;
};

std::vector<Node*> Graph::topological_sort(){
    std::unordered_map<Node*, std::unordered_set<Node*>> incoming;
    std::unordered_set<Node*> visited;
    
    // build incoming
    for(auto node : this->nodes){
        for(auto target : node->outgoing){
            incoming[target].insert(node);
        }        
    }


}

int main(){
    Graph G;
    
    Node a, b, c, d, e;
    
    a.outgoing.push_back(&b);
    a.idx = 1;
    a.outgoing.push_back(&c);
    b.outgoing.push_back(&c);
    b.idx = 2;
    c.outgoing.push_back(&d);
    c.idx = 3;
    d.outgoing.push_back(&e);
    d.index = 4;
    e.index = 5;

    G.add_node(&a);
    G.add_node(&b);
    G.add_node(&c);
    G.add_node(&d);
    G.add_node(&e);


}