SRC_FILES := $(wildcard $(directory)/*.cc)
BIN_FILES := $(patsubst $(directory)/%.cc,$(directory)/%.bin,$(SRC_FILES))


test: $(BIN_FILES)
	rm $(directory)/*.bin
	@echo "Done."
	

%.bin: %.cc
	g++ $< -o $@ -std=c++11