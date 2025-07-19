.PHONY: all clean run

all:
	$(MAKE) -C Logger
	$(MAKE) -C Application

clean:
	$(MAKE) -C Logger clean
	$(MAKE) -C Application clean

run: all
	$(MAKE) -C Application run
