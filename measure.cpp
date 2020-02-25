#include <iostream>
#include <string>
#include <chrono>
#include <stdlib.h>
#include <time.h>
#include "List.h"

using namespace std;
using namespace cop4530;

#define REPEATS 5

int main(int argc, char ** argv) {

   List<int> nums100[REPEATS];
   List<int> nums1000[REPEATS];
   List<int> nums10000[REPEATS];

   int cnt100 = 100;
   int cnt1000 = 1000;
   int cnt10000 = 10000;
   int range100 = cnt100 / 3;
   int range1000 = cnt1000 / 3;
   int range10000 = cnt10000 / 3;

   for (int j = 0; j < REPEATS; j++) {
      /* initialize a random seed;
       * generate a random number between 1 and range.  */
      srand (time(NULL));
      for (int i = 0; i < cnt100; i++) {
         int item = rand() % range100 + 1;
         nums100[j].push_back(item);
      }
      for (int i = 0; i < cnt1000; i++) {
         int item = rand() % range1000 + 1;
         nums1000[j].push_back(item);
      }
      for (int i = 0; i < cnt10000; i++) {
         int item = rand() % range10000 + 1;
         nums10000[j].push_back(item);
      }

   }

   auto r_start = chrono::steady_clock::now();
   for (int i = 0; i < REPEATS; i++) {
      nums100[i].deduplicate();
   }
   auto r_end = chrono::steady_clock::now();

   int usec = chrono::duration_cast<chrono::microseconds>(r_end - r_start).count();
   cout << "dedupe " <<cnt100<<"-item list: " << usec/REPEATS<<" usec"<<endl;

   r_start = chrono::steady_clock::now();
   for (int i = 0; i < REPEATS; i++) {
      nums1000[i].deduplicate();
   }
   r_end = chrono::steady_clock::now();

   usec = chrono::duration_cast<chrono::microseconds>(r_end - r_start).count();
   cout << "dedupe " <<cnt1000<<"-item list: " << usec/REPEATS<<" usec"<<endl;

   r_start = chrono::steady_clock::now();
   for (int i = 0; i < REPEATS; i++) {
      nums10000[i].deduplicate();
   }
   r_end = chrono::steady_clock::now();

   usec = chrono::duration_cast<chrono::microseconds>(r_end - r_start).count();
   cout << "dedupe " <<cnt10000<<"-item list: " << usec/REPEATS<<" usec"<<endl;
 /*  usec = chrono::duration_cast<chrono::microseconds>(r_end - r_start).count();
   cout << "dedupe " <<cnt100<<"-item list: " << usec/REPEATS<<" usec"<<endl;


   usec = chrono::duration_cast<chrono::microseconds>(r_end - r_start).count();
   cout << "dedupe " <<cnt1000<<"-item list: " << usec/REPEATS<<" usec"<<endl;

   usec = chrono::duration_cast<chrono::microseconds>(r_end - r_start).count();
   cout << "dedupe " <<cnt100000<<"-item list: " << usec/REPEATS<<" usec"<<endl;
*/
   r_start = chrono::steady_clock::now();
   for (int i = 0; i < REPEATS; i++) {
      nums100[i].reverse();
   }
   r_end = chrono::steady_clock::now();

   usec = chrono::duration_cast<chrono::microseconds>(r_end - r_start).count();
   cout << "reverse " <<cnt100<<"-item list: " << usec/REPEATS<<" usec"<<endl;

   r_start = chrono::steady_clock::now();
   for (int i = 0; i < REPEATS; i++) {
      nums1000[i].reverse();
   }
   r_end = chrono::steady_clock::now();

   usec = chrono::duration_cast<chrono::microseconds>(r_end - r_start).count();
   cout << "reverse " <<cnt1000<<"-item list: " << usec/REPEATS<<" usec"<<endl;

   r_start = chrono::steady_clock::now();
   for (int i = 0; i < REPEATS; i++) {
      nums10000[i].reverse();
   }
   r_end = chrono::steady_clock::now();

   usec = chrono::duration_cast<chrono::microseconds>(r_end - r_start).count();
   cout << "reverse " <<cnt10000<<"-item list: " << usec/REPEATS<<" usec"<<endl;
   return 0;
}

