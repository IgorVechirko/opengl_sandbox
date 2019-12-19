#ifndef DirectLightSource_H
#define DirectLightSource_H

#include "Ref.h"


_VESTART


class DirectLightSource : public Ref
{

	Vec3 _direction;

	LightProperties _lightProperties;



	DirectLightSource();
	bool init(){return true;};


	public:

		virtual ~DirectLightSource();

		AUTORELEASE_CREATE_FUNC( DirectLightSource );

		void setDirection( const Vec3& aDirection );
		const Vec3& getDirection();

		void setLightProperties( const LightProperties& properties );
		const LightProperties& getLightProperties();


};



_VEEND



#endif