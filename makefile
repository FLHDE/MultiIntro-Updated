# VC6 makefile

OBJ_DIR = obj

RC_FILE = Version.rc
CPP_FILES = *.cpp

RES_FILE = Version.RES
OBJ_FILES = $(OBJ_DIR)\*.obj
LIB_FILE = common.lib

OUTPUT_FILE = MultiIntro.dll

CXX_FLAGS = /c /GX /O2 /nologo /W3 /WX /LD /MD
LD_FLAGS = /DLL /FILEALIGN:512 /NOLOGO /RELEASE

$(OUTPUT_FILE): $(OBJ_DIR) $(RES_FILE) $(LIB_FILE) $(RC_FILE) $(CPP_FILES) $(OBJ_FILES)
    link $(OBJ_FILES) $(LIB_FILE) winmm.lib $(RES_FILE) $(LD_FLAGS) /OUT:$(OUTPUT_FILE)

.cpp{$(OBJ_DIR)}.obj::
    $(CPP) $(CXX_FLAGS) $< /Fo./$(OBJ_DIR)/

$(RES_FILE): $(RC_FILE)
    rc /fo $(RES_FILE) $(RC_FILE)

$(OBJ_DIR):
    if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)

# Dependencies
Main.h: Common.h
main.cpp: Main.h
