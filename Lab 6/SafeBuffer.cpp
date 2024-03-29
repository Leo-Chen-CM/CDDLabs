// SafeBuffer.cpp --- 
// 
// Filename: SafeBuffer.cpp
// Description: 
// Author: Leo
// Maintainer: 
// Created: Thu Mar 30 14:59:49 2023 (+0100)
// Last-Updated: Fri Mar 31 16:39:51 2023 (+0100)
//           By: Leo
//     Update #: 10
// 
// 

// Commentary: 
// 
// 
// 
// 
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
#include "SafeBuffer.h"

SafeBuffer::SafeBuffer()
{
  
}

void SafeBuffer::add(Event t_event)
{
  m_events.push_back(t_event);
}

Event SafeBuffer::get()
{
  m_event = m_events.back();
  m_events.pop_back();
  return m_event;
}

// 
// SafeBuffer.cpp ends here
