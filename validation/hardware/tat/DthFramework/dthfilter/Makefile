#
#**********************************************************************
#
# Synopsis: DTHFILTER Makefile- Linux Application Build Rules.
#
#**********************************************************************
#

include .config.mk

PACKAGE_NAME=dthfilter
PACKAGE_EXEC_NAME=$(PACKAGE_NAME)
PACKAGE_ALIAS=$(PACKAGE_NAME)

SOURCES= dthfilter.c
OUTPUT= $(HATS_OBJ)/$(PACKAGE_NAME)
OBJECTS= $(addprefix $(OUTPUT)/,$(SOURCES:.c=.o))
SYMBOLS= $(HATS_SYM)/$(PACKAGE_EXEC_NAME)
BINARIES= $(HATS_BIN)/$(PACKAGE_EXEC_NAME)

.PHONY: all install clean

all: install

$(OUTPUT)/%.o: %.c
	$(MKDIR) -p $(OUTPUT)
	$(CC) $< -c $(CFLAGS) -o $(@)

$(SYMBOLS): $(OBJECTS)
	$(CC) $^ $(LDFLAGS) $(EXEFLAGS) -o $(@)

$(BINARIES): $(SYMBOLS)
	$(ECHO) -e "\t-----> $(PACKAGE_NAME) : $@"
	$(INSTALL_CMD) -D $< $(HATS_BIN)
	$(STRIP) --strip-unneeded $(@)

install: $(BINARIES)

clean:
	$(ECHO) -e "\t-----> $(PACKAGE_NAME): $@"
	$(RM) -rf $(OUTPUT) $(SYMBOLS) $(BINARIES)
