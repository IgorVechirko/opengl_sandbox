#ifndef PointLightSource_H
#define PointLightSource_H

#include "Node.h"
#include "NodeExtentions.h"


_VESTART

class ColorCube;
class PointLightSource : public Node
					   , public LigthPropertiesProtocol
					   , public LightAttenuationProtocol
{

	typedef Node Parent;

	ColorCube* _cube;

	protected:

		PointLightSource();

		virtual bool onInit() override;


	public:

		virtual ~PointLightSource();

		CREATE_FUNC(PointLightSource);

		virtual void setLightProperties( const LightProperties& properties ) override;
		
};


_VEEND	

#endif
