/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkImageRegionIterator.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __itkImageRegionIterator_h
#define __itkImageRegionIterator_h

#include "itkImageRegionConstIterator.h"
#include "itkImageIteratorWithIndex.h"

namespace itk
{

/** \class ImageRegionIterator
 * \brief Multi-dimensional image iterator which walks a region.
 * 
 * ImageRegionIterator is a templated class to represent a
 * multi-dimensional iterator. ImageRegionIterator is templated over
 * the image type, and is constrained to walk only within the
 * specified region and along a line parallel to one of the coordinate
 * axes, "wrapping" to the next line as it reaches the boundary of the
 * image.  To walk the entire image, specify the region to
 * be \c image->GetLargestPossibleRegion().
 *
 * Most of the functionality is inherited from the ImageRegionConstIterator.
 * The current class only adds write access to image pixels.
 *
 * 
 * \sa ImageRegionConstIterator
 *
 * \ingroup ImageIterators
 *
 *
 */
template<typename TImage>
class ITK_EXPORT ImageRegionIterator : public ImageRegionConstIterator<TImage>
{
public:
  /** Standard class typedefs. */
  typedef ImageRegionIterator Self;
  typedef ImageRegionConstIterator<TImage>  Superclass;
  
   /** Types inherited from the Superclass */
  typedef typename Superclass::IndexType              IndexType;
  typedef typename Superclass::IndexValueType         IndexValueType;
  typedef typename Superclass::SizeType               SizeType;
  typedef typename Superclass::SizeValueType          SizeValueType;
  typedef typename Superclass::OffsetType             OffsetType;
  typedef typename Superclass::OffsetValueType        OffsetValueType;
  typedef typename Superclass::RegionType             RegionType;
  typedef typename Superclass::ImageType              ImageType;
  typedef typename Superclass::PixelContainer         PixelContainer;
  typedef typename Superclass::PixelContainerPointer  PixelContainerPointer;
  typedef typename Superclass::InternalPixelType      InternalPixelType;
  typedef typename Superclass::PixelType              PixelType;
  typedef typename Superclass::AccessorType           AccessorType;


  /** Default constructor. Needed since we provide a cast constructor. */
  ImageRegionIterator();
  
  /** Constructor establishes an iterator to walk a particular image and a
   * particular region of that image. */
  ImageRegionIterator(ImageType *ptr, const RegionType& region);

  /** Constructor that can be used to cast from an ImageIterator to an
   * ImageRegionIterator. Many routines return an ImageIterator but for a
   * particular task, you may want an ImageRegionIterator.  Rather than
   * provide overloaded APIs that return different types of Iterators, itk
   * returns ImageIterators and uses constructors to cast from an
   * ImageIterator to a ImageRegionIterator. */
  ImageRegionIterator( const ImageIteratorWithIndex<TImage> &it);
  
  /** Set the pixel value */
  void Set( const PixelType & value) const  
    { m_PixelAccessor.Set(*(const_cast<InternalPixelType *>(m_Buffer+m_Offset)),value); }

  /** Return a reference to the pixel 
   * This method will provide the fastest access to pixel
   * data, but it will NOT support ImageAdaptors. */
  PixelType & Value(void) 
    { return *(const_cast<InternalPixelType *>(m_Buffer+m_Offset)); }

   /** Return an iterator for the beginning of the region. "Begin"
   * is defined as the first pixel in the region.
   * \deprecated Use GoToBegin() instead */
  Self Begin(void) const;

   /** Return an iterator for the end of the region. "End" is defined
   * as one pixel past the last pixel of the region. 
   * \deprecated Use GoToEnd() instead */
  Self End(void) const;


protected:
  /** the construction from a const iterator is declared protected
      in order to enforce const correctness. */
  ImageRegionIterator( const ImageRegionConstIterator<TImage> &it);
  Self & operator=(const ImageRegionConstIterator<TImage> & it);
 

};

} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkImageRegionIterator.txx"
#endif

#endif 



