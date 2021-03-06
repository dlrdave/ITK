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
#ifndef __itkHistogramAlgorithmBase_txx
#define __itkHistogramAlgorithmBase_txx

#include "itkHistogramAlgorithmBase.h"

namespace itk
{
template< class TInputHistogram >
HistogramAlgorithmBase< TInputHistogram >
::HistogramAlgorithmBase()
{
  m_InputHistogram = 0;
}

template< class TInputHistogram >
void
HistogramAlgorithmBase< TInputHistogram >
::PrintSelf(std::ostream & os, Indent indent) const
{
  Superclass::PrintSelf(os, indent);

  os << indent << "Input Histogram: ";
  if ( m_InputHistogram.IsNotNull() )
    {
    os << m_InputHistogram << std::endl;
    }
  else
    {
    os << "not set." << std::endl;
    }
}
} // end of namespace itk

#endif
