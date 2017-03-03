/*
 * $Id:
 * 0023
 *
 * $File:
 * multi_threads.h
 *
 * $Proj:
 *
 * $Func:
 *
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
 * 2014-09-12, 11:43
 */

#ifndef WORD_REPRESENTATION_MULTI_THREADS_H_
#define WORD_REPRESENTATION_MULTI_THREADS_H_

#include <iostream>


#ifndef _WIN32                         // _WIN32: Defined for applications for Win32 and Win64, always defined
#define HAVE_PTHREAD_H                 // for Linux
#endif

#ifdef HAVE_PTHREAD_H
#include <pthread.h>
#else
#ifdef _WIN32
#include <windows.h>
#include <process.h>
#endif
#endif

#if defined HAVE_PTHREAD_H
#define _USE_NTHREAD 1
#endif

#if (defined(_WIN32) && !defined(__CYGWIN__))
#define _USE_NTHREAD 1
#define BEGINTHREAD(src, stack, func, arg, flag, id) (HANDLE)_beginthreadex((void *)(src), (unsigned)(stack), \
    (unsigned(_stdcall *)(void *))(func), (void *)(arg), \
    (unsigned)(flag),(unsigned *)(id))
#endif

using namespace std;

namespace word_representation_multi_threads {
class MultiThreads {
 public:
#ifdef HAVE_PTHREAD_H
  pthread_t hnd_;
#else
#ifdef _WIN32
  HANDLE hnd_;
#endif
#endif

 public:
  int id_;

 public:
  virtual void Start() {};
  void Join();
};


class Mutex {
 public:
  Mutex();
  ~Mutex();

 public:
  void Init();

 public:
  void Lock() const;
  void Unlock() const;

private:

#ifdef HAVE_PTHREAD_H
  mutable pthread_mutex_t m_mutex;
#else
#ifdef _WIN32
  HANDLE m_mutex;
#endif
#endif

};


}

#endif

