/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    wrap_itkDenseFiniteDifferenceImageFilter.cxx
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "itkImage.h"
#include "itkDenseFiniteDifferenceImageFilter.h"

#ifdef CABLE_CONFIGURATION
#include "itkCSwigImages.h"
#include "itkCSwigMacros.h"

namespace _cable_
{
  const char* const group = 
  ITK_WRAP_GROUP(itkDenseFiniteDifferenceImageFilter);
  namespace wrappers
  {
    ITK_WRAP_OBJECT2(DenseFiniteDifferenceImageFilter, image::F2, image::F2,
                       itkDenseFiniteDifferenceImageFilterF2F2);
    ITK_WRAP_OBJECT2(DenseFiniteDifferenceImageFilter, image::US2,image::F2,
                       itkDenseFiniteDifferenceImageFilterUS2F2);
    ITK_WRAP_OBJECT2(DenseFiniteDifferenceImageFilter, image::F3, image::F3,
                       itkDenseFiniteDifferenceImageFilterF3F3);
    ITK_WRAP_OBJECT2(DenseFiniteDifferenceImageFilter, image::US3, image::F3,
                       itkDenseFiniteDifferenceImageFilterUS3F3);
  }
}

#endif
