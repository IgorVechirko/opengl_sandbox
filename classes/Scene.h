#ifndef Scene_H
#define Scene_H

#include "Node.h"

_VESTART

class GLRender;
class Scene : public Node
{


protected:

	Scene();

public:

	virtual ~Scene();

	CREATE_FUNC(Scene);

	void visit( GLRender* render );

};

_VEEND

#endif