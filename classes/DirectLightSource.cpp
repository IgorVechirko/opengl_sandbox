#include "DirectLightSource.h"

#include "Line.h"

_USEVE


DirectLightSource::DirectLightSource()
	: _direction( 0.0f, 0.0f, 0.0f )
	, _linesCount( 10 )
	, _distBetweenLines( 10.0f )
{
}
DirectLightSource::~DirectLightSource()
{
}
void DirectLightSource::updateDirectionLines()
{
	for( int columnIndx = 0; columnIndx < 10; columnIndx++ )
	{
		for( int rowIndx = 0; rowIndx < 10; rowIndx++ )
		{
			auto indx = columnIndx * _linesCount + rowIndx;
			if ( _directionLines.size() > indx )
			{
				auto line = _directionLines[indx];
				line->setFinishPos( line->getStartPos() + ( _direction * 100.0f ) );
			}
		}
	}
}
bool DirectLightSource::init()
{
	for( int columnIndx = 0; columnIndx < _linesCount; columnIndx++ )
	{
		for( int rowIndx = 0; rowIndx < _linesCount; rowIndx++ )
		{
			auto line = Line::create();
			line->setStartPos( Vec3( rowIndx * _distBetweenLines, columnIndx * _distBetweenLines, 0.0f ) );
			line->setFinishPos( Vec3( rowIndx * _distBetweenLines, columnIndx * _distBetweenLines, 0.0f ) );
			addChild( line );
			_directionLines.push_back( line );
		}
	}

	return true;
}
void DirectLightSource::setRotate( const Vec3& rotate )
{
}
void DirectLightSource::setScale( const Vec3& scale )
{
}
void DirectLightSource::setDirection( const Vec3& direction )
{
	_direction = direction;

	updateDirectionLines();
}
const Vec3& DirectLightSource::getDirection()
{
	return _direction;
}
void DirectLightSource::setLightProperties( const LightProperties& properties )
{
	_lightProperties = properties;

	for( int columnIndx = 0; columnIndx < 10; columnIndx++ )
	{
		for( int rowIndx = 0; rowIndx < 10; rowIndx++ )
		{
			auto indx = columnIndx * _linesCount + rowIndx;
			if ( _directionLines.size() > indx )
			{
				auto line = _directionLines[indx];
				line->setColor( RGBA( _lightProperties.diffuse.r, _lightProperties.diffuse.g, _lightProperties.diffuse.b, 1.0f ) );
			}
		}
	}
}