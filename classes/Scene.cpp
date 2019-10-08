#include "Scene.h"

#include "Director.h"

_USEVE

Scene::Scene()
{
}
Scene::~Scene()
{
}
void Scene::visit( GLRender* render )
{
	Node::visit( render, Mat4(1.0f) );
}