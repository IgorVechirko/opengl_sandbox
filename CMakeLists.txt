
CMAKE_MINIMUM_REQUIRED( VERSION 3.8 )

project( opengl_sandbox VERSION 0.1.0.0	LANGUAGES CXX )

set( SANDBOX_DIR ${CMAKE_CURRENT_SOURCE_DIR} )


add_subdirectory( ${SANDBOX_DIR}/externals/glew/build/cmake EXCLUDE_FROM_ALL )
set( GLEW_INCLUDE_DIR ${SANDBOX_DIR}/externals/glew/include )

add_subdirectory( ${SANDBOX_DIR}/externals/glfw EXCLUDE_FROM_ALL )

add_subdirectory( ${SANDBOX_DIR}/externals/soil EXCLUDE_FROM_ALL )

add_subdirectory( ${SANDBOX_DIR}/externals/assimp EXCLUDE_FROM_ALL )

add_subdirectory( ${SANDBOX_DIR}/externals/glm )

set( RAPIDJSON_INCLUDE_DIR ${SANDBOX_DIR}/externals/rapidjson/include )


set( SANDBOX_SRC ${SANDBOX_DIR}/classes/main.cpp
				 ${SANDBOX_DIR}/classes/Application.cpp
				 ${SANDBOX_DIR}/classes/AutoReleasePool.cpp
				 ${SANDBOX_DIR}/classes/AxisesOrigin.cpp
				 ${SANDBOX_DIR}/classes/Camera.cpp
				 ${SANDBOX_DIR}/classes/CameraMovementController.cpp
				 ${SANDBOX_DIR}/classes/ColorCube.cpp
				 ${SANDBOX_DIR}/classes/Cube.cpp
				 ${SANDBOX_DIR}/classes/CubeVertices.cpp
				 ${SANDBOX_DIR}/classes/DirectLightSource.cpp
				 ${SANDBOX_DIR}/classes/Director.cpp
				 ${SANDBOX_DIR}/classes/FileUtils.cpp
				 ${SANDBOX_DIR}/classes/Flashlight.cpp
				 ${SANDBOX_DIR}/classes/GLRender.cpp
				 ${SANDBOX_DIR}/classes/GLView.cpp
				 ${SANDBOX_DIR}/classes/InputController.cpp
				 ${SANDBOX_DIR}/classes/Line.cpp
				 ${SANDBOX_DIR}/classes/Mesh.cpp
				 ${SANDBOX_DIR}/classes/Model.cpp
				 ${SANDBOX_DIR}/classes/Node.cpp
				 ${SANDBOX_DIR}/classes/NodeExtentions.cpp
				 ${SANDBOX_DIR}/classes/PointLightSource.cpp
				 ${SANDBOX_DIR}/classes/Ref.cpp
				 ${SANDBOX_DIR}/classes/ResourcesManager.cpp
				 ${SANDBOX_DIR}/classes/Scene.cpp
				 ${SANDBOX_DIR}/classes/ShaderProgram.cpp
				 ${SANDBOX_DIR}/classes/Sprite.cpp
				 ${SANDBOX_DIR}/classes/TestScene.cpp
				 ${SANDBOX_DIR}/classes/Texture2D.cpp
				 ${SANDBOX_DIR}/classes/TimeScheduler.cpp
				 ${SANDBOX_DIR}/classes/VECommon.cpp
				 ${SANDBOX_DIR}/classes/Application.h
				 ${SANDBOX_DIR}/classes/AutoReleasePool.h
				 ${SANDBOX_DIR}/classes/AxisesOrigin.h
				 ${SANDBOX_DIR}/classes/Camera.h
				 ${SANDBOX_DIR}/classes/CameraMovementController.h
				 ${SANDBOX_DIR}/classes/ColorCube.h
				 ${SANDBOX_DIR}/classes/Cube.h
				 ${SANDBOX_DIR}/classes/CubeVertices.h
				 ${SANDBOX_DIR}/classes/DirectLightSource.h
				 ${SANDBOX_DIR}/classes/Director.h
				 ${SANDBOX_DIR}/classes/FileUtils.h
				 ${SANDBOX_DIR}/classes/Flashlight.h
				 ${SANDBOX_DIR}/classes/GLRender.h
				 ${SANDBOX_DIR}/classes/GLView.h
				 ${SANDBOX_DIR}/classes/InputController.h
				 ${SANDBOX_DIR}/classes/Line.h
				 ${SANDBOX_DIR}/classes/Mesh.h
				 ${SANDBOX_DIR}/classes/Model.h
				 ${SANDBOX_DIR}/classes/Node.h
				 ${SANDBOX_DIR}/classes/NodeExtentions.h
				 ${SANDBOX_DIR}/classes/PointLightSource.h
				 ${SANDBOX_DIR}/classes/Ref.h
				 ${SANDBOX_DIR}/classes/ResourcesManager.h
				 ${SANDBOX_DIR}/classes/Scene.h
				 ${SANDBOX_DIR}/classes/ShaderProgram.h
				 ${SANDBOX_DIR}/classes/Sprite.h
				 ${SANDBOX_DIR}/classes/TestScene.h
				 ${SANDBOX_DIR}/classes/Texture2D.h
				 ${SANDBOX_DIR}/classes/TimeScheduler.h
				 ${SANDBOX_DIR}/classes/VECommon.h
				 )


add_executable( opengl_sandbox ${SANDBOX_SRC} )

target_link_libraries( opengl_sandbox glew_s glfw SOIL glm assimp )

include_directories( ${RAPIDJSON_INCLUDE_DIR}
					 ${GLEW_INCLUDE_DIR}
					 )

if ( MSVC )
	set_target_properties(
		opengl_sandbox PROPERTIES
		VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/resources"
		)

    target_compile_options( opengl_sandbox PRIVATE /MP )
endif()