## formatting makerules

ALL_SOURCE_FILES := \
	$(shell fd ".*\.h"   -- .)  \
	$(shell fd ".*\.c"   -- .)  \
	$(shell fd ".*\.cpp" -- .)

ALL_TRACKED_FILES := \
	$(shell git ls-files -- . | rg ".*\.h")    \
	$(shell git ls-files -- . | rg ".*\.c")    \
	$(shell git ls-files -- . | rg ".*\.cpp")

ALL_MODIFIED_FILES := \
	$(shell git lsm -- .)


format-all: $(ALL_SOURCE_FILES)
	clang-format -i $^

format: $(ALL_TRACKED_FILES)
	clang-format -i $^
	#$(GENIE) format

q qformat: $(ALL_MODIFIED_FILES)
	clang-format -i $^
