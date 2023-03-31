// Barrier.cpp --- 
// 
// Filename: Barrier.cpp
// Description: 
// Author: Joseph
// Maintainer: 
// Created: Tue Jan  8 12:14:02 2019 (+0000)
// Version: 
// Package-Requires: ()
// Last-Updated: Thu Mar 30 14:38:12 2023 (+0100)
//           By: Leo
//     Update #: 44
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

// Code:

#include "Barrier.h"
#include "Semaphore.h"
#include <iostream>
Barrier::Barrier(int numThreads)
{
  m_numThreads = numThreads;
  count=0;
  sBarrier = std::make_shared<Semaphore>(0);
  sBarrier2 = std::make_shared<Semaphore>(1);
  
}
Barrier::~Barrier()
{
  //NOTHING TO DO
}

void Barrier::wait()
{
//Airlock Open
//Airlock 2 Closed
count++;
if(count == m_numThreads)
    {
      sBarrier2->Wait();
      std::cout<<std::endl<<"ALL HERE"<<std::endl;
      sBarrier->Signal();
    }
 sBarrier->Wait();
 sBarrier->Signal();
 
  //Airlock Closed
  //Airlock 2 Open

  count--;
  if(count == 0)
    {
      sBarrier->Wait();
      sBarrier2->Signal();
    }
  sBarrier2->Wait();
  sBarrier2->Signal();
  }

// 
// Barrier.cpp ends here
/*



*/
