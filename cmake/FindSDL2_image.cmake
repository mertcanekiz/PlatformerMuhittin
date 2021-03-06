SET(SDL2IMAGE_SEARCH_PATHS
  $ENV{PROGRAMFILES}/SDL2# WINDOWS
  "$ENV{PROGRAMFILES(X86)}/SDL2"# WINDOWS
  ~/Library/Frameworks
  /Library/Frameworks
  /usr/local
  /usr
  /sw # Fink
  /opt/local # DarwinPorts
  /opt/csw # Blastwave
  /opt
)

FIND_PATH(SDL2IMAGE_INCLUDE_DIR SDL_image.h
  HINTS
  $ENV{SDL2DIR}
  PATH_SUFFIXES include/SDL2 include
  PATHS ${SDL2IMAGE_SEARCH_PATHS}
)

FIND_LIBRARY(SDL2IMAGE_LIBRARY
  NAMES SDL2_image
  HINTS
  $ENV{SDL2DIR}
  PATH_SUFFIXES lib64 lib
  PATHS ${SDL2IMAGE_SEARCH_PATHS}
  DOC "SDL2 image Library Path"
)

INCLUDE(FindPackageHandleStandardArgs)

#message(${SDL2IMAGE_LIBRARY})

FIND_PACKAGE_HANDLE_STANDARD_ARGS(SDL2_image REQUIRED_VARS SDL2IMAGE_LIBRARY SDL2IMAGE_INCLUDE_DIR)

SET(SDL2IMAGE_FOUND "NO")
IF(SDL2IMAGE_LIBRARY AND SDL2IMAGE_INCLUDE_DIR)
  SET(SDL2IMAGE_FOUND "YES")
  MESSAGE(STATUS "Looking for SDL2_image - found")
ENDIF(SDL2IMAGE_LIBRARY AND SDL2IMAGE_INCLUDE_DIR)
