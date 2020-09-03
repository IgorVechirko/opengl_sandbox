#ifndef FunctionalTestsDelegate_H
#define FunctionalTestsDelegate_H

#include "ScopeDelegate.h"
#include "InputListener.h"
#include "Scene.h"

namespace FuncTests
{
	class FunctionalTestsDelegate
		: public GLSandbox::ScopeDelegate
		, public GLSandbox::InputListener
	{

		std::vector<std::function<GLSandbox::Scene*(void)>> _testsCreateFuncs;
		int _currentTest;


		virtual void init() override;

		void showNextTest();
		void showPrevTest();
		void showScene( std::function<GLSandbox::Scene*(void)>& createSceneFunc );

		virtual void onKeyPressed( int keyCode ) override;

		

	public:

		FunctionalTestsDelegate();
		virtual ~FunctionalTestsDelegate();

	};
}


#endif