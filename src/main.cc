#include <iostream>
#include <vector>

#include "estimate_hr.h"

int main(void) {

  // Creates simple data
  std::vector<int> data;
  for(int ii = 0; ii < 100; ii++){
    data.push_back(ii);
  }
  argos::hr_params_s hr_params;
  hr_params.sample_rate = 250;
  hr_params.std_dev_threshold = 3.0;

  int hr;
  hr = argos::EstimateHeartRate(data, hr_params);

  std::cout << "Estimated Heart Rate: " << hr << std::endl;
  
  return 0;
}
