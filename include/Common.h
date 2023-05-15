#ifndef _COMMON_
#define _COMMON_

#define IMPORT __declspec(dllimport)

namespace Universe
{
	IMPORT uint get_base_id(char const *);
}

#endif
