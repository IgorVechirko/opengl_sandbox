
CMAKE_MINIMUM_REQUIRED( VERSION 3.8 )

project( opengl_sandbox VERSION 0.1.0.0	LANGUAGES CXX )

set( GL_SANDBOX_DIR ${CMAKE_CURRENT_SOURCE_DIR} )



#externals
add_subdirectory( ${GL_SANDBOX_DIR}/externals/glew/build/cmake EXCLUDE_FROM_ALL )
set( GLEW_INCLUDE_DIR ${GL_SANDBOX_DIR}/externals/glew/include )

add_subdirectory( ${GL_SANDBOX_DIR}/externals/glfw EXCLUDE_FROM_ALL )

add_subdirectory( ${GL_SANDBOX_DIR}/externals/soil EXCLUDE_FROM_ALL )

add_subdirectory( ${GL_SANDBOX_DIR}/externals/assimp EXCLUDE_FROM_ALL )

add_subdirectory( ${GL_SANDBOX_DIR}/externals/glm )

set( RAPIDJSON_INCLUDE_DIR ${GL_SANDBOX_DIR}/externals/rapidjson/include )



#sources
set( GL_SANDBOX_SRC_DIR ${GL_SANDBOX_DIR}/classes )

set( Common ${GL_SANDBOX_SRC_DIR}/Common.h ${GL_SANDBOX_SRC_DIR}/Common.cpp )

set( FileUtils ${GL_SANDBOX_SRC_DIR}/FileUtils.h ${GL_SANDBOX_SRC_DIR}/FileUtils.cpp )
set( ResourcesManager ${GL_SANDBOX_SRC_DIR}/ResourcesManager.h ${GL_SANDBOX_SRC_DIR}/ResourcesManager.cpp )

set( TimeScheduler ${GL_SANDBOX_SRC_DIR}/TimeScheduler.h ${GL_SANDBOX_SRC_DIR}/TimeScheduler.cpp )

set( AutoReleasePool ${GL_SANDBOX_SRC_DIR}/AutoReleasePool.h ${GL_SANDBOX_SRC_DIR}/AutoReleasePool.cpp )
set( Ref ${GL_SANDBOX_SRC_DIR}/Ref.h ${GL_SANDBOX_SRC_DIR}/Ref.cpp )

set( InputListener ${GL_SANDBOX_SRC_DIR}/InputListener.h )

set( DirectLightSource ${GL_SANDBOX_SRC_DIR}/DirectLightSource.h ${GL_SANDBOX_SRC_DIR}/DirectLightSource.cpp )
set( Flashlight ${GL_SANDBOX_SRC_DIR}/Flashlight.h ${GL_SANDBOX_SRC_DIR}/Flashlight.cpp )
set( PointLightSource ${GL_SANDBOX_SRC_DIR}/PointLightSource.h ${GL_SANDBOX_SRC_DIR}/PointLightSource.cpp )

set( GLRender ${GL_SANDBOX_SRC_DIR}/GLRender.h ${GL_SANDBOX_SRC_DIR}/GLRender.cpp )

set( GLContext ${GL_SANDBOX_SRC_DIR}/GLContext.h ${GL_SANDBOX_SRC_DIR}/GLContext.cpp )
set( OpenGL ${GL_SANDBOX_SRC_DIR}/OpenGL.h ${GL_SANDBOX_SRC_DIR}/OpenGL.cpp )


set( Texture2D ${GL_SANDBOX_SRC_DIR}/Texture2D.h ${GL_SANDBOX_SRC_DIR}/Texture2D.cpp )
set( TexturesCache ${GL_SANDBOX_SRC_DIR}/TexturesCache.h ${GL_SANDBOX_SRC_DIR}/TexturesCache.cpp )

set( ShaderProgram ${GL_SANDBOX_SRC_DIR}/ShaderProgram.h ${GL_SANDBOX_SRC_DIR}/ShaderProgram.cpp )
set( ShadersCache ${GL_SANDBOX_SRC_DIR}/ShadersCache.h ${GL_SANDBOX_SRC_DIR}/ShadersCache.cpp )

set( Camera ${GL_SANDBOX_SRC_DIR}/Camera.h ${GL_SANDBOX_SRC_DIR}/Camera.cpp )

set( Scene ${GL_SANDBOX_SRC_DIR}/Scene.h ${GL_SANDBOX_SRC_DIR}/Scene.cpp )

