// Event.cpp --- 
// 
// Filename: Event.cpp
// Description: 
// Author: Leo
// Maintainer: 
// Created: Thu Mar 30 16:02:13 2023 (+0100)
// Last-Updated: Fri Mar 31 16:51:23 2023 (+0100)
//           By: Leo
//     Update #: 18
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

//
#include "Event.h"
Event::Event()
{
  m_Letters = {'A','B', 'C','D','E', 'F','G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  
}

// 
// Event.cpp ends here


char Event::Process()
{
  int randomLetterNumber = std::rand() % 0 + m_Letters.size();
  m_letter = m_Letters[randomLetterNumber];

  return m_letter;
}
