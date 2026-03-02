# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "D:\\Programming\\ECE295_C9\\out\\ECE295_C9\\default.cmf"
  "D:\\Programming\\ECE295_C9\\out\\ECE295_C9\\default.hex"
  "D:\\Programming\\ECE295_C9\\out\\ECE295_C9\\default.hxl"
  "D:\\Programming\\ECE295_C9\\out\\ECE295_C9\\default.mum"
  "D:\\Programming\\ECE295_C9\\out\\ECE295_C9\\default.o"
  "D:\\Programming\\ECE295_C9\\out\\ECE295_C9\\default.sdb"
  "D:\\Programming\\ECE295_C9\\out\\ECE295_C9\\default.sym"
  )
endif()
