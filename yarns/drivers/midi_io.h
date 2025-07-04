// Copyright 2013 Emilie Gillet.
//
// Author: Emilie Gillet (emilie.o.gillet@gmail.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
// 
// See http://creativecommons.org/licenses/MIT/ for more information.
//
// -----------------------------------------------------------------------------
//
// Driver for dumping log messages to the UART (TX pin).

#ifndef YARNS_DRIVERS_MIDI_IO_H_
#define YARNS_DRIVERS_MIDI_IO_H_

#include "stmlib/stmlib.h"

#include <stm32f10x_conf.h>

namespace yarns {

class MidiIO {
 public:
  
  MidiIO() { }
  ~MidiIO() { }
  
  void Init();
  
  bool writable() {
    return USART1->SR & USART_FLAG_TXE;
  }
  
  bool readable() {
    return USART1->SR & USART_FLAG_RXNE;
  }
  
  void Overwrite(uint8_t byte) {
    USART1->DR = byte;
  }
  
  uint8_t ImmediateRead() {
    return USART1->DR;
  }
  
 private:
  DISALLOW_COPY_AND_ASSIGN(MidiIO);
};

}  // namespace yarns

#endif  // YARNS_DRIVERS_MIDI_IO_H_
