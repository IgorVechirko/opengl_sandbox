#include "Application.h"

#include "TestScene.h"
#include "Director.h"

_USEVE

Application::Application()
{
}
Application::~Application()
{
}
Application* Application::getInstance()
{
	static Application app;
	return &app;
}
void Application::initView()
{
}
void Application::initContent()
{
	Director::getInstance()->setScene( TestScene::create() );
}
int Application::run()
{
	Director::getInstance()->init();

	initView();
	VIEW->setupWindowSize( (int)DEF_WIN_SIZE.x, (int)DEF_WIN_SIZE.y );
	INPUT->init();
	initContent();

	if ( !CUR_SCENE )
	{
		Director::getInstance()->setScene( Scene::create() );
	}

	

	Director::getInstance()->runMainLoop();

	return 0;
}