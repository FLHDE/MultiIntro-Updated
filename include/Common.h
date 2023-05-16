#ifndef _COMMON_
#define _COMMON_

#define IMPORT __declspec(dllimport)

typedef unsigned int uint;

namespace Universe
{
	IMPORT uint get_base_id(char const *);
}

class IMPORT INI_Reader
{
public:
    bool open(char const *, bool);
    bool read_header(void);
    bool is_header(char const *);
    bool read_value(void);
    bool is_value(char const *);
    bool get_value_bool(unsigned int);
    int get_value_int(unsigned int);
    void close(void);

private:
    char data[0x1568];
};

#endif
