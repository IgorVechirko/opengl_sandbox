
CMAKE_MINIMUM_REQUIRED( VERSION 3.8 )

project( opengl_sandbox VERSION 0.1.0.0	LANGUAGES CXX )

set( SANDBOX_DIR ${CMAKE_CURRENT_SOURCE_DIR} )



#externals
add_subdirectory( ${SANDBOX_DIR}/externals/glew/build/cmake EXCLUDE_FROM_ALL )
set( GLEW_INCLUDE_DIR ${SANDBOX_DIR}/externals/glew/include )

add_subdirectory( ${SANDBOX_DIR}/externals/glfw EXCLUDE_FROM_ALL )

add_subdirectory( ${SANDBOX_DIR}/externals/soil EXCLUDE_FROM_ALL )

add_subdirectory( ${SANDBOX_DIR}/externals/assimp EXCLUDE_FROM_ALL )

add_subdirectory( ${SANDBOX_DIR}/externals/glm )

add_subdirectory( ${SANDBOX_DIR}/externals/boost EXCLUDE_FROM_ALL )

set( RAPIDJSON_INCLUDE_DIR ${SANDBOX_DIR}/externals/rapidjson/include )



#sources
set( VECommon ${SANDBOX_DIR}/classes/VECommon.h ${SANDBOX_DIR}/classes/VECommon.cpp )

set( FileUtils ${SANDBOX_DIR}/classes/FileUtils.h ${SANDBOX_DIR}/classes/FileUtils.cpp )
set( ResourcesManager ${SANDBOX_DIR}/classes/ResourcesManager.h ${SANDBOX_DIR}/classes/ResourcesManager.cpp )

set( TimeScheduler ${SANDBOX_DIR}/classes/TimeScheduler.h ${SANDBOX_DIR}/classes/TimeScheduler.cpp )

set( AutoReleasePool ${SANDBOX_DIR}/classes/AutoReleasePool.h ${SANDBOX_DIR}/classes/AutoReleasePool.cpp )
set( Ref ${SANDBOX_DIR}/classes/Ref.h ${SANDBOX_DIR}/classes/Ref.cpp )

set( InputListener ${SANDBOX_DIR}/classes/InputListener.h )

set( DirectLightSource ${SANDBOX_DIR}/classes/DirectLightSource.h ${SANDBOX_DIR}/classes/DirectLightSource.cpp )
set( Flashlight ${SANDBOX_DIR}/classes/Flashlight.h ${SANDBOX_DIR}/classes/Flashlight.cpp )
set( PointLightSource ${SANDBOX_DIR}/classes/PointLightSource.h ${SANDBOX_DIR}/classes/PointLightSource.cpp )

set( GLRender ${SANDBOX_DIR}/classes/GLRender.h ${SANDBOX_DIR}/classes/GLRender.cpp )

set( GLContext ${SANDBOX_DIR}/classes/GLContext.h ${SANDBOX_DIR}/classes/GLContext.cpp )
set( OpenGL ${SANDBOX_DIR}/classes/OpenGL.h ${SANDBOX_DIR}/classes/OpenGL.cpp )


set( Texture2D ${SANDBOX_DIR}/classes/Texture2D.h ${SANDBOX_DIR}/classes/Texture2D.cpp )

set( ShaderProgram ${SANDBOX_DIR}/classes/ShaderProgram.h ${SANDBOX_DIR}/classes/ShaderProgram.cpp )

set( Camera ${SANDBOX_DIR}/classes/Camera.h ${SANDBOX_DIR}/classes/Camera.cpp )
set( CameraMovementController ${SANDBOX_DIR}/classes/CameraMovementController.h ${SANDBOX_DIR}/classes/CameraMovementController.cpp )

set( Scene ${SANDBOX_DIR}/classes/Scene.h ${SANDBOX_DIR}/classes/Scene.cpp )

set( Node ${SANDBOX_DIR}/classes/Node.h ${SANDBOX_DIR}/classes/Node.cpp )
set( NodeExtentions ${SANDBOX_DIR}/classes/NodeExtentions.h ${SANDBOX_DIR}/classes/NodeExtentions.cpp )

set( AxisesOrigin ${SANDBOX_DIR}/classes/AxisesOrigin.h ${SANDBOX_DIR}/classes/AxisesOrigin.cpp )
set( ColorCube ${SANDBOX_DIR}/classes/ColorCube.h ${SANDBOX_DIR}/classes/ColorCube.cpp )
set( Cube ${SANDBOX_DIR}/classes/Cube.h ${SANDBOX_DIR}/classes/Cube.cpp )
set( CubeVertices ${SANDBOX_DIR}/classes/CubeVertices.h ${SANDBOX_DIR}/classes/CubeVertices.cpp )
set( Line ${SANDBOX_DIR}/classes/Line.h ${SANDBOX_DIR}/classes/Line.cpp )
set( Mesh ${SANDBOX_DIR}/classes/Mesh.h ${SANDBOX_DIR}/classes/Mesh.cpp )
set( Model ${SANDBOX_DIR}/classes/Model.h ${SANDBOX_DIR}/classes/Model.cpp )
set( Sprite ${SANDBOX_DIR}/classes/Sprite.h ${SANDBOX_DIR}/classes/Sprite.cpp )

