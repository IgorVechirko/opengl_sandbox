
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

set( RAPIDJSON_INCLUDE_DIR ${SANDBOX_DIR}/externals/rapidjson/include )



#sources
set( VECommon ${SANDBOX_DIR}/classes/VECommon.h ${SANDBOX_DIR}/classes/VECommon.cpp )

set( Application ${SANDBOX_DIR}/classes/Application.h ${SANDBOX_DIR}/classes/Application.cpp )

set( Director ${SANDBOX_DIR}/classes/Director.h ${SANDBOX_DIR}/classes/Director.cpp )

set( FileUtils ${SANDBOX_DIR}/classes/FileUtils.h ${SANDBOX_DIR}/classes/FileUtils.cpp )
set( ResourcesManager ${SANDBOX_DIR}/classes/ResourcesManager.h ${SANDBOX_DIR}/classes/ResourcesManager.cpp )

set( TimeScheduler ${SANDBOX_DIR}/classes/TimeScheduler.h ${SANDBOX_DIR}/classes/TimeScheduler.cpp )

set( AutoReleasePool ${SANDBOX_DIR}/classes/AutoReleasePool.h ${SANDBOX_DIR}/classes/AutoReleasePool.cpp )
set( Ref ${SANDBOX_DIR}/classes/Ref.h ${SANDBOX_DIR}/classes/Ref.cpp )

set( InputController ${SANDBOX_DIR}/classes/InputController.h ${SANDBOX_DIR}/classes/InputController.cpp )

set( DirectLightSource ${SANDBOX_DIR}/classes/DirectLightSource.h ${SANDBOX_DIR}/classes/DirectLightSource.cpp )
set( Flashlight ${SANDBOX_DIR}/classes/Flashlight.h ${SANDBOX_DIR}/classes/Flashlight.cpp )
set( PointLightSource ${SANDBOX_DIR}/classes/PointLightSource.h ${SANDBOX_DIR}/classes/PointLightSource.cpp )

set( GLRender ${SANDBOX_DIR}/classes/GLRender.h ${SANDBOX_DIR}/classes/GLRender.cpp )

set( GLView ${SANDBOX_DIR}/classes/GLView.h ${SANDBOX_DIR}/classes/GLView.cpp )

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
set( main ${SANDBOX_DIR}/classes/main.cpp )


source_group( common FILES ${VECommon} )
source_group( application FILES ${Application} )
source_group( director FILES ${Director} )
source_group( file_utils FILES ${FileUtils} 
						 	   ${ResourcesManager} )
source_group( scheduler FILES ${TimeScheduler} )
source_group( auto_release FILES ${AutoReleasePool} 
						   	     ${Ref} )
source_group( input FILES ${InputController} )
source_group( light FILES ${DirectLightSource} 
						  ${Flashlight} 
						  ${PointLightSource} )
source_group( render FILES ${GLRender} )
source_group( view FILES ${GLView} )
source_group( textures FILES ${Texture2D} )
source_group( shader FILES ${ShaderProgram} )
source_group( camera FILES ${Camera} 
					 	   ${CameraMovementController} )
source_group( scene FILES ${Scene} )
source_group( nodes\\base FILES ${Node} 
						 	   ${NodeExtentions} )
source_group( nodes FILES ${AxisesOrigin} 
						  ${ColorCube} 
						  ${Cube} 
						  ${CubeVertices} 
						  ${Line} 
						  ${Mesh} 
						  ${Model} 
						  ${Sprite} )

source_group( content FILES ${TestScene} ${main} )



set( SANDBOX_SRC ${VECommon}
				 ${Application}
				 ${Director}
				 ${FileUtils}
				 ${ResourcesManager}
				 ${TimeScheduler}
				 ${AutoReleasePool}
				 ${Ref}
				 ${InputController}
				 ${DirectLightSource}
				 ${Flashlight}
				 ${PointLightSource}
				 ${GLRender}
				 ${GLView}
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
				 ${main}
)

#setup project
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