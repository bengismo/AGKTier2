#ifndef __REED_SOLOMON_DECODER_H__
#define __REED_SOLOMON_DECODER_H__

/*
 *  ReedSolomonDecoder.h
 *  zxing
 *
 *  Copyright 2010 ZXing authors All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <memory>
#include <vector>
#include <common/Counted.h>
#include <common/Array.h>

namespace zxing {
class GF256;
class GF256Poly;

class ReedSolomonDecoder {
private:
  GF256 &field;
public:
  ReedSolomonDecoder(GF256 &fld);
  ~ReedSolomonDecoder();
  void decode(ArrayRef<int> received, int twoS);
private:
  std::vector<Ref<GF256Poly> > runEuclideanAlgorithm(Ref<GF256Poly> a, Ref<GF256Poly> b, int R);
  ArrayRef<int> findErrorLocations(Ref<GF256Poly> errorLocator);
  ArrayRef<int> findErrorMagnitudes(Ref<GF256Poly> errorEvaluator, ArrayRef<int> errorLocations, bool dataMatrix);
};
}

#endif // __REED_SOLOMON_DECODER_H__
