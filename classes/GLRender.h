#ifndef GLRender_H
#define GLRender_H

#include "VECommon.h"

_VESTART

class Camera;
class Node;
class GLRender
{

	std::vector<Node*> _nodes;

	bool _inited;

	GLFWwindow* _window;
	GLuint _windowWidth;
	GLuint _windowHeight;

	Camera* _camera;

	GLRender();

	void keysCallback( GLFWwindow* window, int key, int scancode, int action, int mode );

public:

	virtual ~GLRender();

	static GLRender* getInstance();

	void init();

	void addNodeForDraw( Node* node );
	void delNodeFromDraw( Node* node );

	GLuint getWindowWidth();
	GLuint getWindowHeight();

	void setCamera( Camera* camera );
	Camera* getCamera();

	void draw();
};

_VEEND

#endif