# VC6 makefile

BIN_DIR = bin
INCLUDE_DIR = include
OBJ_DIR = obj
RC_DIR = rc
SRC_DIR = src

RC_FILE = $(RC_DIR)\Version.rc
CPP_FILES = $(SRC_DIR)\*.cpp

RES_FILE = $(OBJ_DIR)\Version.RES
OBJ_FILES = $(OBJ_DIR)\*.obj
LIB_FILE = $(OBJ_DIR)\common.lib

OUTPUT_FILE = $(BIN_DIR)\MultiIntro.dll

CXX_FLAGS = /c /GX /O2 /nologo /W3 /WX /LD /MD
LD_FLAGS = /DLL /FILEALIGN:512 /NOLOGO /RELEASE

$(OUTPUT_FILE): $(OBJ_DIR) $(BIN_DIR) $(RES_FILE) $(LIB_FILE) $(RC_FILE) $(CPP_FILES) $(OBJ_FILES)
    link $(OBJ_FILES) $(LIB_FILE) winmm.lib $(RES_FILE) $(LD_FLAGS) /OUT:$(OUTPUT_FILE)

{$(SRC_DIR)}.cpp{$(OBJ_DIR)}.obj::
    $(CPP) $(CXX_FLAGS) $< -I$(INCLUDE_DIR) /Fo./$(OBJ_DIR)/

$(RES_FILE): $(RC_FILE)
    rc /fo $(RES_FILE) $(RC_FILE)

$(BIN_DIR):
    if not exist $(BIN_DIR) mkdir $(BIN_DIR)

$(OBJ_DIR):
    if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)

# Dependencies
$(INCLUDE_DIR)\Main.h: $(INCLUDE_DIR)\Common.h
$(SRC_DIR)\main.cpp: $(INCLUDE_DIR)\Main.h
