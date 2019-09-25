#include<iostream>
#include<queue>
#include<stack>
 
using namespace std;

struct Box {
    float x; // start position of box
    float width; // width of box
    float height; // height of box
};

int main(){
    // left upper corner of a given box is (x, height)
    // (x, w, h) 
    // example: (1, 1000, 5), (3, 4, 3)
    // 0 1 2 3 4 5 6 idx
    // 0 2 2 3 3 3 3 height

    priority_queue<Box> top_box; // sort -> height, x value of the end_position

    vector<Box> incoming; 
    sort(boxes.begin(), boxes.end()); // Sorted based on x position ascending
    float current_height = 0;
    int counter = 0;
    while(!top_box.empty() || counter < incoming.size()){
        if(!top_box.empty() && (top_box.top().x + top_box.top().width) <= boxes[counter].x){
            // Hit the end of the top box
            box = top_box.top();
            // Draw a line from current position down to the next largest height
            top_box.pop();

        } else {
            // Add the next box
            top_box.push(make_pair(boxes[counter].height, boxes[counter].x + boxes[counter].width));
            if(boxes[counter].height > top_box.top().height){
                // draw
            }
            counter++;
        }
    }
}

