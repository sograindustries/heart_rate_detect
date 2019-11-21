#include <iostream>
#include <math.h>
#include <vector>

#include "estimate_hr.h"
#include "fir_filter.h"

namespace {

  // Textual include
  #include "kernels.cc"
  
  FirFilter<double, kQrsFilterLength, kQrsFilterKernel> qrs_filter;
  FirFilter<double, kMaFilterLength, kMaFilter> ma_filter;

}
int argos::EstimateHeartRate(const std::vector<int>& data, const hr_params_s& hr_params) {

  // Process new data
  for(int ii = 0; ii < data.size(); ++ii) {
    qrs_filter.put(data[ii]);
    const double qrs_sample = qrs_filter.get();
    ma_filter.put(qrs_sample * qrs_sample);
    const double ma_sample = ma_filter.get();
  }
  
  return 0;
}


