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
#ifndef __itkNeighborhoodAlgorithm_h
#define __itkNeighborhoodAlgorithm_h

#include <list>
#include "itkImage.h"
#include "itkNeighborhoodOperator.h"
#include "itkNeighborhoodIterator.h"

namespace itk
{
namespace NeighborhoodAlgorithm
{
/** \class ImageBoundaryFacesCalculator
*
* Splitting the image into the necessary regions is an easy task when you use
* the ImageBoundaryFacesCalculator.  The face
* calculator is so named because it returns a list of the ``faces'' of the ND
* dataset.  Faces are those regions whose pixels all lie within a distance $d$
* from the boundary, where $d$ is the radius of the neighborhood stencil used
* for the numerical calculations. In other words, faces are those regions
* where a neighborhood iterator of radius $d$ will always overlap the boundary
* of the image. The face calculator also returns the single \emph{inner}
* region, in which out-of-bounds values are never required and bounds checking
* is not necessary.
*
* \image html FaceBoundaryCalculator.png "Example regions produced by the calculator."
*
* First we find center (non-boundary) region 0.
* then find the face on the lower side of the 0th dimension (Region 1).
* Next we find the face opposite to that face (Region 2).
* Then we find the face between region 1 and region 2 on
* the lower side of the 1th dimension.(region 3).
* Finally we find the face opposite to face 3 (region 4).
*
* \note The first region contained in faceList should be the
* non-boundary region, if there is one. The existence of a
* non-boundary region depends on the relative location of
* regionToProcess and bufferedRegion. The non-boundary regions (if
* any) are the remaining faces in faceList.
*
*/
template< class TImage >
struct ITK_EXPORT ImageBoundaryFacesCalculator {
  typedef typename NeighborhoodIterator< TImage >::RadiusType RadiusType;
  typedef typename TImage::RegionType                         RegionType;
  typedef typename TImage::IndexType                          IndexType;
  typedef typename IndexType::IndexValueType                  IndexValueType;
  typedef typename TImage::SizeType                           SizeType;
  typedef typename SizeType::SizeValueType                    SizeValueType;
  typedef std::list< RegionType >                             FaceListType;
  itkStaticConstMacro(ImageDimension, unsigned int, TImage::ImageDimension);

  FaceListType operator()(const TImage *, RegionType, RadiusType);
};

/** \class CalculateOutputWrapOffsetModifiers
 *
 * Helper class for setting up itkNeighborhoodIterator output
 * buffers. Calculates the necessary modifiers to synchronize input and output
 * iteration between images with equal RequestedRegion sizes but unequal
 * BufferedRegion sizes.
 */
template< class TImage >
struct ITK_EXPORT CalculateOutputWrapOffsetModifiers {
  typedef Offset< ::itk::GetImageDimension< TImage >::ImageDimension > OffsetType;
  OffsetType operator()(TImage *, TImage *) const;
};
} // end namespace NeighborhoodAlgorithm
} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkNeighborhoodAlgorithm.txx"
#endif

#endif
