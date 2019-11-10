#ifndef _ARGOS_ESTIMATE_HR_H_
#define _ARGOS_ESTIMATE_HR_H_

#include <vector>

typedef struct {
  int sample_rate;
  float std_dev_threshold;
} hr_params_s;

int EstimateHeartRate(std::vector<int> data, hr_param_s hr_param);

#endif _ARGOS_ESTIMATE_HR_H_
