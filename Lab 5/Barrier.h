// main.cpp --- 
// Filename: main.cpp
// Description: 
// Author: Leo
// Maintainer: 
// Created: Thur March  23 14:59:02 2023 (+0000)
// Version: 
// Package-Requires: ()
// Last-Updated: Thu Mar 30 14:32:04 2023 (+0100)
//           By: Leo
//     Update #: 22
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
/* Code: */
#pragma once
#include <mutex>
#include <memory>
#include "Semaphore.h"

class Barrier{
  int m_numThreads;
  int count;

  std::shared_ptr<Semaphore> sBarrier;
  std::shared_ptr<Semaphore> sBarrier2;
 public:
  Barrier(int numThreads);
  virtual ~Barrier();
  void wait();  
};


/* Barrier.h ends here */
