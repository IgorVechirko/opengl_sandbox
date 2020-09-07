#include "DrawModelTest.h"

#include "Model.h"
#include "ResourcesManager.h"
#include "ShadersCache.h"

using namespace GLSandbox;

namespace FuncTests
{
	DrawModelTest::DrawModelTest()
	{
	}
	DrawModelTest::~DrawModelTest()
	{
	}
	bool DrawModelTest::onInit()
	{
		Scene::onInit();
		setName( "DrawModelTest" );
		Console::log( getName(), ": test scene run. Please use a,w,s,d,r,f for move and mouse for rotate camera." );

		auto model = createScopedRefWithInitializer<Model>(&Model::initWithFilePath, getResMng()->getResPath( "GUN" ) );
		if ( model )
		{
			model->setShaderProgram( getShadersCache()->getStandartShader( StandartShaderType::POS_UV_TEXTURE ) );
			addChild( model );
		}

		_movementController.setScope( getScope() );
		_movementController.setMovementSpeed( 1.0f );
		_movementController.initWithCamera( getCamera() );

		getCamera()->setPosition( Vec3( 0.0f, 0.0f, 5.0f ) );

		return true;
	}

}
