# auto include feature must be disable because the class is not in the file
# with the same name
set(WRAPPER_AUTO_INCLUDE_HEADERS OFF)
WRAP_INCLUDE("vcl_complex.h")
WRAP_INCLUDE("vnl/vnl_diag_matrix.h")

WRAP_CLASS("vnl_diag_matrix")
  WRAP_TEMPLATE("${ITKM_D}" "${ITKT_D}")
  WRAP_TEMPLATE("_vcl_complex${ITKM_D}" "vcl_complex<${ITKT_D}>")
  WRAP_TEMPLATE("${ITKM_F}" "${ITKT_F}")
  WRAP_TEMPLATE("_vcl_complex${ITKM_F}" "vcl_complex<${ITKT_F}>")
  WRAP_TEMPLATE("${ITKM_SI}" "${ITKT_SI}")
  WRAP_TEMPLATE("${ITKM_LD}" "${ITKT_LD}")
END_WRAP_CLASS()
