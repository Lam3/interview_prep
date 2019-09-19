#include <queue>
#include <inttypes.h>
#include <iostream>

uint32_t GetData();

class MovingAverageFilter{
  public:
    MovingAverageFilter(uint32_t filter_size){
      running_sum = 0;
      filter_size = filter_size;
    }
    
    void addData(uint32_t data_point){
      data_stream.push(data_point);
      running_sum += data_point;
      
      if(data_stream.size() > filter_size){
        running_sum -= data_stream.top();
        data_stream.pop();
      }
    }
    
    double getAverage(){
      return (double)running_sum / (double)data_stream.size();
    }
    
  private:
    queue<uint32_t> data_stream;
    uint32_t running_sum;
    uint32_t filter_size;
};

int main() {
  MovingAverageFilter filter(10);
  uint32_t current_average;
  while (true) {
    // Retrieve the data from the sensor.
    filter.addData(GetData());
    // Compute the moving average.
    current_average = filter.getAverage();
    // Output the result to the console.
    std::cout << "Current average is: " << current_average << std::endl;
    // Wait .02;
  }
}

// Forgot to initialize the queue in constructor 
// Forgot a destructor (?)
// const + pass by reference would have been better
// maybe should have been a pointer to priority queue?