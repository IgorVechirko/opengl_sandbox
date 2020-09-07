# OpenGL Sandbox
Simple project for try use OpenGL API functionality to take understanding about main work principles.

Using libraries:
1. For unifrom window creating and get input events using glfw library. 
2. For work wiht gl extentions using glew libraries
3. For render stuctures calculation using GLM library
4. For load textures using SOIL library
5. For load 3D models using assimp library

For easier way to create different render entity and make possibility do some trivial tasks faster and comfortable in project were add next classes:
* WorkingScope - class contain pointers to all main objects. Has interface for run main loop from external.
* Creator - class has uniform interface for create all kine of objects.
* Allocator - Creator class member. Provide memory allocation counting logic for detect memory leacks issues.
* GLContext - entity response for all interaction with created window and linked with window context.
* ResourcesManager - class allow access to resource path throw this resource unique ID, relation (ID:path) write in separate json config.
* AutoReleasePool - class for monitoring and deleting objects which was create with auto release functionality ( Ref object ).
* TimeScheduler - class allow organize work with time dependent callbecks.
* InputListener - class objects allow receive callbacks from observable object wich process input events. GLContext class processing input events.
* Scene - class is the main Node of scene graph. GLContext containing pointer to current render Scene. Scene contains camera and light sources ( direction, point light, flashlight ) objects

# Previews
Direction light
![DirectionLight](images/direction_light.png "Direction light sample")
Point lights
![PointLights](images/point_lights.png "Point lights sample")
Flashlight
![Flashlihgt](images/flashlight.png "Flashlight sample")
3D model loading ( no lighting logic, dispayed only diffus textures )
![3DModel](images/3d_model_no_lihgt.png "3D model sample")
