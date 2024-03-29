/* SafeBuffer.h --- 
 * 
 * Filename: SafeBuffer.h
// Description: 
// Author: Leo
// Maintainer: 
// Created: Thur March  23 14:59:02 2023 (+0000)
// Version: 
// Package-Requires: ()
// Last-Updated: Fri Mar 31 14:18:14 2023 (+0100)
//           By: Leo
//     Update #: 25
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
class SafeBuffer
{
  SafeBuffer(int t_bufferSize);
  int m_bufferSize;
 public:
  void add(Event t_event);
  Event get();
  void process();
};


/* SafeBuffer.h ends here */
