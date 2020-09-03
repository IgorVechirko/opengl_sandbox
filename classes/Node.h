#ifndef Node_H
#define Node_H

#include "Ref.h"
#include "WorkingScopeProvider.h"

namespace GLSandbox
{

	class GLRender;
	class Node
		: public Ref
		, public WorkingScopeProvider
	{

		mutable glm::mat4 _transform;
		mutable bool _transformDirty;

	protected:

		Vec3 _pos;
		Vec3 _rotate;
		Vec3 _scale;

		Vec3 _originShift;

		std::string _name;

		std::vector<Node*> _children;

		bool _visible;

	protected:

		const glm::mat4& getTransform() const;


		virtual bool onInit(){ return true;};

		virtual void update( float delatTime ){};

	public:

		Node();
		virtual ~Node();
		MAKE_UNCOPYABLE(Node);

		bool init();

		virtual void drawTraversal( const Mat4& parentTransform );
		virtual void draw( const Mat4& transform ){};

		virtual void setPosition( const Vec3& pos );
		const Vec3& getPosition() const;

		virtual void setRotate( const Vec3& rotate );
		const Vec3& getRotate() const;

		virtual void setScale( const Vec3& scale );
		const Vec3& getScale() const;

		virtual void setVisbile( bool visible );
		virtual bool getVisible() const;

		void setName( const std::string& name );
		const std::string& getName() const;

		void setOriginShift( const Vec3& shift );
		const Vec3& getOriginShift() const;

		void addChild( Node* child );
		void removeChild( Node* child );

		void scheduleUpdate();
		void unscheduleUpdate();

		const std::vector<Node*>& getChildren() const;
		Node* getChild( const std::string& childName ) const;
	
		template<typename T> 
		T* getChild( const std::string& childName ) const
		{
			return dynamic_cast<T>( getChild( childName ) );
		}
	};

}

#endif