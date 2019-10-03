#include <iostream>
#include <math.h>
#include <vector>
#include <bits/stdc++.h>

#define PI 3.14159

using namespace std;

class Point
{
public:
    Point(const double &x, const double &y)
    {
        x_ = new double(x);
        y_ = new double(y);
        cout << "Point x, y constructor called" << endl;
    };

    Point(const Point &p)
    {
        cout << "Point copy constructor called" << endl;
        this->x_ = p.x_;
        this->y_ = p.y_;
    }

    Point operator=(const Point &p)
    {
        cout << "Point assignment operator called" << endl;
        this->x_ = p.x_;
        this->y_ = p.y_;
    }

    Point()
    {
        cout << "Point empty constructor called" << endl;
    }
    double *x_;
    double *y_;
};

double optimalFOV(const vector<Point> &trees, const Point &start, const double &alpha)
{
    vector<double> angles(trees.size());
    int n = trees.size();
    for (int k = 0; k < n; k++)
    {
        angles[k] = atan2(*trees[k].y_, *trees[k].x_);
        if (angles[k] < 0)
        {
            angles[k] += 2 * PI;
        }
    }
    sort(angles.begin(), angles.end());

    vector<double> wrapped_angles(angles.size() * 2);
    for (int k = 0; k < angles.size(); k++)
    {
        wrapped_angles[k] = angles[k];
        wrapped_angles[k + n] = angles[k] + 2 * PI;
    }

    double result = wrapped_angles[0];
    int max_in_view = 0;
    int j = 0;
    for (int k = 0; k < angles.size(); k++)
    {
        // We're using doubles here, so need to watch out for "slop"
        while (j < wrapped_angles.size() && wrapped_angles[j + 1] - wrapped_angles[k] <= alpha)
        {
            j++;
        }
        if (j - k > max_in_view)
        {
            max_in_view = j - k + 1;
            result = angles[k];
        }
    }
    return result;
}

class Line
{
public:

    Line(const Point &a, const Point &b)
    {
        a_ = new Point(a);
        b_ = new Point(b);
        slope = (*(b_->y_) - *(a_->y_)) / (*(b_->x_) - *(a_->x_));
        intercept = *(b_->y_) - ( *(b_->x_) * (this->slope));
    }

    bool checkCollision(const Line &obstacle){
        if(obstacle.slope != this->slope){
            return true;
        } else {
            return (obstacle.intercept == this->intercept);
        }
    }

    bool checkCollison(const Line &obstacle, Point &intersect){
        // overloaded function, includes intersect which will be set to the intersection point
        if(!this->checkCollision(obstacle)){
            return false;
        }
        return true;
        // Calculate the collision position and set intersect->x, intersect->y
    }


private:
    Point *a_, *b_;
    double slope;
    double intercept;
};

int main()
{
    vector<Point> trees = {Point(1, 1), Point(.9, 1), Point(-2, -2), Point(-2, -1.7)};
    Point start(0, 0);
    double alpha = PI / 4;

    cout << "Optimal pointing angle is: " << optimalFOV(trees, start, alpha) * 180 / PI << endl;
}