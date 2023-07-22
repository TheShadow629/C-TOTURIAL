#ifndef UserInterface_h__
#define UserInterface_h__
#include "ReadFile.h"
class UserInterface
{
public:
	static int Function1(ReadFile& f1);
	static int Function2(ReadFile& f1);
	static int Function3(ReadFile& f1);
	static int Function4(ReadFile& f1);
	static int Function5(ReadFile& f1);

	static int Function6_EXIT(bool& flag);
};
#endif // UserInterface_h__