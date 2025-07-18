VERILATOR = verilator
TOP_MODULE = ./../../02_rtl/insertionSort
CPP_TB = tb_insertionSort.cpp

all:
	$(VERILATOR) --cc --exe --build $(TOP_MODULE) $(CPP_TB) -Wall -Wno-fatal
	./obj_dir/V$(TOP_MODULE)

clean:
	rm -rf obj_dir
