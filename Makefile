src = src
test = test

.PHONY: all $(test) $(src)
all: $(test)

$(test) $(src):
	$(MAKE) --directory=$@

$(test) : $(src)