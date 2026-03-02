include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(ECE295_C9_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(ECE295_C9_default_default_XC8_FILE_TYPE_assemble)
add_library(ECE295_C9_default_default_XC8_assemble OBJECT ${ECE295_C9_default_default_XC8_FILE_TYPE_assemble})
    ECE295_C9_default_default_XC8_assemble_rule(ECE295_C9_default_default_XC8_assemble)
    list(APPEND ECE295_C9_default_library_list "$<TARGET_OBJECTS:ECE295_C9_default_default_XC8_assemble>")

endif()

# Handle files with suffix S, for group default-XC8
if(ECE295_C9_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(ECE295_C9_default_default_XC8_assemblePreprocess OBJECT ${ECE295_C9_default_default_XC8_FILE_TYPE_assemblePreprocess})
    ECE295_C9_default_default_XC8_assemblePreprocess_rule(ECE295_C9_default_default_XC8_assemblePreprocess)
    list(APPEND ECE295_C9_default_library_list "$<TARGET_OBJECTS:ECE295_C9_default_default_XC8_assemblePreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC8
if(ECE295_C9_default_default_XC8_FILE_TYPE_compile)
add_library(ECE295_C9_default_default_XC8_compile OBJECT ${ECE295_C9_default_default_XC8_FILE_TYPE_compile})
    ECE295_C9_default_default_XC8_compile_rule(ECE295_C9_default_default_XC8_compile)
    list(APPEND ECE295_C9_default_library_list "$<TARGET_OBJECTS:ECE295_C9_default_default_XC8_compile>")

endif()


# Main target for this project
add_executable(ECE295_C9_default_image_MMh998W4 ${ECE295_C9_default_library_list})

set_target_properties(ECE295_C9_default_image_MMh998W4 PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf"
    ADDITIONAL_CLEAN_FILES "${output_extensions}"
    RUNTIME_OUTPUT_DIRECTORY "${ECE295_C9_default_output_dir}")
target_link_libraries(ECE295_C9_default_image_MMh998W4 PRIVATE ${ECE295_C9_default_default_XC8_FILE_TYPE_link})

# Add the link options from the rule file.
ECE295_C9_default_link_rule( ECE295_C9_default_image_MMh998W4)


