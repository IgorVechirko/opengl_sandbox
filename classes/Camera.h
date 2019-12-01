#include "Ref.h"

_VESTART

class Camera : public Ref
{
	Mat4 _projection;
	Mat4 _view;

	bool _viewDirty;

	Vec3 _cameraPos;
	Vec3 _cameraFront;
	Vec3 _cameraUp;

	float _cameraPitch;
	float _cameraYaw;
	float _cameraRoll;

	Camera();

protected:

	virtual bool init(){return true;};

public:

	virtual ~Camera();

	void setProjection( const Mat4& projection );
	const Mat4& getProjection() const;

	void setView( const Mat4& view );
	const Mat4& getView();

	void setCameraPos( const Vec3& pos );
	const Vec3& getCameraPos() const;

	void moveAhead( float shift );
	void moveBack( float shift );
	void moveRight( float shift );
	void moveLeft( float shift );
	void moveUp( float shift );
	void moveDown( float shift );

	void spinPitch( float shift );
	void spinYaw( float shift );



	AUTORELEASE_CREATE_FUNC(Camera);
};

_VEEND

