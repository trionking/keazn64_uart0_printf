################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Progress monitor hint: 36
first : all
-include ../makefile.init

# This file contains definitions of environment variables used in the makefiles and .args files if exist.
-include makefile.local

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include KEAZN64/LIN_Driver/bsp/UART/subdir.mk
-include KEAZN64/LIN_Driver/coreapi/subdir.mk
-include KEAZN64/LIN_Driver/diagnostic/subdir.mk
-include KEAZN64/LIN_Driver/lowlevel/subdir.mk
-include KEAZN64/LIN_Driver/transport/subdir.mk
-include KEAZN64/lin_cfg/subdir.mk
-include KEAZN64/sources/subdir.mk
-include Project_Settings/Linker_Files/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
kea64_sdk_test.elf \

EXECUTABLES_QUOTED += \
"kea64_sdk_test.elf" \

EXECUTABLES_OS_FORMAT += \
kea64_sdk_test.elf \

SECONDARY_FLASH += \
kea64_sdk_test.srec \

SECONDARY_FLASH_QUOTED += \
"kea64_sdk_test.srec" \

SECONDARY_FLASH_OS_FORMAT += \
kea64_sdk_test.srec \


# All Target
all: warning-messages explicit-dependencies kea64_sdk_test.elf secondary-outputs

# Tool invocations
kea64_sdk_test.elf: $(OBJS) D:/work/hwang_mini/sw/S32_IDE_Test/test2/kea64_sdk_test/Project_Settings/Linker_Files/SKEAZ_flash.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Executing target #37 $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "kea64_sdk_test.elf" "@kea64_sdk_test.args"  $(USER_OBJS_QUOTED) $(LIBS_QUOTED)
	@echo 'Finished building target: $@'
	@echo ' '

kea64_sdk_test.srec: $(EXECUTABLES)
	@echo 'Executing target #38 $@'
	@echo 'Invoking: Standard S32DS Create Flash Image'
	arm-none-eabi-objcopy -O srec $(EXECUTABLES)  "kea64_sdk_test.srec"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(SECONDARY_FLASH_QUOTED) ./*/*.d ./*/*/*.d ./*/*/*/*.d ./*/*/*/*/*.d  ./*/*.o ./*/*/*.o ./*/*/*/*.o ./*/*/*/*/*.o  $(EXECUTABLES_QUOTED)
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH)

.PHONY: all clean dependents explicit-dependencies warning-messages
.SECONDARY:

-include ../makefile.targets

explicit-dependencies: 

warning-messages: 

