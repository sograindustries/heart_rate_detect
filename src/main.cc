#include <iostream>
#include <vector>

#include "estimate_hr.h"

extern int heartbeat_01[3570];

int main(void) {

  // Creates simple data
  std::vector<int> data;
  for(int ii = 0; ii < sizeof(heartbeat_01)/4; ii++){
    data.push_back(heartbeat_01[ii]);
  }
  std::cout << "Loaded a " << data.size() << " length data set." << std::endl;
  argos::hr_params_s hr_params;
  hr_params.sample_rate = 250;
  hr_params.std_dev_threshold = 3.0;
  hr_params.max_heart_rate = 275;
  int hr;
  hr = argos::EstimateHeartRate(data, hr_params);

  std::cout << "Estimated Heart Rate: " << hr << " (BPM)" << std::endl;
  
  return 0;
}
