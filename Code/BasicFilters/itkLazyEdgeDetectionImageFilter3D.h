/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkLazyEdgeDetectionImageFilter3D.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __itkLazyEdgeDetectionImageFilter3D_h
#define __itkLazyEdgeDetectionImageFilter3D_h

#include "itkImageToImageFilter.h"

namespace itk
{
  
/** \class LazyEdgeDetectionImageFilter3D
 * \brief Implements a Reflection of an image along a selected direction.
 *
 * This class is parameterized over the type of the input image and
 * the type of the output image.  
 * 
 * \ingroup   IntensityImageFilters     Singlethreaded
 */
template <class TInputImage, class TOutputImage>
class ITK_EXPORT LazyEdgeDetectionImageFilter3D : public ImageToImageFilter<TInputImage,TOutputImage> 
{
public:
  /** Standard class typedefs. */
  typedef LazyEdgeDetectionImageFilter3D  Self;
  typedef ImageToImageFilter<TInputImage,TOutputImage>  Superclass;
  typedef SmartPointer<Self>   Pointer;
  typedef SmartPointer<const Self>  ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);
  
  /** Run-time type information (and related methods). */
  itkTypeMacro(LazyEdgeDetectionImageFilter3D, ImageToImageFilter);

  /** Some convenient typedefs. */
  typedef TInputImage InputImageType;
  typedef typename    InputImageType::Pointer    InputImagePointer;
  typedef typename    InputImageType::RegionType InputImageRegionType; 
  typedef typename    InputImageType::PixelType  InputImagePixelType; 
  typedef TOutputImage OutputImageType;
  typedef typename     OutputImageType::Pointer    OutputImagePointer;
  typedef typename     OutputImageType::RegionType OutputImageRegionType;
  typedef typename     OutputImageType::PixelType  OutputImagePixelType;

  /** Set the direction in which to reflect the data. */
  itkGetMacro( Direction, unsigned int );
  itkSetMacro( Direction, unsigned int );
  void SetEdgeDetectorThreshold(double d){edgeDetectorThreshold=d;};
  void SetEdgeDetectorOutsideValue(double d){edgeDetectorOutsideValue=d;};
  void SetEdgeDetectorVariance(double d){edgeDetectorVariance=d;};
  void SetEdgeDetectorMaximumError(double d){edgeDetectorMaximumError=d;};
protected:
  LazyEdgeDetectionImageFilter3D();
  virtual ~LazyEdgeDetectionImageFilter3D() {};
  void PrintSelf(std::ostream& os, Indent indent) const;
  /** This method implements the actual reflection of the image.
   *
   * \sa ImageToImageFilter::ThreadedGenerateData(),
   *     ImageToImageFilter::GenerateData()  */
  void GenerateData(void);

private:
  LazyEdgeDetectionImageFilter3D(const Self&); //purposely not implemented
  void operator=(const Self&); //purposely not implemented

  double edgeDetectorThreshold;
  double edgeDetectorOutsideValue;
  double edgeDetectorVariance;
  double edgeDetectorMaximumError;
  unsigned int m_Direction;

};

} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkLazyEdgeDetectionImageFilter3D.txx"
#endif

#endif
