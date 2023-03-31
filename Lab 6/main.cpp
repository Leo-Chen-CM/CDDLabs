//#include "Barrier.h"
#include "Event.h"
#include "Semaphore.h"
#include "SafeBuffer.h"
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
// Last-Updated: Fri Mar 31 16:56:57 2023 (+0100)
//           By: Leo
//     Update #: 74
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

static const int num_threads = 10;
const int size=20;
std::shared_ptr<Semaphore> m_mutex;
std::shared_ptr<Semaphore> m_items;

/*! \fn producer
    \brief Creates events and adds them to buffer
*/

void producer(std::shared_ptr<SafeBuffer> theBuffer, int numLoops){

  for(int i=0;i<numLoops;++i)
    {
    //Produce event and add to buffer
      Event e = Event();

      m_mutex->Wait();
      theBuffer->add(e);
      m_mutex->Signal();
      m_items->Signal();

    std::cout << "Character was added to the buffer" <<std::endl;
    }
  

}

/*! \fn consumer
    \brief Takes events from buffer and consumes them
*/

void consumer(std::shared_ptr<SafeBuffer> theBuffer)
{

 m_items->Wait();
 m_mutex->Wait();

 Event e = theBuffer->get();

  m_mutex->Signal();
  e.Process();
  std::cout << "Character was taken out of the buffer" <<std::endl;
}

int main(void)
{

  std::vector<std::thread> producersThread(num_threads);
  std::vector<std::thread> consumersThread(num_threads);

  std::shared_ptr<SafeBuffer> theBuffer(new SafeBuffer);



  for(std::thread&t : producersThread)
    {
      t = std::thread(producer, theBuffer, 10);
    }


  for(std::thread&t : consumersThread)
    {
	t = std::thread(consumer, theBuffer);
    }

  /**< Join the threads with the main thread */
  for (auto& v :producersThread)
    {
      v.join();
    }

  for (auto& v :consumersThread)
    {
      v.join();
    }
 
  return 0;
}
//barrier
