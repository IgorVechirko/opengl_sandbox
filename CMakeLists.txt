
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
set( CubeMap ${GL_SANDBOX_SRC_DIR}/CubeMap.h ${GL_SANDBOX_SRC_DIR}/CubeMap.cpp )

set( ShaderProgram ${GL_SANDBOX_SRC_DIR}/ShaderProgram.h ${GL_SANDBOX_SRC_DIR}/ShaderProgram.cpp )
set( ShadersCache ${GL_SANDBOX_SRC_DIR}/ShadersCache.h ${GL_SANDBOX_SRC_DIR}/ShadersCache.cpp )

set( Camera ${GL_SANDBOX_SRC_DIR}/Camera.h ${GL_SANDBOX_SRC_DIR}/Camera.cpp )

set( Scene ${GL_SANDBOX_SRC_DIR}/Scene.h ${GL_SANDBOX_SRC_DIR}/Scene.cpp )

set( Node ${GL_SANDBOX_SRC_DIR}/Node.h ${GL_SANDBOX_SRC_DIR}/Node.cpp )
set( NodeExtensions ${GL_SANDBOX_SRC_DIR}/NodeExtensions.h ${GL_SANDBOX_SRC_DIR}/NodeExtensions.cpp )

set( AxisesOrigin ${GL_SANDBOX_SRC_DIR}/AxisesOrigin.h ${GL_SANDBOX_SRC_DIR}/AxisesOrigin.cpp )
set( ColorCube ${GL_SANDBOX_SRC_DIR}/ColorCube.h ${GL_SANDBOX_SRC_DIR}/ColorCube.cpp )
set( Cube ${GL_SANDBOX_SRC_DIR}/Cube.h ${GL_SANDBOX_SRC_DIR}/Cube.cpp )
set( ReflectionCube ${GL_SANDBOX_SRC_DIR}/ReflectionCube.h ${GL_SANDBOX_SRC_DIR}/ReflectionCube.cpp )
set( RefractionCube ${GL_SANDBOX_SRC_DIR}/RefractionCube.h ${GL_SANDBOX_SRC_DIR}/RefractionCube.cpp )

set( Line ${GL_SANDBOX_SRC_DIR}/Line.h ${GL_SANDBOX_SRC_DIR}/Line.cpp )

set( Model ${GL_SANDBOX_SRC_DIR}/Model.h ${GL_SANDBOX_SRC_DIR}/Model.cpp )
set( Sprite ${GL_SANDBOX_SRC_DIR}/Sprite.h ${GL_SANDBOX_SRC_DIR}/Sprite.cpp )
set( OutlineSprite ${GL_SANDBOX_SRC_DIR}/OutlineSprite.h ${GL_SANDBOX_SRC_DIR}/OutlineSprite.cpp )
set( Point ${GL_SANDBOX_SRC_DIR}/Point.h ${GL_SANDBOX_SRC_DIR}/Point.cpp )

set( TestScene ${GL_SANDBOX_SRC_DIR}/TestScene.h ${GL_SANDBOX_SRC_DIR}/TestScene.cpp )
set( Main ${GL_SANDBOX_SRC_DIR}/main.cpp )

set( DrawTypes ${GL_SANDBOX_SRC_DIR}/DrawTypes.h ${GL_SANDBOX_SRC_DIR}/DrawTypes.cpp )
set( MaterialsAndLightsTypes ${GL_SANDBOX_SRC_DIR}/MaterialsAndLightsTypes.h ${GL_SANDBOX_SRC_DIR}/MaterialsAndLightsTypes.cpp )

set( Creator ${GL_SANDBOX_SRC_DIR}/Creator.h ${GL_SANDBOX_SRC_DIR}/Creator.cpp )
set( Allocator ${GL_SANDBOX_SRC_DIR}/Allocator.h ${GL_SANDBOX_SRC_DIR}/Allocator.cpp )

set ( VertexArrayObject ${GL_SANDBOX_SRC_DIR}/VertexArrayObject.h ${GL_SANDBOX_SRC_DIR}/VertexArrayObject.cpp )
set ( CustomFrameBuffer ${GL_SANDBOX_SRC_DIR}/CustomFrameBuffer.h ${GL_SANDBOX_SRC_DIR}/CustomFrameBuffer.cpp )

set ( Skybox ${GL_SANDBOX_SRC_DIR}/Skybox.h ${GL_SANDBOX_SRC_DIR}/Skybox.cpp )


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
									${CustomFrameBuffer}
)

source_group( shaders FILES 
							${shaders}
							${ShadersCache}
							${ShaderProgram}
)

source_group( textures FILES 
							${TexturesCache}
							${Texture2D}
							${CubeMap}
)

source_group( camera FILES ${Camera} )

source_group( nodes FILES ${AxisesOrigin} 
						  ${ColorCube} 
						  ${Cube} 
						  ${Line} 
						  ${Sprite}
						  ${Model}
						  ${Point}
						  ${OutlineSprite}
						  ${ReflectionCube}
						  ${RefractionCube}
)
source_group( nodes\\base FILES 
								${Node} 
								${NodeExtensions} 
)
source_group( nodes\\scene FILES ${Scene} )
source_group( nodes\\scene\\light FILES 
						${DirectLightSource} 
						${Flashlight} 
						${PointLightSource}
)
source_group( nodes\\scene\\skybox FILES
	${Skybox}
)

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
				 ${Point}
				 ${OutlineSprite}
				 ${CustomFrameBuffer}
				 ${Skybox}
				 ${CubeMap}
				 ${ReflectionCube}
				 ${RefractionCube}
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





