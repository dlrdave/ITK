project(PathExamples)
include_regular_expression("^.*$")


add_executable(PolyLineParametricPath1 PolyLineParametricPath1.cxx )
target_link_libraries(PolyLineParametricPath1 ITKIO)

if(BUILD_TESTING)

add_test(PolyLineParametricPath1 ${CXX_TEST_PATH}/PolyLineParametricPath1
    ${ITK_SOURCE_DIR}/Examples/Data/VisibleWomanEyeSlice.png
)

endif(BUILD_TESTING)
