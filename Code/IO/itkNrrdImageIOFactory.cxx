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
#include "itkNrrdImageIOFactory.h"
#include "itkCreateObjectFunction.h"
#include "itkNrrdImageIO.h"
#include "itkVersion.h"

namespace itk
{
NrrdImageIOFactory::NrrdImageIOFactory()
{
  this->RegisterOverride( "itkImageIOBase",
                          "itkNrrdImageIO",
                          "Nrrd Image IO",
                          1,
                          CreateObjectFunction< NrrdImageIO >::New() );
}

NrrdImageIOFactory::~NrrdImageIOFactory()
{}

const char *
NrrdImageIOFactory::GetITKSourceVersion(void) const
{
  return ITK_SOURCE_VERSION;
}

const char *
NrrdImageIOFactory::GetDescription() const
{
  return "Nrrd ImageIO Factory, allows the loading of Nrrd images into insight";
}
} // end namespace itk
