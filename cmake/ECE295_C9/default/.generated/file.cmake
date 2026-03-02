# The following variables contains the files used by the different stages of the build process.
set(ECE295_C9_default_default_XC8_FILE_TYPE_assemble)
set_source_files_properties(${ECE295_C9_default_default_XC8_FILE_TYPE_assemble} PROPERTIES LANGUAGE ASM)

# For assembly files, add "." to the include path for each file so that .include with a relative path works
foreach(source_file ${ECE295_C9_default_default_XC8_FILE_TYPE_assemble})
        set_source_files_properties(${source_file} PROPERTIES INCLUDE_DIRECTORIES "$<PATH:NORMAL_PATH,$<PATH:REMOVE_FILENAME,${source_file}>>")
endforeach()

set(ECE295_C9_default_default_XC8_FILE_TYPE_assemblePreprocess)
set_source_files_properties(${ECE295_C9_default_default_XC8_FILE_TYPE_assemblePreprocess} PROPERTIES LANGUAGE ASM)

# For assembly files, add "." to the include path for each file so that .include with a relative path works
foreach(source_file ${ECE295_C9_default_default_XC8_FILE_TYPE_assemblePreprocess})
        set_source_files_properties(${source_file} PROPERTIES INCLUDE_DIRECTORIES "$<PATH:NORMAL_PATH,$<PATH:REMOVE_FILENAME,${source_file}>>")
endforeach()

set(ECE295_C9_default_default_XC8_FILE_TYPE_compile
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../Si5351.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../main copy.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../main.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../twi.c")
set_source_files_properties(${ECE295_C9_default_default_XC8_FILE_TYPE_compile} PROPERTIES LANGUAGE C)
set(ECE295_C9_default_default_XC8_FILE_TYPE_link)
set(ECE295_C9_default_image_name "default.elf")
set(ECE295_C9_default_image_base_name "default")

# The output directory of the final image.
set(ECE295_C9_default_output_dir "${CMAKE_CURRENT_SOURCE_DIR}/../../../out/ECE295_C9")

# The full path to the final image.
set(ECE295_C9_default_full_path_to_image ${ECE295_C9_default_output_dir}/${ECE295_C9_default_image_name})

# Potential output file extensions
set(output_extensions
    .hex
    .hxl
    .mum
    .o
    .sdb
    .sym
    .cmf)
list(TRANSFORM output_extensions PREPEND "${ECE295_C9_default_output_dir}/${ECE295_C9_default_image_base_name}")
