if(NOT DEFINED FPU)
	set(FPU "-mfpu=fpv5-d16 -mfloat-abi=hard -u _printf_float")

endif()

if(NOT DEFINED SPECS)
	set(SPECS "--specs=nano.specs --specs=nosys.specs ")
endif()

if(NOT DEFINED DEBUG_CONSOLE_CONFIG)
	set(DEBUG_CONSOLE_CONFIG "-DSDK_DEBUGCONSOLE=0")
endif()

set(CMAKE_ASM_FLAGS_DEBUG " \
    ${CMAKE_ASM_FLAGS_DEBUG} \
    ${FPU} \
    -mcpu=cortex-m7 \
    -mthumb \
")

set(CMAKE_C_FLAGS_DEBUG " \
    ${CMAKE_C_FLAGS_DEBUG} \
    ${FPU} \
    ${DEBUG_CONSOLE_CONFIG} \
    -std=gnu99 \
    -D__NEWLIB__ \
    -DCPU_MIMXRT1021DAG5A \
    -DCPU_MIMXRT1021DAG5A_cm7 \
    -DXIP_EXTERNAL_FLASH=1 \
    -DXIP_BOOT_HEADER_ENABLE=1 \
    -DLV_CONF_INCLUDE_SIMPLE=1 \
    -DMCUXPRESSO_SDK \
    -DSERIAL_PORT_TYPE_UART=1 \
    -DSDK_OS_FREE_RTOS \
    -DCR_INTEGER_PRINTF \
    -D__MCUXPRESSO \
    -D__USE_CMSIS \
    -DDEBUG \
    -O0 \
    -fno-common \
    -fmerge-constants \
    -g3 \
     -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -Wno-format \
    -fstack-usage \
    -mcpu=cortex-m7 \
    -mthumb \
")

set(CMAKE_CXX_FLAGS_DEBUG " \
    ${CMAKE_CXX_FLAGS_DEBUG} \
    ${FPU} \
    ${DEBUG_CONSOLE_CONFIG} \
    -DCPU_MIMXRT1021DAG5A \
    -DCPU_MIMXRT1021DAG5A_cm7 \
    -DMCUXPRESSO_SDK \
    -DSERIAL_PORT_TYPE_UART=1 \
    -D__MCUXPRESSO \
    -D__USE_CMSIS \
    -DDEBUG \
    -D__NEWLIB__ \
    -O0 \
    -fno-common \
    -fmerge-constants \
    -g3 \
    -Wall \
     -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fno-rtti -fno-exceptions -Wno-format \
    -fstack-usage \
    -mcpu=cortex-m7 \
    -mthumb \
")

set(CMAKE_EXE_LINKER_FLAGS_DEBUG " \
    ${CMAKE_EXE_LINKER_FLAGS_DEBUG} \
    ${FPU} \
    ${SPECS} \
    -nostdlib \
    -Xlinker \
    -no-warn-rwx-segments \
    -Xlinker \
    -Map=output.map \
    -Xlinker \
    --gc-sections \
    -Xlinker \
    -print-memory-usage \
    -Xlinker \
    --sort-section=alignment \
    -Xlinker \
    --cref \
    -mcpu=cortex-m7 \
    -mthumb \
    -T${ProjDirPath}/evkmimxrt1020_lvgl_guider_template_Debug.ld \
")
