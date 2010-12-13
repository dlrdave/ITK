/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifdef _WIN64
#include <vnl/vnl_matrix.txx>

#ifdef _WIN64
VCL_DEFINE_SPECIALIZATION
class vnl_numeric_traits<long long>
{
 public:
  //: Additive identity
  static const long long zero VCL_STATIC_CONST_INIT_INT_DECL(0);
  //: Multiplicative identity
  static const long long one VCL_STATIC_CONST_INIT_INT_DECL(1);
  //: Maximum value which this type can assume
  static const long long maxval; // = 0x7fffffff;
  //: Return value of abs()
  typedef unsigned long long abs_t;
  //: Name of a type twice as long as this one for accumulators and products.
  typedef long long double_t;
  //: Name of type which results from multiplying this type with a double
  typedef double real_t;
};

#if !VCL_CANNOT_SPECIALIZE_CV
VCL_DEFINE_SPECIALIZATION
class vnl_numeric_traits<long long const> : public vnl_numeric_traits<long long> {};
#endif

#endif   // _WIN64

VNL_MATRIX_INSTANTIATE(long long);
#endif
