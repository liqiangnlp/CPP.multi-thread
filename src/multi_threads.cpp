/*
 * $Id:
 * 0024
 *
 * $File:
 * multi_threads.cpp
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

#include "multi_threads.h"

namespace word_representation_multi_threads {

/*
 * $Name: Join
 * $Function: Join multi threads
 * $Date: 2014-09-12
 */
void MultiThreads::Join() {
#ifdef HAVE_PTHREAD_H
  pthread_join(hnd_, 0);
#else
#ifdef _WIN32
  WaitForSingleObject(hnd_, INFINITE);
  CloseHandle(hnd_);
#endif
#endif
}


/*
 * $Name: Mutex
 * $Function: Mutex
 * $Date: 2014-10-05
 */
Mutex::Mutex() {
#ifdef HAVE_PTHREAD_H
  pthread_mutex_init(&m_mutex, NULL);
#else
#ifdef _WIN32
  m_mutex = ::CreateMutex(NULL, FALSE, NULL);
#endif
#endif
}


/*
 * $Name: ~Mutex
 * $Function: ~Mutex
 * $Date: 2014-10-05
 */
Mutex::~Mutex() {
#ifdef HAVE_PTHREAD_H
  pthread_mutex_destroy(&m_mutex);
#else
#ifdef _WIN32
  ::CloseHandle(m_mutex);
#endif
#endif
}


/*
 * $Name: Init
 * $Function: Init
 * $Date: 2014-10-05
 */
void Mutex::Init() {
#ifdef HAVE_PTHREAD_H
  pthread_mutex_init(&m_mutex, NULL);
#else
#ifdef _WIN32
  m_mutex = ::CreateMutex(NULL, FALSE, NULL);
#endif
#endif
}


/*
 * $Name: Lock
 * $Function: Lock
 * $Date: 2014-10-05
 */
void Mutex::Lock() const {
#ifdef HAVE_PTHREAD_H
  pthread_mutex_lock(&m_mutex);
#else
#ifdef _WIN32
  DWORD d = WaitForSingleObject(m_mutex, INFINITE);
#endif
#endif
}


/*
 * $Name: Unlock
 * $Function: Unlock
 * $Date: 2014-10-05
 */
void Mutex::Unlock() const {
#ifdef HAVE_PTHREAD_H
  pthread_mutex_unlock(&m_mutex);
#else
#ifdef _WIN32
  ::ReleaseMutex(m_mutex);
#endif
#endif
}

}


