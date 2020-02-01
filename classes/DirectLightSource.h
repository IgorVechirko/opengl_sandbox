#ifndef DirectLightSource_H
#define DirectLightSource_H

#include "Node.h"
#include "NodeExtentions.h"


_VESTART

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

	DirectLightSource();


	virtual bool init() override;

	virtual void setRotate( const Vec3& rotate ) override;
	virtual void setScale( const Vec3& scale ) override;


	public:

		virtual ~DirectLightSource();

		AUTORELEASE_CREATE_FUNC( DirectLightSource );

		void setDirection( const Vec3& aDirection );
		const Vec3& getDirection();

		virtual void setLightProperties( const LightProperties& properties ) override;


};



_VEEND



#endif