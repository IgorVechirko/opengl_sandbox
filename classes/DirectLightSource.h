#ifndef DirectLightSource_H
#define DirectLightSource_H

#include "Node.h"
#include "NodeExtestions.h"


namespace GLSandbox
{
	class Line;
	class DirectLightSource : public Node
							, public LigthPropertiesProtocol
	{

		typedef Node Parent;

		Vec3 _direction;

		const int _linesCount;
		const float _distBetweenLines;
		std::vector<Line*> _directionLines;


		void updateDirectionLines();


	protected:

		virtual bool onInit() override;

		virtual void setRotate( const Vec3& rotate ) override;
		virtual void setScale( const Vec3& scale ) override;


		public:

			DirectLightSource();
			virtual ~DirectLightSource();
			MAKE_UNCOPYABLE(DirectLightSource);

			void setDirection( const Vec3& aDirection );
			const Vec3& getDirection() const;

			virtual void setLightProperties( const LightProperties& properties ) override;


	};

}



#endif