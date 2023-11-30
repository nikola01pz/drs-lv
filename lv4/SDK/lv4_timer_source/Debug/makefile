################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
ELFSIZE += \
lv4_timer_source.elf.size \

ELFCHECK += \
lv4_timer_source.elf.elfcheck \


# All Target
all: lv4_timer_source.elf secondary-outputs

# Tool invocations
lv4_timer_source.elf: $(OBJS) ../src/lscript.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MicroBlaze gcc linker'
	mb-gcc -Wl,-T -Wl,../src/lscript.ld -L../../lv4_timer_source_bsp/microblaze_0/lib -mxl-barrel-shift -mxl-pattern-compare -mcpu=v8.50.c -mno-xl-soft-mul -Wl,--no-relax -Wl,--gc-sections -o "lv4_timer_source.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

lv4_timer_source.elf.size: lv4_timer_source.elf
	@echo 'Invoking: MicroBlaze Print Size'
	mb-size lv4_timer_source.elf  |tee "lv4_timer_source.elf.size"
	@echo 'Finished building: $@'
	@echo ' '

lv4_timer_source.elf.elfcheck: lv4_timer_source.elf
	@echo 'Invoking: Xilinx ELF Check'
	elfcheck lv4_timer_source.elf -hw ../../EDK_hw_platform/system.xml -pe microblaze_0  |tee "lv4_timer_source.elf.elfcheck"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES)$(ELFSIZE)$(ELFCHECK)$(S_UPPER_DEPS) lv4_timer_source.elf
	-@echo ' '

secondary-outputs: $(ELFSIZE) $(ELFCHECK)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
