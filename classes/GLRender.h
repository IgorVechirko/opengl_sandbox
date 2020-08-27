#ifndef GLRender_H
#define GLRender_H

#include "WorkingScopeProvider.h"

namespace GLSandbox
{

	class Scene;
	class GLRender : public WorkingScopeProvider
	{

	public:

		GLRender( WorkingScope* scope );
		virtual ~GLRender();

		void init();

		void drawScene( Scene* scene );
	};

}

#endif