#include <iostream>
#include <list>
#include <vector>

class Graph{
    public:
        Graph(int num_nodes);
        
        void add_edge(int start, int end);

        std::list<int> BFS(int start);

        std::list<int> DFS();

    private:
        int v;

        // Adjacency lists
        std::list<int> *adj;

        void DFSutil(int start, std::vector<bool> *visited, std::list<int> *visited_order);

};

Graph::Graph(int num_nodes){
    this->v = num_nodes;
    adj = new std::list<int>[this->v];
}

void Graph::add_edge(int start, int end){
    adj[start].push_back(end);
}

std::list<int> Graph::DFS(){
    std::vector<bool> *visited = new std::vector<bool>(this->v);
    std::list<int> visited_order;

    for(int k = 0; k < this->v; ++k){
        visited->push_back(false);
    }
    for(int k = 0; k < this->v; ++k){
        if(!(*visited)[k]){
            DFSutil(k, visited, &visited_order);
        }
    }
    std::cout << "SEARCH COMPLETE" << std::endl;
    return visited_order;
}

void Graph::DFSutil(int start, std::vector<bool> *visited, std::list<int> *visited_order){
    (*visited)[start] = true;
    std::cout << "Expanding " << start << std::endl;
    // visited_order->push_back(start);
    // std::cout << "About to get children" << std::endl;
    for(int child : adj[start]){
        std::cout << "About to check: " << child << std::endl;
        if(!(*visited)[child]){
            DFSutil(child, visited, visited_order);
        }
    }
    std::cout << "Finished node: " << start << std::endl;
    (*visited_order).push_back(start);
}

std::list<int> Graph::BFS(int start){
    std::vector<bool> visited;
    for (int k = 0; k < v; ++k){
        visited.push_back(false);
    }
    visited[start] = true;

    std::list<int> visit_order;
    std::list<int> queue;
    queue.push_back(start);
    int curr; // current node
    while(!queue.empty()){
        curr = queue.front();
        queue.pop_front();
        visit_order.push_back(curr);

        for(int child : adj[curr]){
            if(!visited[child]){
                queue.push_back(child);
                visited[child] = true;
            }
        }

    }
    return visit_order;
}

int main(){
    // Create a graph given in the above diagram 
    Graph g(4); 
    g.add_edge(0, 1); 
    g.add_edge(0, 2); 
    g.add_edge(1, 2); 
    g.add_edge(2, 0); 
    g.add_edge(2, 3); 
    g.add_edge(3, 3); 
  
    std::cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 

    std::list<int> order = g.BFS(2);

    for(int k : order){
        std::cout << k << ", ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "Following is Depth First Traversal " << std::endl;
    order = g.DFS();
    for(int k : order){
        std::cout << k << ", ";
    }
    std::cout << std::endl << std::endl;

    return 0;
}