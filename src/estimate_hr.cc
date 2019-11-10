#include <vector>

#include "estimate_hr.h"

namespace {

double GetMean(const std::vector<int>& data) {
  double accum = 0;
  for(int ii = 0; ii < data.size(); ++ii) {
    accum += data[ii];
  }
  return accum / static_cast<double>(data.size());
}

double GetStdDev(const std::vector<int>& data) {
  double mean = GetMean(data);
  double accum = 0;
  for(int ii = 0; ii < data.size(); ++ii) {
    double mean_diff = (static_cast<double>(data[ii]) - mean);
    accum += mean_diff * mean_diff;
  }
  return accum / static_cast<double>(data.size());
}

double GetStdDev(const std::vector<int>& data, const double& mean) {
  double accum = 0;
  for(int ii = 0; ii < data.size(); ++ii) {
    double mean_diff = (static_cast<double>(data[ii]) - mean);
    accum += mean_diff * mean_diff;
  }
  return accum / static_cast<double>(data.size());
}

}
  
int argos::EstimateHeartRate(const std::vector<int>& data, const hr_params_s& hr_params) {
  return 2;
}
