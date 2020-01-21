ESSENTIAJS_VERSION=0.0.1
LIB_DIR_ES=$(EMSCRIPTEN)/system/local/lib
BUILD_DIR_ES=builds
BINDING_CPP_ES=src/cpp/bindings.cpp
TO_INCLUDE_ES=src/cpp/include/essentiamin.cpp
POST_JS_WASM=src/js/wasm.module.post.js
ESSENTIA_TOOLS_JS=src/js/essentia.jstools.js

build:
	@rm -rf $(BUILD_DIR_ES) 
	@mkdir $(BUILD_DIR_ES)

	@echo "Compiling the bindings to bitcode ..."

	@emcc --bind -Oz \
	   $(BINDING_CPP_ES) \
	   $(TO_INCLUDE_ES) \
	   -o $(BUILD_DIR_ES)/essentiamin.bc \
	   -s EXCEPTION_DEBUG \
	   -s ASSERTIONS=2 \
	   -s DISABLE_EXCEPTION_CATCHING=2 || exit 1
	@echo "Done ..."

	@echo "Linking and compiling the bindings with essentia to js, wasm files ..."

	@emcc --emrun --bind -Oz \
	   -s WASM=1 \
	   $(BUILD_DIR_ES)/essentiamin.bc ${LIB_DIR_ES}/essentia.a \
	   -o $(BUILD_DIR_ES)/essentiamin-$(ESSENTIAJS_VERSION)-module.js \
	   -s BINARYEN_ASYNC_COMPILATION=0 \
	   -s ALLOW_MEMORY_GROWTH=1 \
	   -s SINGLE_FILE=1 || exit 1
	    
	@cat $(POST_JS_WASM) >> $(BUILD_DIR_ES)/essentiamin-$(ESSENTIAJS_VERSION)-module.js

	@cp $(ESSENTIA_TOOLS_JS) $(BUILD_DIR_ES)/
	@echo "Done ..."

	@echo "Removing unnecessary files ..."
	@rm $(BUILD_DIR_ES)/essentiamin.bc
	@echo "Done ..."

	@echo "Builds ..."
	@ls $(BUILD_DIR_ES)


clean:
	@rm -rf ./builds
