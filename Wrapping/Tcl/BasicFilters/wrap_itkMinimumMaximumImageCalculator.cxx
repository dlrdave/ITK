/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    wrap_itkMinimumMaximumImageCalculator.cxx
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#include "itkMinimumMaximumImageCalculator.h"
#include "itkImage.h"

#ifdef CABLE_CONFIGURATION
#include "wrap_ITKBasicFilters.h"

#define ITK_WRAP_MMIC(x) \
  ITK_WRAP_IMAGE_CALCULATOR(MinimumMaximumImageCalculator, x) \

ITK_WRAP_CONFIG_GROUP(itkMinimumMaximumImageCalculator);
ITK_WRAP_DEFINE_IMAGE_TYPES();

ITK_WRAP_MMIC(F2);
ITK_WRAP_MMIC(F3);
ITK_WRAP_MMIC(US2);
ITK_WRAP_MMIC(US3);

#endif
