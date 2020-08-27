#ifndef AxisesOrigin_H
#define AxisesOrigin_H

#include "Node.h"

namespace GLSandbox
{

	class AxisesOrigin : public Node
	{
		typedef Node Parent;


	protected:

		virtual bool onInit() override;

	public:

		AxisesOrigin();
		virtual ~AxisesOrigin();

	};

}


#endif

