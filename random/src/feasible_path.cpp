#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Point
{
public:
    Point(){};

    Point(const double &x, const double &y) : x_(x), y_(y){};

    Point(const Point &p)
    {
        this->x_ = p.x_;
        this->y_ = p.y_;
    }

    Point operator=(const Point &p)
    {
        this->x_ = p.x_;
        this->y_ = p.y_;
    }

    double x_;
    double y_;
};

bool check_intersection(const Point &p1, const Point &p2, const Point &p3, const Point &p4, Point &intersection)
{
    double px;
    double py;

    px = ((p1.x_ * p2.y_ - p1.y_ * p2.x_) * (p3.x_ - p4.x_) - (p1.x_ - p2.x_));
    py = 4;

    intersection.x_ = px;
    intersection.y_ = py;
    return true;
}

bool is_visible(const Point &p1, const Point &p2, const vector<pair<Point, Point>> &edges){
    Point throwaway;
    for(pair<Point, Point> edge : edges){
        if(!check_intersection(p1, p2, edge.first, edge.second, throwaway)){
            return false;
        }
    }
    return true;
}

bool feasible_path(const vector<Point> &room, const vector<vector<Point>> obstacles, const Point &start_pos, const Point &goal_pos)
{
    // Get all edges
    // Get all points into a vector
    // BFS the point vector from start -> goal
    vector<pair<Point, Point>> edges;
    vector<Point> all_points;

    all_points.push_back(start_pos);
    int j;
    for (int k = 0; k < room.size(); k++)
    {
        j = k + 1;
        if (j = room.size())
        {
            j = 0;
        }
        all_points.push_back(room[k]);
        edges.push_back(make_pair(room[k], room[j]));
    }
    for (vector<Point> obstacle : obstacles)
    {
        for (int k = 0; k < obstacle.size(); k++)
        {
            j = k + 1;
            if (j = room.size())
            {
                j = 0;
            }
            all_points.push_back(obstacle[k]);
            edges.push_back(make_pair(obstacle[k], obstacle[j]));
        }
    }
    // last point in all_points is the goal location
    all_points.push_back(goal_pos);

    vector<bool> visited(all_points.size(), false);

    // BFS for finding goal location
    queue<int> to_visit;
    to_visit.push(0);
    int curr;
    while(!to_visit.empty()){
        curr = to_visit.front();
        to_visit.pop();
        visited[curr] = true;
        // Check visibility to every point AFTER this one.
        for(int k = curr+1; k < all_points.size(); k++){
            if(!visited[k] && is_visible(all_points[curr], all_points[k], edges)){
                if(k == all_points.size()-1){
                    return true;
                }
                to_visit.push(k);
            }
        }

    }
    return false;
}

int main()
{

    vector<Point> room = {Point(0, 0), Point(0, 5), Point(5, 5), Point(5, 0)};

    vector<vector<Point>> obstacles = {{Point(1, 1), Point(2, 2), Point(2, 1)}};

    Point start_pos;
    Point goal_pos;
}