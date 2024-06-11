ifndef MODEL_NAME
$(error MODEL_NAME environment variable is not set. Please define a valid model name.)
endif

ALGSRC_DIR := ./algsrc

ALGHEADER_PATH := $(ALGSRC_DIR)/$(MODEL_NAME).h

# Source files
SOURCES := \
 $(addprefix $(ALGSRC_DIR)/, $(addprefix $(MODEL_NAME), .c _data.c) rt_nonfinite.c rtGetInf.c rtGetNaN.c ) \
 ./wrapper/wrapper.c

# Include directories
INC_DIRS := \
 "$(ALGSRC_DIR)" \
 "./lvext" \
 "."

TARGET_FILENAME := lib$(MODEL_NAME).so

# If there is any additional project specific compiler flags desired, add to CFLAGS variable
CFLAGS += 

# All Target
all: $(TARGET_FILENAME)

# Tool invocations
$(TARGET_FILENAME): $(SOURCES)
	@echo 'Creating Shared Library: $@ ...'
	$(CC) $(CFLAGS) $(addprefix -I, $(INC_DIRS)) -DMODEL_NAME=$(MODEL_NAME) -Werror=conversion -Werror=sign-conversion -fPIC -shared -o $@ $^
	@echo ' '
	@echo 'Shared Library $@ has been successfully created.'
	@echo ' '
	
# Other Targets
clean:
	-del $(TARGET_FILENAME)
	-@echo ' '

.PHONY: all clean
