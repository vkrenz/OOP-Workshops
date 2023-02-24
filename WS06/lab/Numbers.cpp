#include <fstream>
#include "Numbers.h"
using namespace std;
namespace sdds {
   void Numbers::sort(double* nums, unsigned int size) {
      unsigned int i, j;
      double temp;
      for(i = size - 1; size && i > 0; i--) {
         for(j = 0; j < i; j++) {
            if(nums[j] > nums[j + 1]) {
               temp = nums[j];
               nums[j] = nums[j + 1];
               nums[j + 1] = temp;
            }
         }
      }
   }

   unsigned int Numbers::countLines(const char* filename) { /**/
      unsigned int lines = 0u;
      ifstream nums(filename);
      while(nums) {
         lines += (nums.get() == '\n');
      }
      return lines;
   }
}