#ifndef UserInterface_h__
#define UserInterface_h__
#include "ReadWindLog.h"
class UserInterface
{
public:
	static int Function1(ReadWindLog& f1);
	static int Function2(ReadWindLog& f1);
	static int Function3(ReadWindLog& f1);
	static int Function4(ReadWindLog& f1);
	static int Function5(ReadWindLog& f1);
	static int Function6_EXIT(bool& flag);
};
#endif // UserInterface_h__