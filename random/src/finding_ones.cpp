#include <vector>
#include <iostream>
#include <list> 

using namespace std;

int largest_cluster(const vector<vector<int>> &arr){
    bool visited[arr.size()][arr[0].size()] = {false};
    int max_cluster = 0;
    
    for(int k = 0; k < arr.size(); k++){
        for(int j = 0; j < arr.size(); j++){

            if(arr[k][j] && !visited[k][j]){
                visited[k][j] = true;
                int cluster_size = 0;
                list<pair<int, int>> to_expand;
                to_expand.push_back(make_pair(k, j));
                
                while(!to_expand.empty()){
                    pair<int, int> curr = to_expand.front();
                    to_expand.pop_front();
                    cluster_size++;

                    // Check all neighbors
                    // Above
                    if(curr.first != 0 && !visited[curr.first-1][curr.second] && arr[curr.first-1][curr.second]){
                        to_expand.push_back(make_pair(curr.first-1, curr.second));
                        visited[curr.first-1][curr.second] = true;
                    }
                    // Below
                    if(curr.first != arr.size()-1 && !visited[curr.first +1][curr.second] && arr[curr.first +1][curr.second]){
                        to_expand.push_back(make_pair(curr.first+1, curr.second));
                        visited[curr.first+1][curr.second] = true;
                    }
                    // Left
                    if(curr.second != 0 && !visited[curr.first][curr.second-1] && arr[curr.first][curr.second-1]){
                        to_expand.push_back(make_pair(curr.first, curr.second-1));
                        visited[curr.first][curr.second-1] = true;
                    }
                    // Right
                    if(curr.second != arr[0].size()-1 && !visited[curr.first][curr.second+1] && arr[curr.first][curr.second+1]){
                        to_expand.push_back(make_pair(curr.first, curr.second+1));
                        visited[curr.first][curr.second+1] = true;
                    }

                }
                if(max_cluster < cluster_size){
                    max_cluster = cluster_size;
                }
            }
        }
    }
    return max_cluster;
}

int main(){
    vector<vector<int>> arr = {{1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {0, 0, 0, 0, 1}};
    // vector<int> row = {0, 1, 0, 1, 1};
    int soln = largest_cluster(arr);
    cout << "Largest cluster inside array is of size: " << soln << endl;
}