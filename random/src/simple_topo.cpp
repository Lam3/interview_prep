#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <list>

class Graph{
    public:
        Graph(int num_vertex){
            this->v = num_vertex;
            outgoing = std::vector<std::unordered_set<int>>(this->v);
        };

        ~Graph(){};

        void add_edge(int beginning, int destination){
            this->outgoing[beginning].insert(destination);
        }

        void show_edges(){
            for(int k = 0; k < outgoing.size(); k++){
                for(int val : outgoing[k]){
                    std::cout << "Node " << k << " points to node " << val << std::endl;
                }
            }
        }

        void topo_sort(std::vector<int> &sorted);

    private:
        int v; // number of vertices
        std::vector<std::unordered_set<int>> outgoing;
};

void Graph::topo_sort(std::vector<int> &sorted){
    
    std::vector<std::unordered_set<int>> incoming(this->v);
    for(int k = 0; k < this->v; k++){
        for(int val : outgoing[k]){
            incoming[val].insert(k);
        }
    }
    
    std::vector<bool> added(this->v, false);
    std::list<int> heads;
    for(int k = 0; k < this->v; k++){
        if(incoming[k].empty()){
            heads.push_back(k);
            added[k] = true;
        }
    }

    std::vector<bool> visited(this->v, false);
    while(!heads.empty()){
        int head = heads.front();
        heads.pop_front();

        visited[head] = true;
        sorted.push_back(head);

        for(int child : outgoing[head]){
            // if all incoming for child are in visited, it becomes a head
            // otherwise, pass
            if(added[child]){
                continue;
            }
            bool pass = true;
            for(int inc : incoming[child]){
                if(!visited[inc]){
                    pass = false;
                    break;
                }
            }
            if(pass){
                added[child] = true;
                heads.push_back(child);
            }
        }
    }
}

int main(){
    Graph G(6);
    G.add_edge(0,1);
    G.add_edge(1,2);
    G.add_edge(1,4);
    G.add_edge(2,3);
    G.add_edge(3,5);
    G.add_edge(4,2);

    G.show_edges();
    std::vector<int> sorted;
    G.topo_sort(sorted);
    for(int k : sorted){
        std::cout << k << ", ";
    }
    std::cout << std::endl;
}