#functional tests project 

set( WORKING_TESTS_SRC_DIR ${GL_SANDBOX_DIR}/func_tests_src )

set( TestScene ${WORKING_TESTS_SRC_DIR}/TestScene.h ${WORKING_TESTS_SRC_DIR}/TestScene.cpp )
set( TestScopeDelegat ${WORKING_TESTS_SRC_DIR}/TestScopeDelegat.h ${WORKING_TESTS_SRC_DIR}/TestScopeDelegat.cpp )
set( func_tests_main ${WORKING_TESTS_SRC_DIR}/func_tests_main.cpp )
set( CameraMovementController ${WORKING_TESTS_SRC_DIR}/CameraMovementController.h ${WORKING_TESTS_SRC_DIR}/CameraMovementController.cpp )

set( FunctionalTestsDelegate ${WORKING_TESTS_SRC_DIR}/FunctionalTestsDelegate.h ${WORKING_TESTS_SRC_DIR}/FunctionalTestsDelegate.cpp )

set( ResMngTest ${WORKING_TESTS_SRC_DIR}/ResMngTest.h ${WORKING_TESTS_SRC_DIR}/ResMngTest.cpp )
set( DrawPrimitivesTest ${WORKING_TESTS_SRC_DIR}/DrawPrimitivesTest.h ${WORKING_TESTS_SRC_DIR}/DrawPrimitivesTest.cpp )
set( DrawSpriteTest ${WORKING_TESTS_SRC_DIR}/DrawSpriteTest.h ${WORKING_TESTS_SRC_DIR}/DrawSpriteTest.cpp )
set( MoveViewTest ${WORKING_TESTS_SRC_DIR}/MoveViewTest.h ${WORKING_TESTS_SRC_DIR}/MoveViewTest.cpp )
set( DirectLightTest ${WORKING_TESTS_SRC_DIR}/DirectLightTest.h ${WORKING_TESTS_SRC_DIR}/DirectLightTest.cpp )
set( PointLightTest ${WORKING_TESTS_SRC_DIR}/PointLightTest.h ${WORKING_TESTS_SRC_DIR}/PointLightTest.cpp )
set( FlashlightTest ${WORKING_TESTS_SRC_DIR}/FlashlightTest.h ${WORKING_TESTS_SRC_DIR}/FlashlightTest.cpp )
set( DrawModelTest ${WORKING_TESTS_SRC_DIR}/DrawModelTest.h ${WORKING_TESTS_SRC_DIR}/DrawModelTest.cpp )
set( DrawLightningModelTest ${WORKING_TESTS_SRC_DIR}/DrawLightningModelTest.h ${WORKING_TESTS_SRC_DIR}/DrawLightningModelTest.cpp )
set( DrawPointTest ${WORKING_TESTS_SRC_DIR}/DrawPointTest.h ${WORKING_TESTS_SRC_DIR}/DrawPointTest.cpp )
set( OutlineSpriteTest ${WORKING_TESTS_SRC_DIR}/OutlineSpriteTest.h ${WORKING_TESTS_SRC_DIR}/OutlineSpriteTest.cpp )
set( FrameBufferTest ${WORKING_TESTS_SRC_DIR}/FrameBufferTest.h ${WORKING_TESTS_SRC_DIR}/FrameBufferTest.cpp )
set( SkyboxTest ${WORKING_TESTS_SRC_DIR}/SkyboxTest.h ${WORKING_TESTS_SRC_DIR}/SkyboxTest.cpp )
set( ReflectionCubeTest ${WORKING_TESTS_SRC_DIR}/ReflectionCubeTest.h ${WORKING_TESTS_SRC_DIR}/ReflectionCubeTest.cpp )
set( RefractionCubeTest ${WORKING_TESTS_SRC_DIR}/RefractionCubeTest.h ${WORKING_TESTS_SRC_DIR}/RefractionCubeTest.cpp )

source_group( content FILES 
							${TestScene} 
							${TestScopeDelegat} 
							${CameraMovementController}
							${FunctionalTestsDelegate}
)
source_group( tests FILES
									${ResMngTest}
									${DrawPrimitivesTest}
									${DrawSpriteTest}
									${MoveViewTest}
									${DirectLightTest}
									${PointLightTest}
									${FlashlightTest}
									${DrawModelTest}
									${DrawLightningModelTest}
									${DrawPointTest}
									${OutlineSpriteTest}
									${FrameBufferTest}
									${SkyboxTest}
									${ReflectionCubeTest}
									${RefractionCubeTest}
)

source_group( woking_main ${func_tests_main} )

set( WOKING_TESTS_SRC 
					${TestScene} 
					${TestScopeDelegat} 
					${func_tests_main}
					${CameraMovementController}
					${FunctionalTestsDelegate}
					${ResMngTest}
					${DrawPrimitivesTest}
					${DrawSpriteTest}
					${MoveViewTest}
					${DirectLightTest}
					${PointLightTest}
					${FlashlightTest}
					${DrawModelTest}
					${DrawLightningModelTest}
					${DrawPointTest}
					${OutlineSpriteTest}
					${FrameBufferTest}
					${SkyboxTest}
					${ReflectionCubeTest}
					${RefractionCubeTest}
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
