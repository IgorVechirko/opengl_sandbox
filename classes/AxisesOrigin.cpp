#include "AxisesOrigin.h"

#include "Line.h"


_USEVE


AxisesOrigin::AxisesOrigin()
{
}
AxisesOrigin::~AxisesOrigin()
{
}
bool AxisesOrigin::onInit()
{
	auto XAxis = Line::create(getScope());
	XAxis->setStartPos( Vec3( 0.0f ) );
	XAxis->setFinishPos( Vec3( 100000.0f, 0.0f, 0.0f ) );
	XAxis->setColor( RGBA::RED );
	addChild( XAxis );

	auto YAxis = Line::create(getScope());
	YAxis->setStartPos( Vec3( 0.0f ) );
	YAxis->setFinishPos( Vec3( 0.0f, 100000.0f, 0.0f ) );
	YAxis->setColor( RGBA::GREEN );
	addChild( YAxis );

	auto ZAxis = Line::create(getScope());
	ZAxis->setStartPos( Vec3( 0.0f ) );
	ZAxis->setFinishPos( Vec3( 0.0f, 0.0f, 100000.0f ) );
	ZAxis->setColor( RGBA( 0.0f, 0.0f, 1.0f, 1.0f ) );
	addChild( ZAxis );

	return true;
}