set( Node ${GL_SANDBOX_SRC_DIR}/Node.h ${GL_SANDBOX_SRC_DIR}/Node.cpp )
set( NodeExtensions ${GL_SANDBOX_SRC_DIR}/NodeExtensions.h ${GL_SANDBOX_SRC_DIR}/NodeExtensions.cpp )

set( AxisesOrigin ${GL_SANDBOX_SRC_DIR}/AxisesOrigin.h ${GL_SANDBOX_SRC_DIR}/AxisesOrigin.cpp )
set( ColorCube ${GL_SANDBOX_SRC_DIR}/ColorCube.h ${GL_SANDBOX_SRC_DIR}/ColorCube.cpp )
set( Cube ${GL_SANDBOX_SRC_DIR}/Cube.h ${GL_SANDBOX_SRC_DIR}/Cube.cpp )

set( Line ${GL_SANDBOX_SRC_DIR}/Line.h ${GL_SANDBOX_SRC_DIR}/Line.cpp )

set( Model ${GL_SANDBOX_SRC_DIR}/Model.h ${GL_SANDBOX_SRC_DIR}/Model.cpp )
set( Sprite ${GL_SANDBOX_SRC_DIR}/Sprite.h ${GL_SANDBOX_SRC_DIR}/Sprite.cpp )

set( TestScene ${GL_SANDBOX_SRC_DIR}/TestScene.h ${GL_SANDBOX_SRC_DIR}/TestScene.cpp )
set( Main ${GL_SANDBOX_SRC_DIR}/main.cpp )

set( DrawTypes ${GL_SANDBOX_SRC_DIR}/DrawTypes.h ${GL_SANDBOX_SRC_DIR}/DrawTypes.cpp )
set( MaterialsAndLightsTypes ${GL_SANDBOX_SRC_DIR}/MaterialsAndLightsTypes.h ${GL_SANDBOX_SRC_DIR}/MaterialsAndLightsTypes.cpp )

set( Creator ${GL_SANDBOX_SRC_DIR}/Creator.h ${GL_SANDBOX_SRC_DIR}/Creator.cpp )
set( Allocator ${GL_SANDBOX_SRC_DIR}/Allocator.h ${GL_SANDBOX_SRC_DIR}/Allocator.cpp )

set ( VertexArrayObject ${GL_SANDBOX_SRC_DIR}/VertexArrayObject.h ${GL_SANDBOX_SRC_DIR}/VertexArrayObject.cpp )


set( WorkingScope 
				  ${GL_SANDBOX_SRC_DIR}/WorkingScope.h
				  ${GL_SANDBOX_SRC_DIR}/WorkingScope.cpp
				  ${GL_SANDBOX_SRC_DIR}/WorkingScopeProvider.cpp
				  ${GL_SANDBOX_SRC_DIR}/WorkingScopeProvider.h
				  ${GL_SANDBOX_SRC_DIR}/ScopeDelegate.h
)

set( shaders ${GL_SANDBOX_SRC_DIR}/shaders.h ${GL_SANDBOX_SRC_DIR}/shaders.cpp )




source_group( common FILES ${Common} )

source_group( file_utils FILES ${FileUtils} 
						 	   ${ResourcesManager} )

source_group( scheduler FILES ${TimeScheduler} )

source_group( creator FILES ${Creator} )

source_group( memmory_managment\\auto_release FILES 
													${AutoReleasePool} 
						   							${Ref}
)
source_group( memmory_managment\\allocation FILES ${Allocator} )

source_group( input FILES ${InputListener} )

source_group( gl FILES 
						${OpenGL}
)
source_group( gl\\context FILES ${GLContext} )
source_group( gl\\render FILES ${GLRender} )
source_group( gl\\components FILES 
									${VertexArrayObject}
)

source_group( shaders FILES 
							${shaders}
							${ShadersCache}
							${ShaderProgram}
)

source_group( textures FILES 
							${TexturesCache}
							${Texture2D} 
)

source_group( camera FILES ${Camera} )

source_group( nodes FILES ${AxisesOrigin} 
						  ${ColorCube} 
						  ${Cube} 
						  ${Line} 
						  ${Sprite}
						  ${Model}
)
source_group( nodes\\base FILES 
								${Node} 
								${NodeExtensions} 
)
source_group( nodes\\light FILES 
						${DirectLightSource} 
						${Flashlight} 
						${PointLightSource}
)
source_group( nodes\\scene FILES ${Scene} )

source_group( working_scope FILES ${WorkingScope} )

source_group( data_structures FILES 
									${MaterialsAndLightsTypes}
									${DrawTypes}
)


