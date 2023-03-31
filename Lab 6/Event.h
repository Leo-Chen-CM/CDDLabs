/* Event.h --- 
 * 
 * Filename: Event.h
// Description: 
// Author: Leo
// Maintainer: 
// Created: Thu Mar 30 14:59:49 2023 (+0100)
// Last-Updated: Fri Mar 31 16:50:35 2023 (+0100)
//           By: Leo
//     Update #: 21
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

/* Code: */
#ifndef EVENT_H
#define EVENT_H 
#include <vector>
#include <cstdlib>
class Event
{
 public:
  char m_letter;
  char CreateEvent();
  char Process();
  std::vector<char> m_Letters;
  Event();
  ~Event(){};
};

#endif

/* Event.h ends here */
