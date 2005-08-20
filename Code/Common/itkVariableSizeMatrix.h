/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkVariableSizeMatrix.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __itkVariableSizeMatrix_h
#define __itkVariableSizeMatrix_h


#include "itkPoint.h"
#include "itkVector.h"
#include "itkCovariantVector.h"
#include "vnl/vnl_matrix_fixed.h"
#include "itkArray.h"


namespace itk
{

/** \class VariableSizeMatrix
 * \brief A templated class holding a M x N size Matrix
 * This class contains a vnl_matrix in order 
 * to make all the vnl mathematical methods available. This class is meant to be
 * used when the matrix length cannot be determined at compile time.
 *
 * \ingroup DataRepresentation
 */

template<class T >
class VariableSizeMatrix {
public:
  /** Standard class typedefs. */
  typedef VariableSizeMatrix  Self;

  /** Component value type */
  typedef T ValueType;
  typedef T ComponentType;

  /** Internal matrix type */
  typedef vnl_matrix<T>  InternalMatrixType;

  /** Matrix by Vector multiplication.  */
  Array<T> operator*(const Array<T> & vector) const;
 
  /** Matrix by Matrix multiplication.  */
  Self operator*(const Self & matrix) const;
 
  /** Matrix addition.  */
  Self operator+(const Self & matrix) const;
  const Self & operator+=(const Self & matrix );
 
  /** Matrix addition.  */
  Self operator-(const Self & matrix) const;
  const Self & operator-=(const Self & matrix );
 
  /** Matrix by vnl_matrix multiplication.  */
  vnl_matrix<T> operator*(const vnl_matrix<T> & matrix) const;

  /** Matrix by Matrix multiplication.  */
  void operator*=(const Self & matrix);
 
  /** Matrix by vnl_matrix multiplication.  */
  void operator*=(const vnl_matrix<T> & matrix);

  /** Matrix by vnl_vector multiplication.  */
  vnl_vector<T> operator*(const vnl_vector<T> & matrix) const;

  /** Matrix by scalar multiplication.  */
  void operator*=(const T & value)
    { m_Matrix *= value; }

  /** Matrix by scalar multiplication.  */
  Self operator*(const T & value)
    { Self result( *this );
      result *= value;
      return result; }

  /** Matrix by scalar division.  */
  void operator/=(const T & value)
    { m_Matrix /= value; }
  
  /** Matrix by scalar division.  */
  Self operator/(const T & value)
    { Self result( *this );
      result /= value;
      return result; }

   /** Return an element of the matrix. */
  inline T & operator()( unsigned int row, unsigned int col )
    { return m_Matrix(row,col); }

  /** Return an element of the matrix. */
  inline const T & operator()( unsigned int row, unsigned int col ) const
    { return m_Matrix(row,col); }

  /** Return a row of the matrix. */
  inline T * operator[]( unsigned int i )
    { return m_Matrix[i]; }

  /** Return a row of the matrix.*/
  inline const T * operator[]( unsigned int i ) const
    { return m_Matrix[i]; }

  /** Return the matrix. */
  inline InternalMatrixType & GetVnlMatrix( void )
    { return m_Matrix; }

  /** Return the matrix. */
  inline const InternalMatrixType & GetVnlMatrix( void ) const
    { return m_Matrix; }

  /** Set the matrix to identity. */
  inline void SetIdentity( void ) 
    { m_Matrix.set_identity(); }

  /** Fill the matrix with a value. */
  inline void Fill( const T & value ) 
    { m_Matrix.fill( value ); }

  /** Assignment operator. */
  inline const Self & operator=( const vnl_matrix<T> & matrix);

  /** Comparison operators. */
  inline bool operator==( const Self & matrix);
  inline bool operator!=( const Self & matrix);

  /** Assignment operator. */
  inline const Self & operator=( const Self & matrix);

  /** Return the inverse matrix. */
  inline vnl_matrix<T> GetInverse( void ) const;
 
  /** Return the transposed matrix. */
  inline vnl_matrix<T> GetTranspose( void ) const;

  /** Default constructor. */
  VariableSizeMatrix() : m_Matrix() {};

  /** Copy constructor. */
  VariableSizeMatrix(const Self & matrix) : m_Matrix( matrix.m_Matrix ) {};

  /** Return number of rows in the matrix */
  inline unsigned int Rows() { return m_Matrix.rows(); }
  
  /** Return number of columns in the matrix */
  inline unsigned int Cols() { return m_Matrix.cols(); }

  /** Set the matrix size. Old data lost. Returns true if size changed. */
  inline bool SetSize( unsigned int r, unsigned int c)
    {  return m_Matrix.set_size( r, c );  }
    
 
 
private:
  InternalMatrixType     m_Matrix;
  unsigned int m_Rows;   // Number of rows
  unsigned int m_Cols;   // Number of columns

};

template< class T >  
ITK_EXPORT std::ostream& operator<<(std::ostream& os, 
                                    const VariableSizeMatrix<T> & v) 
                            { os << v.GetVnlMatrix(); return os; }


  
} // end namespace itk
  

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkVariableSizeMatrix.txx"
#endif


#endif 
