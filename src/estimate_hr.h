#ifndef _ARGOS_ESTIMATE_HR_H_
#define _ARGOS_ESTIMATE_HR_H_

#include <vector>

namespace argos {

typedef struct {
  int sample_rate;
  float std_dev_threshold;
} hr_params_s;

int EstimateHeartRate(const std::vector<int>& data, const hr_params_s& hr_param);


}
#endif _ARGOS_ESTIMATE_HR_H_
