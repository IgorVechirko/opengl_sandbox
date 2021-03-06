#include "Node.h"

namespace GLSandbox
{

	class Camera : public Node
	{
		typedef Node Parent;

		Mat4 _projection;
		mutable Mat4 _view;

		mutable bool _viewDirty;

		mutable Vec3 _cameraFront;
		const Vec3 _cameraUp;

		float _cameraPitch;
		float _cameraYaw;
		float _cameraRoll;

	
	protected:

		virtual bool onInit() override;


	public:

		Camera();
		virtual ~Camera();
		MAKE_UNCOPYABLE(Camera);

		void setProjection( const Mat4& projection );
		const Mat4& getProjection() const;

		void setView( const Mat4& view );
		const Mat4& getView() const;

		virtual void setPosition( const Vec3& pos ) override;

		void moveAhead( float shift );
		void moveBack( float shift );
		void moveRight( float shift );
		void moveLeft( float shift );
		void moveUp( float shift );
		void moveDown( float shift );

		void spinPitch( float shift );
		void spinYaw( float shift );

	};

}

