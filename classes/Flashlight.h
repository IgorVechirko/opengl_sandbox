#ifndef FlashLight_H
#define FlashLight_H


#include "Node.h"
#include "NodeExtentions.h"


namespace GLSandbox
{

	class ColorCube;
	class Flashlight : public Node
					 , public LigthPropertiesProtocol
					 , public LightAttenuationProtocol
	{

		typedef Node Parent;

		ColorCube* _cube;

		Vec3 _direction;
		float _cutOffAngle;
		float _outerCutOffAngle;


	protected:

		virtual bool onInit() override;

	public:

		Flashlight();
		virtual ~Flashlight();
	
		virtual void setLightProperties( const LightProperties& properties ) override;

		void setDirection( const Vec3& direction );
		const Vec3& getDirection();

		void setCutOffAngle( float angle );
		float getCutOffAngle();

		void setOuterCutOffAngle( float angle );
		float getOuterCutOffAngle();

	};

}


#endif