#ifndef OutlineSprite_H
#define OutlineSprite_H

#include "Sprite.h"


namespace GLSandbox
{

	class OutlineSprite : public Sprite
	{
		float _outlineCoef;

		ShaderProtocol _outlineShaderProtocol;

		RGBA _outlineColor;

	protected:

		virtual bool onInit() override;

		virtual void drawTraversal( const Mat4& parentTransform ) override;


	public:

		OutlineSprite();
		virtual ~OutlineSprite();
		MAKE_UNCOPYABLE(OutlineSprite);

		ShaderProtocol& getOutlineShaderProtocol();

		void setOutlineCoef( float coef );
		float getOutlineCoef();


	};


}


#endif