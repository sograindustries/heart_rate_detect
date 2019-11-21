#include <iostream>
#include <vector>

#include "estimate_hr.h"

extern double heartbeat_01[5000];

int main(void) {

  // Creates simple data
  //  std::cout << "Loaded a " << data.size() << " length data set." << std::endl;
  argos::hr_params_s hr_params;
  hr_params.sample_rate = 250;
  hr_params.std_dev_threshold = 3.0;
  hr_params.max_heart_rate = 275;
  int hr;

  for (int jj = 0; jj < 5; ++jj) {
    std::vector<int> data;
    for(int ii = 0; ii < 1000; ii++){
      data.push_back(heartbeat_01[ii + 1000*jj]);
    }
    hr = argos::EstimateHeartRate(data, hr_params);
    std::cout << "Estimated Heart Rate: " << hr << " (BPM)" << std::endl;
  }
  
  return 0;
}