set( TestScene ${SANDBOX_DIR}/classes/TestScene.h ${SANDBOX_DIR}/classes/TestScene.cpp )
set( Main ${SANDBOX_DIR}/classes/main.cpp )

set( WorkingScope 
				  ${SANDBOX_DIR}/classes/WorkingScope.h
				  ${SANDBOX_DIR}/classes/WorkingScope.cpp
				  ${SANDBOX_DIR}/classes/WorkingScopeProvider.cpp
				  ${SANDBOX_DIR}/classes/WorkingScopeProvider.h )


source_group( common FILES ${VECommon} )

source_group( file_utils FILES ${FileUtils} 
						 	   ${ResourcesManager} )

source_group( scheduler FILES ${TimeScheduler} )

source_group( auto_release FILES ${AutoReleasePool} 
						   	     ${Ref} )

source_group( input FILES ${InputListener} )

source_group( gl FILES ${OpenGL} )
source_group( gl\\context FILES ${GLContext} )
source_group( gl\\render FILES ${GLRender} )

source_group( textures FILES ${Texture2D} )

source_group( shader FILES ${ShaderProgram} )

source_group( camera FILES ${Camera} 
					 	   ${CameraMovementController} 
)

source_group( nodes FILES ${AxisesOrigin} 
						  ${ColorCube} 
						  ${Cube} 
						  ${CubeVertices} 
						  ${Line} 
						  ${Mesh} 
						  ${Model} 
						  ${Sprite} 
)
source_group( nodes\\base FILES 
								${Node} 
								${NodeExtentions} 
)
source_group( nodes\\light FILES 
						${DirectLightSource} 
						${Flashlight} 
						${PointLightSource} 
)
source_group( nodes\\scene FILES ${Scene} )

source_group( content FILES ${TestScene} )

source_group( main FILES ${Main} )

source_group( working_scope FILES ${WorkingScope} )



set( SANDBOX_SRC ${VECommon}
				 ${FileUtils}
				 ${ResourcesManager}
				 ${TimeScheduler}
				 ${AutoReleasePool}
				 ${Ref}
				 ${InputListener}
				 ${DirectLightSource}
				 ${Flashlight}
				 ${PointLightSource}
				 ${GLRender}
				 ${GLContext}
				 ${OpenGL}
				 ${Texture2D}
				 ${ShaderProgram}
				 ${Camera}
				 ${CameraMovementController}
				 ${Scene}
				 ${Node}
				 ${NodeExtentions}
				 ${AxisesOrigin}
				 ${ColorCube}
				 ${Cube}
				 ${CubeVertices}
				 ${Line}
				 ${Mesh}
				 ${Model}
				 ${Sprite}
				 ${TestScene} 
				 ${Main}
				 ${WorkingScope}
)

#setup project
add_executable( opengl_sandbox ${SANDBOX_SRC} )

target_link_libraries( opengl_sandbox glew_s glfw SOIL glm assimp )

target_compile_definitions( opengl_sandbox PRIVATE BUILD )

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


#tests sources

set( unit_tests_main ${SANDBOX_DIR}/unit_tests_src/unit_tests_main.cpp )

set( RefTest ${SANDBOX_DIR}/unit_tests_src/RefTest.h ${SANDBOX_DIR}/unit_tests_src/RefTest.cpp )

set( TimeSchedulerTest ${SANDBOX_DIR}/unit_tests_src/TimeSchedulerTest.h ${SANDBOX_DIR}/unit_tests_src/TimeSchedulerTest.cpp )

source_group( unit_main FILES ${unit_tests_main} )

source_group( unit_tests\\ref FILES ${RefTest} )

source_group( unit_tests\\scheduler FILES ${TimeSchedulerTest} )




set( UNIT_TESTS_SRC 
					${unit_tests_main}
					${RefTest}
					${TimeSchedulerTest} )

#setup unit tests project
add_executable( unit_tests ${SANDBOX_SRC} ${UNIT_TESTS_SRC} )

target_link_libraries( unit_tests glew_s glfw SOIL glm assimp boost.test )

target_compile_definitions( unit_tests PRIVATE UNIT_TESTS )

include_directories( ${RAPIDJSON_INCLUDE_DIR}
					 ${GLEW_INCLUDE_DIR}
					 ${SANDBOX_DIR}/classes
)

if ( MSVC )
	set_target_properties(
		unit_tests PROPERTIES
		VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/resources"
	)

	target_compile_options( unit_tests PRIVATE /MP )
endif()