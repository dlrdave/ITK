/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkCurvesLevelSetFunction.txx
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __itkCurvesLevelSetFunction_txx_
#define __itkCurvesLevelSetFunction_txx_

#include "itkCurvesLevelSetFunction.h"
#include "itkImageRegionIterator.h"
#include "itkGradientRecursiveGaussianImageFilter.h"
#include "vnl/algo/vnl_symmetric_eigensystem.h"
#include "vnl/vnl_matrix_fixed.h"

namespace itk {

template< class TImageType, class TFeatureImageType>
void 
CurvesLevelSetFunction< TImageType,TFeatureImageType>
::Initialize(const RadiusType &r)
{

  Superclass::Initialize(r);
    
  this->SetAdvectionWeight( NumericTraits<ScalarValueType>::One );
  this->SetPropagationWeight( NumericTraits<ScalarValueType>::One );
  this->SetCurvatureWeight( NumericTraits<ScalarValueType>::One );

}

template <class TImageType, class TFeatureImageType>
void CurvesLevelSetFunction<TImageType, TFeatureImageType>
::CalculateSpeedImage()
{
  /* copy the feature image into the speed image */
  ImageRegionConstIterator<FeatureImageType>
    fit(this->GetFeatureImage(), this->GetFeatureImage()->GetRequestedRegion());
  ImageRegionIterator<ImageType>
    sit(this->GetSpeedImage(), this->GetFeatureImage()->GetRequestedRegion());

  for ( fit.GoToBegin(), sit.GoToBegin(); ! fit.IsAtEnd(); ++sit, ++fit)
    {
    sit.Set( static_cast<ScalarValueType>( fit.Get() ) );
    }
}


template <class TImageType, class TFeatureImageType>
void CurvesLevelSetFunction<TImageType, TFeatureImageType>
::CalculateAdvectionImage()
{
  /* compoute the gradient of the feature image. */
  typedef GradientRecursiveGaussianImageFilter<FeatureImageType,VectorImageType>
    DerivativeFilterType;

  typename DerivativeFilterType::Pointer derivative = DerivativeFilterType::New();
  derivative->SetInput( this->GetFeatureImage() );
  derivative->SetSigma( m_DerivativeSigma );
  derivative->Update();
  
  /* copy negative gradient into the advection image. */
  ImageRegionIterator<VectorImageType>
    dit( derivative->GetOutput(), this->GetFeatureImage()->GetRequestedRegion() );
  ImageRegionIterator<VectorImageType>
    ait( this->GetAdvectionImage(), this->GetFeatureImage()->GetRequestedRegion() );

  for( dit.GoToBegin(), ait.GoToBegin(); !dit.IsAtEnd(); ++dit, ++ait )
    {
    typename VectorImageType::PixelType v = dit.Get();
    for ( unsigned int j = 0; j < ImageDimension; j++ )
      {
      v[j] *= -1.0L;
      }
    ait.Set( v);
    }
}

} // end namespace itk


#endif
