TOPMODULE       ?= SS_detect_start
INC_DIR         ?= ./include
LIB_DIR         := 

TOOL            := verilator
VERILATOR_FLAGS := --binary --timing --trace --build
WARNING_IGNORE  := -Wno-fatal -Wno-lint -Wno-style -Wno-width
INC_FLAGS       := $(addprefix -I,$(INC_DIR) $(LIB_DIR))

all: clean compile run

all_wave: clean compile run sim

compile:
	@echo "-> Creating output directory..."
	@mkdir -p $(INC_DIR)
	@echo "-> Compiling..."
	@$(TOOL) $(VERILATOR_FLAGS) -f $(INC_DIR)/flist.f $(INC_FLAGS) $(WARNING_IGNORE) --Mdir $(INC_DIR)/obj_dir --trace --o Vtb_$(TOPMODULE)

run:
	@echo "-> Running..."
	@$(INC_DIR)/obj_dir/Vtb_$(TOPMODULE) | tee $(INC_DIR)/simulation.log
	@mv ./tb_$(TOPMODULE).vcd $(INC_DIR)

sim:
	@echo "-> Opening waveform viewer..."
	@gtkwave $(INC_DIR)/tb_$(TOPMODULE).vcd &> /dev/null

clean:
	@echo "-> Cleaning project..."
	@rm -rf $(INC_DIR)/obj_dir

help:
	@echo "Makefile targets:"
	@echo "  all       : Clean, compile, and run (default)"
	@echo "  all_wave  : Clean, compile, run, and open waveform viewer"
	@echo "  compile   : Compile the design with Verilator"
	@echo "  run       : Run the simulation"
	@echo "  sim       : Open waveform viewer"
	@echo "  clean     : Remove generated files"
	@echo "  help      : Show this help message"

.PHONY: all all_wave compile run sim clean help
