INCLUDE_PATH = $(CPLUS_INCLUDE_PATH)
ifeq "$(INCLUDE_PATH)" ""
	INCLUDE_PATH = /usr/include
endif

DIR = $(INCLUDE_PATH)/stdextcpp

default:
	@echo "Try 'make install' to install the files in $(DIR)"

install:
	@mkdir -p $(DIR)
	@cp -rv *.hpp $(DIR)

uninstall:
	@rm -rfv $(DIR)
