/*
 * $Id:
 * 0001
 *
 * $File:
 * main.h
 *
 * $Proj:
 * 
 *
 * $Func:
 * header file of main function
 *
 * $Version:
 * 1.0.0
 *
 * $Created by:
 * Qiang Li
 *
 * $Email
 * liqiangneu@gmail.com
 *
 * $Last Modified by:
 * 20140703, 20:58
 */

#ifndef WORD_REPRESENTATION_MAIN_H_
#define WORD_REPRESENTATION_MAIN_H_

#include <iostream>
#include <vector>
#include "multi_threads.h"

using namespace std;
using namespace word_representation_multi_threads;


class Test{
 public:
  Mutex lock;
 public:
  Test(){
    i = 0;
    lock.Init();
  }
 public:
  int i;

 public:
  void Compute();
  void ComputeMultiThread(int &id);
};

class TestThreads : public MultiThreads {
 public:
  Test * p_test_;

 public:
  void *TrainModelThread();

 private:
  static void *Wrapper(void *ptr) {
    TestThreads *this_ptr = (TestThreads *)ptr;
    this_ptr->TrainModelThread();
    return 0;
  }

  public:
    void Start();
  };



#endif
