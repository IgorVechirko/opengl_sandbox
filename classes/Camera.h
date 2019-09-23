#include "Ref.h"

_VESTART

class Camera : public Ref
{
	Mat4 _projection;
	Mat4 _view;

	Camera();

protected:

	bool init(){return true;};

public:

	virtual ~Camera();

	void setProjection( const Mat4& projection );
	const Mat4& getProjection() const;

	void setView( const Mat4& view );
	const Mat4& getView() const;

	AUTORELEASE_CREATE_FUNC(Camera);
};

_VEEND

