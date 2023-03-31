/* SafeBuffer.h --- 
 * 
 * Filename: SafeBuffer.h
// Description: 
// Author: Leo
// Maintainer: 
// Created: Thur March  23 14:59:02 2023 (+0000)
// Version: 
// Package-Requires: ()
// Last-Updated: Fri Mar 31 18:11:24 2023 (+0100)
//           By: Leo
//     Update #: 33
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
/* Code: */

#include "Event.h"
#include <vector>
#include "Semaphore.h"
class SafeBuffer
{
private:
  std::vector<Event> m_events;
  Event m_event;
  
 public:
  void add(Event t_event);
  Event get();
  SafeBuffer();
  ~SafeBuffer(){};
};


/* SafeBuffer.h ends here */
