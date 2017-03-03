/*
 * $Id:
 * 0002
 *
 * $File:
 * main.cpp
 *
 * $Proj:
 * 
 *
 * $Func:
 * main function
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
 * 20120704, 20:59
 */

#include "main.h"

int main(int argc, char * argv[]) {
  vector<TestThreads> v_test_threads;
  v_test_threads.resize(5);
  Test test;
  test.Compute();
  return 0;
}


void Test::Compute() {
  vector<TestThreads> v_test_threads;
  v_test_threads.resize(5);
  for (int i = 0; i < 5; ++i) {
    v_test_threads.at(i).id_ = i;
    v_test_threads.at(i).p_test_ = this;
    v_test_threads.at(i).Start();
  }

  for (int i = 0; i < 5; ++i) {
    v_test_threads.at(i).Join();
  }

  return;
}


void Test::ComputeMultiThread(int &id) {
  cerr << "id=" << id << "\n" <<flush;
//  lock.Lock();
  for (int j = 0; j < 10000; ++j) {
    i += j;
    cerr << "id=" << id << " j="<<j<<" i=" << i << "\n" << flush;
  }
//  lock.Unlock();
  return;
}



void TestThreads::Start() {
#ifdef HAVE_PTHREAD_H
  pthread_create(&hnd_, 0, &TestThreads::Wrapper, static_cast<void *>(this));
#else
#ifdef _WIN32
  DWORD dword_id;
  hnd_ = BEGINTHREAD(0, 0, &TestThreads::Wrapper, this, 0, &dword_id);
#else
  TrainModelThread();
#endif
#endif
}


void *TestThreads::TrainModelThread() {
  p_test_->ComputeMultiThread(id_);
  return 0;
}




