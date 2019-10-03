#include<iostream>
#include<queue>
#include<stack>
#include<bits/stdc++.h>
 
using namespace std;

struct Box {
        Box(){};
        Box(float x, float w, float h):x(x), width(w), height(h){};

        void show(){
            cout << "X position: " << this->x << endl;
            cout << "Width: " << this->width << endl;
            cout << "Height: " << this->height << endl;
        }

        float x; // start position of box
        float width; // width of box
        float height; // height of box
};

bool operator<(const Box &a, const Box &b){
    if(a.height >= b.height){
        return true;
    } else {
        return false;
    }
}

bool compareBoxes(Box a, Box b){
    if(a.x < b.x){
        return true;
    } else if(b.x < a.x){
        return false;
    } else {
        if(a.height <= b.height){
            return true;
        } else {
            return false;
        }
    }
}

bool operator<(const vector<int>& a, const vector<int>& b){
    if(a[0] < b[0]){
        return true;
    } else {
        return false;
    }
}

int main(){
    Box a(1, 5, 1);
    Box b(3, 2, 4);
    Box c(6, 1, 1);

    vector<Box> boxes;
    boxes.push_back(c);
    boxes.push_back(a);
    boxes.push_back(b);
    cout << "BEFORE SORT: " << endl;
    for(Box box : boxes){
        box.show();
        cout << endl;
    }

    sort(boxes.begin(), boxes.end(), compareBoxes);
    cout << endl << "AFTER SORT: " << endl;
    for(Box box : boxes){
        box.show();
        cout << endl;
    }

    priority_queue<Box> top_box;
    int counter = 0;
    int x = 0, y = 0;
    Box current;
    while(!top_box.empty() || counter < boxes.size()){
        // If pq is empty or the top_box right side is >= left edge of next box, add next box
        if(top_box.empty() || (top_box.top().x + top_box.top().width) >= boxes[counter].x){
            top_box.push(boxes[counter]);
            counter++;
        } else {
            // move to end of top_box.top()
            current = top_box.top();
            top_box.pop();
        }
    }
}