#include "AxisesOrigin.h"

#include "Line.h"
#include "WorkingScope.h"


_USEVE


AxisesOrigin::AxisesOrigin()
{
}
AxisesOrigin::~AxisesOrigin()
{
}
bool AxisesOrigin::onInit()
{
	auto XAxis = createNode<Line>();
	XAxis->setStartPos( Vec3( 0.0f ) );
	XAxis->setFinishPos( Vec3( 100000.0f, 0.0f, 0.0f ) );
	XAxis->setColor( RGBA::RED );
	addChild( XAxis );

	auto YAxis = createNode<Line>();
	YAxis->setStartPos( Vec3( 0.0f ) );
	YAxis->setFinishPos( Vec3( 0.0f, 100000.0f, 0.0f ) );
	YAxis->setColor( RGBA::GREEN );
	addChild( YAxis );

	auto ZAxis = createNode<Line>();
	ZAxis->setStartPos( Vec3( 0.0f ) );
	ZAxis->setFinishPos( Vec3( 0.0f, 0.0f, 100000.0f ) );
	ZAxis->setColor( RGBA( 0.0f, 0.0f, 1.0f, 1.0f ) );
	addChild( ZAxis );

	return true;
}