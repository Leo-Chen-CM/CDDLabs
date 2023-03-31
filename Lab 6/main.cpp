//#include "Barrier.h"
#include "Event.h"
#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <vector>
#include <memory>
// main.cpp --- 
// Filename: main.cpp
// Description: 
// Author: Leo
// Maintainer: 
// Created: Thur March  23 14:59:02 2023 (+0000)
// Version: 
// Package-Requires: ()
// Last-Updated: Fri Mar 31 10:55:14 2023 (+0100)
//           By: Leo
//     Update #: 38
// URL: 
// Doc URL: 
// Keywords: 
// Compatibility: 
// 
// 

// Commentary: 
// 
// 
// 
// 

// Change Log:
// 
// 
// 
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at
// your option) any later version.
// 
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
// 
// 

static const int num_threads = 100;
const int size=20;
std::shared_ptr<Semaphore> m_mutex;
std::shared_ptr<Semaphore> m_items;

/*! \fn producer
    \brief Creates events and adds them to buffer
*/

void producer(std::shared_ptr<SafeBuffer<std::shared_ptr<Event>> theBuffer, int numLoops){

  for(int i=0;i<numLoops;++i)
    {
    //Produce event and add to buffer
    Event e= createEvent(i);
    m_mutex->wait();
    theBuffer->add(e);
    m_items->signal();
    m_mutex->signal();
    }
  

}

/*! \fn consumer
    \brief Takes events from buffer and consumes them
*/

void consumer(std::shared_ptr<SafeBuffer<std::shared_ptr Event>> theBuffer, int numLoops)
{

  for(int i=0;i<numLoops;++i)
    {
    //Produce event and add to buffer

    m_items->wait();
    m_mutex->wait();
    
    std::shared_ptr<Event> e= theBuffer->get();

    m_mutex->signal();
    e->consume();
    }
  

}

int main(void)
{

  std::vector<std::thread> vt(num_threads);
  std::shared_ptr<SafeBuffer<std::shared_ptr<Event>> aBuffer( new Buffer<shared_ptr Event>(size));

  m_mutex = std::make_shared<Semaphore>(1);
  m_items =  std::make_shared<Semaphore>(0);
  
  /**< Launch the threads  */
  int i=0;
  for(std::thread& t: vt)
    {
    t=std::thread(updateTask,aBuffer,10);
  }
  
  /**< Join the threads with the main thread */
  for (auto& v :vt)
    {
      v.join();
  }
  std::cout << sharedVariable << std::endl;
  return 0;
}
//barrier