set( SANDBOX_SRC ${Common}
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
				 ${Scene}
				 ${Node}
				 ${NodeExtensions}
				 ${AxisesOrigin}
				 ${ColorCube}
				 ${Cube}
				 ${Line}
				 ${Model}
				 ${Sprite}
				 ${WorkingScope}
				 ${MaterialsAndLightsTypes}
				 ${DrawTypes}
				 ${Creator}
				 ${Allocator}
				 ${VertexArrayObject}
				 ${shaders}
				 ${TexturesCache}
				 ${ShadersCache}
)

#setup project
add_library( gl_sandbox STATIC ${SANDBOX_SRC} )

target_link_libraries( gl_sandbox glew_s glfw SOIL glm assimp )

target_compile_definitions( gl_sandbox PRIVATE BUILD )

target_include_directories( gl_sandbox PUBLIC ${GL_SANDBOX_SRC_DIR} )
target_include_directories( gl_sandbox PUBLIC 
											${RAPIDJSON_INCLUDE_DIR}
											${GLEW_INCLUDE_DIR} 
)

if ( MSVC )
    target_compile_options( gl_sandbox PRIVATE /MP )

	target_compile_options( gl_sandbox PRIVATE /wd4018)

endif()





#wokign tests project 

set( WORKING_TESTS_SRC_DIR ${GL_SANDBOX_DIR}/func_tests_src )

set( TestScene ${WORKING_TESTS_SRC_DIR}/TestScene.h ${WORKING_TESTS_SRC_DIR}/TestScene.cpp )
set( TestScopeDelegat ${WORKING_TESTS_SRC_DIR}/TestScopeDelegat.h ${WORKING_TESTS_SRC_DIR}/TestScopeDelegat.cpp )
set( func_tests_main ${WORKING_TESTS_SRC_DIR}/func_tests_main.cpp )
set( CameraMovementController ${WORKING_TESTS_SRC_DIR}/CameraMovementController.h ${WORKING_TESTS_SRC_DIR}/CameraMovementController.cpp )

set( FunctionalTestsDelegate ${WORKING_TESTS_SRC_DIR}/FunctionalTestsDelegate.h ${WORKING_TESTS_SRC_DIR}/FunctionalTestsDelegate.cpp )

source_group( content FILES 
							${TestScene} 
							${TestScopeDelegat} 
							${CameraMovementController}
							${FunctionalTestsDelegate}
)
source_group( content\\tests FILES
)

source_group( woking_main ${func_tests_main} )

set( WOKING_TESTS_SRC 
					${TestScene} 
					${TestScopeDelegat} 
					${func_tests_main}
					${CameraMovementController}
					${FunctionalTestsDelegate}
)


add_executable( func_tests ${WOKING_TESTS_SRC} )

target_link_libraries( func_tests gl_sandbox )

target_include_directories( func_tests PRIVATE ${WORKING_TESTS_SRC_DIR} )

if ( MSVC )
	set_target_properties(
		func_tests PROPERTIES
		VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/resources"
	)

    target_compile_options( func_tests PRIVATE /MP )
endif()






#tests sources

add_subdirectory( ${GL_SANDBOX_DIR}/externals/boost EXCLUDE_FROM_ALL )


set( UNIT_TESTS_SRC_DIR ${GL_SANDBOX_DIR}/unit_tests_src )
set( unit_tests_main ${UNIT_TESTS_SRC_DIR}/unit_tests_main.cpp )
set( RefTest ${UNIT_TESTS_SRC_DIR}/RefTest.h ${UNIT_TESTS_SRC_DIR}/RefTest.cpp )
set( TimeSchedulerTest ${UNIT_TESTS_SRC_DIR}/TimeSchedulerTest.h ${UNIT_TESTS_SRC_DIR}/TimeSchedulerTest.cpp )

source_group( unit_main FILES ${unit_tests_main} )

source_group( unit_tests\\ref FILES ${RefTest} )

source_group( unit_tests\\scheduler FILES ${TimeSchedulerTest} )


set( UNIT_TESTS_SRC 
					${unit_tests_main}
					${RefTest}
					${TimeSchedulerTest} )

#setup unit tests project
add_executable( unit_tests ${UNIT_TESTS_SRC} )

target_link_libraries( unit_tests gl_sandbox boost.test )

target_compile_definitions( unit_tests PRIVATE UNIT_TESTS )

target_include_directories( unit_tests PRIVATE ${UNIT_TESTS_SRC_DIR} )
#include_directories( ${GL_SANDBOX_SRC_DIR} )

if ( MSVC )
	target_compile_options( unit_tests PRIVATE /MP )
endif()
