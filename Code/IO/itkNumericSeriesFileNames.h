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
#ifndef __itkNumericSeriesFileNames_h
#define __itkNumericSeriesFileNames_h

#ifdef _MSC_VER
#pragma warning ( disable : 4786 )
#endif

#include "itkObject.h"
#include "itkObjectFactory.h"
#include "itkMacro.h"
#include <vector>

namespace itk
{
/** \class NumericSeriesFileNames
 * \brief Generate an ordered sequence of filenames.
 *
 * This class generate an ordered sequence of files whose filenames
 * contain a single unique, non-negative, integral value
 * (e.g. test.1.png, test2.png, foo.3, etc.).
 *
 * The file name is created from a sprintf-style series format which
 * should contain an integer format string like "%d". Bad formats will
 * cause the series reader to throw an exception.
 *
 * \ingroup IOFilters
 *
 */
class ITKIO_EXPORT NumericSeriesFileNames:public Object
{
public:
  /** Standard class typedefs. */
  typedef NumericSeriesFileNames Self;
  typedef Object                 Superclass;
  typedef SmartPointer< Self >   Pointer;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(NumericSeriesFileNames, Object);

  /* -------- Define the API for NumericSeriesFileNames ----------- */

  /** Use this method to set the starting index of the numeric series.
   * The default value is 1. */
  itkSetMacro(StartIndex, unsigned long);
  itkGetConstMacro(StartIndex, unsigned long);

  /** Set the end index of the numeric series. The default is 1. */
  itkSetMacro(EndIndex, unsigned long);
  itkGetConstMacro(EndIndex, unsigned long);

  /** Set the increment of the index of the numeric series. The
   * default value is 1.  */
  itkSetMacro(IncrementIndex, unsigned long);
  itkGetConstMacro(IncrementIndex, unsigned long);

  /** The format string used to generate the series. Different subclasses
   * require different characteristics of this string. For example, the
   * subclass NumericSeriesFileNames requires a "%d" or some integral
   * format specified to be embedded in the string. Default is "%d". */
  itkSetStringMacro(SeriesFormat);
  itkGetStringMacro(SeriesFormat);

  /** Returns a vector containing the series' file names. The file
    * names are ordered by Index. */
  const std::vector< std::string > & GetFileNames();

protected:
  NumericSeriesFileNames();
  ~NumericSeriesFileNames() {}
  void PrintSelf(std::ostream & os, Indent indent) const;

private:
  NumericSeriesFileNames(const Self &); //purposely not implemented
  void operator=(const Self &);         //purposely not implemented

  unsigned long m_StartIndex;
  unsigned long m_EndIndex;
  unsigned long m_IncrementIndex;

  /** A string for formatting the names of files in the series. */
  std::string m_SeriesFormat;

  std::vector< std::string > m_FileNames;
};
} //namespace ITK

#endif // __itkNumericSeriesFileNames_h
