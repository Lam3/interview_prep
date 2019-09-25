#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

long minimum_area(vector<vector<int>> points)
{
    unordered_map<int, unordered_set<int>> x_by_y;
    unordered_map<int, unordered_set<int>> y_by_x;

    long min_area = __LONG_MAX__;
    long area;

    for (auto point : points)
    {
        x_by_y[point[1]].insert(point[0]);
        y_by_x[point[0]].insert(point[1]);
    }

    int low_x, low_y, high_x, high_y;

    for (auto point : points)
    {
        // Treat point as our lower left
        low_x = point[0];
        low_y = point[1];
        for (int high_y : y_by_x[low_x])
        {
            // This is our upper left, and thus finding high_y, but only if high_y > low_y
            if (high_y > low_y)
            {

                for (int high_x : x_by_y[low_y])
                {
                    // This is our lower right, and thus finding high_x
                    if (high_x > low_x)
                    {
                        //Check if the top right corner exists, compute area, and update max
                        if(x_by_y[high_y].find(high_x) != x_by_y[high_y].end()){
                            area = (high_y - low_y) * (high_x - low_x);
                            if(area < min_area){
                                min_area = area;
                            }
                        }
                    }

                }
            }
        }
    }
    return min_area;
};

int main()
{
    vector<vector<int>> points = {{5, 0}, {0, 4}, {4, 4}, {4, 0}, {1,2}, {2, 2}, {2,0}};

    cout << "Minimum area of the points is: " << minimum_area(points) << endl;
}