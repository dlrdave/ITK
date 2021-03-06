# vxl/config/cmake/VXLStandardOptions.cmake
#
# This CMake module is included by vxl/CMakeLists.txt.  It adds
# several vxl-standard testing and build options to the project:
#
#  BUILD_SHARED_LIBS
#  BUILD_TESTING
#  BUILD_EXAMPLES
#  WARN_DEPRECATED
#  WARN_DEPRECATED_ONCE
#  WARN_DEPRECATED_ABORT
#
# These options may be introduced into client projects with this line:
#
#  INCLUDE(${VXL_CMAKE_DIR}/VXLStandardOptions.cmake)
#
# This module may be automatically included by UseVXL.cmake.
# See vxl/config/cmake/UseVXL.cmake for details.
#

# Everything here should be valid for both the vxl source and for
# client projects.

INCLUDE( ${CMAKE_ROOT}/Modules/Dart.cmake )

IF( WIN32 )
  OPTION( BUILD_SHARED_LIBS "Should shared libraries be the default?" NO )
ELSE( WIN32 )
  OPTION( BUILD_SHARED_LIBS "Should shared libraries be the default?" NO )
ENDIF( WIN32 )

SET( SOLARIS 0 )
IF( CMAKE_SYSTEM MATCHES "SunOS.*" )
  SET( SOLARIS 1 )
ENDIF( CMAKE_SYSTEM MATCHES "SunOS.*" )

# if this is a dashboard build
IF( DART_ROOT )
  ADD_DEFINITIONS( -DDART_BUILD )
ENDIF( DART_ROOT)

# Some people may want to build the test cases even though they aren't
# using Dart.
IF( NOT DART_ROOT )
  IF( WIN32 )
    OPTION( BUILD_TESTING "Should the tests be built?" NO )
  ELSE( WIN32 )
    OPTION( BUILD_TESTING "Should the tests be built?" YES )
  ENDIF( WIN32 )

  IF( BUILD_TESTING )
    ENABLE_TESTING()
  ENDIF( BUILD_TESTING )
ENDIF( NOT DART_ROOT )
OPTION( BUILD_TESTING "Should the tests be built?" YES )

# By default, build examples when building tests.
OPTION( BUILD_EXAMPLES "Should the examples be built?" ${BUILD_TESTING} )

OPTION( WARN_DEPRECATED "Enable runtime warnings for deprecated functions?" YES )
OPTION( WARN_DEPRECATED_ONCE "Only warn once per function (if runtime warnings are enabled)?" YES )
OPTION( WARN_DEPRECATED_ABORT "Abort on executing a deprecated function (if runtime warnings are enabled)?" NO )

MARK_AS_ADVANCED( WARN_DEPRECATED WARN_DEPRECATED_ONCE WARN_DEPRECATED_ABORT )

IF(WARN_DEPRECATED)
  ADD_DEFINITIONS( -DVXL_WARN_DEPRECATED )
  IF(WARN_DEPRECATED_ONCE)
    ADD_DEFINITIONS( -DVXL_WARN_DEPRECATED_ONCE )
  ENDIF(WARN_DEPRECATED_ONCE)
  IF(WARN_DEPRECATED_ABORT)
    ADD_DEFINITIONS( -DVXL_WARN_DEPRECATED_ABORT )
  ENDIF(WARN_DEPRECATED_ABORT)
ENDIF(WARN_DEPRECATED)



IF (VCL_HAS_LFS OR WIN32)
  OPTION( VXL_USE_LFS "Should VXL use Large File Support?" NO)
  MARK_AS_ADVANCED( VXL_USE_LFS )
ENDIF (VCL_HAS_LFS OR WIN32)

IF(VXL_USE_LFS)
  IF(WIN32)
    # TODO: MS Version Support
    #  MESSAGE( SEND_ERROR "Sorry - Large File Support is not quite working on Win32 yet. Turning VXL_USE_LFS off")
    #  SET(VXL_USE_LFS "NO" CACHE BOOL "Should VXL use Large File Support?" FORCE)
  ELSE(WIN32)
    IF (VCL_HAS_LFS)
      ADD_DEFINITIONS( -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE)
    ELSE (VCL_HAS_LFS)
      MESSAGE( SEND_ERROR "This platform does not have Large File Support - turning VXL_USE_LFS off")
      SET(VXL_USE_LFS "NO" CACHE BOOL "Should VXL use Large File Support?" FORCE)
    ENDIF (VCL_HAS_LFS)
  ENDIF(WIN32)
ENDIF(VXL_USE_LFS)

