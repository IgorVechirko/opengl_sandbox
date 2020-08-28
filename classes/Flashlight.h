#ifndef FlashLight_H
#define FlashLight_H


#include "Node.h"
#include "NodeExtestions.h"


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
		const Vec3& getDirection() const;

		void setCutOffAngle( float angle );
		float getCutOffAngle() const;

		void setOuterCutOffAngle( float angle );
		float getOuterCutOffAngle() const;

	};

}


#endif