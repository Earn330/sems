#ifndef _RateLimit_h_
#define _RateLimit_h_

#include "AmThread.h"
#include "atomic_types.h"
#include <sys/types.h>

class RateLimit
  : protected AmMutex
{
  u_int32_t last_update;
  int rate;
  int peak;
  int counter;

  unsigned int time_base;

  void update_limit();

public:
  // rate: units/time_base
  // peak: units/time_base
  // time_base: seconds
  RateLimit(unsigned int rate, unsigned int peak, 
	    unsigned int time_base);

  /**
   * returns true if 'size' should be dropped
   */
  bool limit(unsigned int size);
};

#endif