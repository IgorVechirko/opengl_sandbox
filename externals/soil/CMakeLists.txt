CMAKE_MINIMUM_REQUIRED( VERSION 3.0 )

project( SOIL VERSION 1.0 LANGUAGES C )

set( SOIL_DIR ${CMAKE_CURRENT_SOURCE_DIR} )

set( SOIL_INCLUDE_DIR ${SOIL_DIR}/include )
set( SOIL_INCLUDES include/SOIL/SOIL.h 
                   include/SOIL/image_dxt.h
                   include/SOIL/image_helper.h
                   include/SOIL/stb_image_aug.h
                   include/SOIL/stbi_dds_aug_c.h
                   include/SOIL/stbi_dds_aug.h
)

set( SOIL_SRC src/soil.c 
              src/stb_image_aug.c
              src/image_dxt.c
              src/image_helper.c
)


add_library( SOIL STATIC ${SOIL_INCLUDES} ${SOIL_SRC} )

target_include_directories( SOIL PUBLIC ${SOIL_INCLUDE_DIR} )
target_include_directories( SOIL PRIVATE ${SOIL_INCLUDE_DIR} )

if ( MSVC )
    target_compile_options( SOIL PRIVATE /W3 /wd4996 /wd4244 /wd4018 )
endif()