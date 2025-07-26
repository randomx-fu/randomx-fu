// randomx_vm.cpp (PoC mutation for randomx-fu)
// Simple mutation layer to demonstrate RandomX opcode tweaking

#include "command_line.h"
#include "randomx_vm.h"

namespace randomx_fu {

static const command_line::arg_descriptor<bool> arg_mutate_pow = {
    "randomx-fu", "Enable RandomX opcode mutation (PoC for anti-centralization fork)"
};

void maybe_mutate_opcode_table(VM& vm, InstructionTable& instruction_table) {
    if (command_line::get_arg(vm, arg_mutate_pow)) {
        for (size_t i = 0; i < instruction_table.size(); ++i) {
            instruction_table[i].opcode ^= 0x5A; // yeah this breaks optimizations. that's the point.
        }
    }
}

void register_cli_arg(boost::program_options::options_description& desc) {
    command_line::add_arg(desc, arg_mutate_pow);
}

}
