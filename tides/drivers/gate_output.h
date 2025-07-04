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
// Driver for the end of cycles output pins.

#ifndef TIDES_DRIVERS_GATE_OUTPUT_H_
#define TIDES_DRIVERS_GATE_OUTPUT_H_

#include "stmlib/stmlib.h"

#include <stm32f10x_conf.h>

namespace tides {

class GateOutput {
 public:
  GateOutput() { }
  ~GateOutput() { }
  
  void Init();
  
  inline void Write(bool end_of_attack, bool end_of_release) {
    if (end_of_attack) {
      GPIOA->BRR = GPIO_Pin_12;
    } else {
      GPIOA->BSRR = GPIO_Pin_12;
    }

    if (end_of_release) {
      GPIOA->BRR = GPIO_Pin_11;
    } else {
      GPIOA->BSRR = GPIO_Pin_11;
    }
  }
  
 private:
  DISALLOW_COPY_AND_ASSIGN(GateOutput);
};

}  // namespace tides

#endif  // TIDES_DRIVERS_GATE_OUTPUT_H_
