/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkMetaImageConverter.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __MetaImageConverter__h
#define __MetaImageConverter__h

#include "itkImageSpatialObject.h"
#include "metaImage.h"

namespace itk 
{

template <unsigned int NDimensions = 3, class PixelType = unsigned char>
class MetaImageConverter
{

public:

  MetaImageConverter();
  ~MetaImageConverter() {};

  typedef itk::ImageSpatialObject<NDimensions,PixelType > SpatialObjectType;
  typedef typename SpatialObjectType::TransformType TransformType;

  typedef typename SpatialObjectType::Pointer SpatialObjectPointer;

  SpatialObjectPointer ReadMeta(const char* name);

  bool WriteMeta(SpatialObjectType* spatialObject,const char* name);

  SpatialObjectPointer MetaImageToImageSpatialObject(MetaImage * image);
  MetaImage* ImageSpatialObjectToMetaImage(SpatialObjectType * spatialObject);

};

} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
  #include "itkMetaImageConverter.txx"
#endif


#endif
