#ifndef DirectLightSource_H
#define DirectLightSource_H

#include "Node.h"


_VESTART

class Line;
class DirectLightSource : public Node
{

	typedef Node Parent;

	Vec3 _direction;

	LightProperties _lightProperties;

	const int _linesCount;
	const float _distBetweenLines;
	std::vector<Line*> _directionLines;


	void updateDirectionLines();


protected:

	DirectLightSource();


	virtual bool init() override;

	virtual void setRotate( const Vec3& rotate ) override;
	virtual void setScale( const Vec3& scale ) override;


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