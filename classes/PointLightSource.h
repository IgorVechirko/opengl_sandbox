#ifndef PointLightSource_H
#define PointLightSource_H

#include "Node.h"
#include "NodeExtestions.h"


namespace GLSandbox
{

	class ColorCube;
	class PointLightSource : public Node
						   , public LigthPropertiesProtocol
						   , public LightAttenuationProtocol
	{

		typedef Node Parent;


		ColorCube* _cube;

		protected:

			virtual bool onInit() override;


		public:

			PointLightSource();
			virtual ~PointLightSource();

			virtual void setLightProperties( const LightProperties& properties ) override;
		
	};

}


#endif
