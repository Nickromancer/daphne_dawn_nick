# Copyright 2021 The DAPHNE Consortium
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Specifies how to generate the file "kernels.cpp" (which resides in the build
# directory) as the basis for the pre-compiled kernels library.

#       * more properly set up paths (ugly relative include path below)
#cmake_minimum_required(VERSION 3.21)

#project(Delilahkernels)


set(PREFIX ${PROJECT_SOURCE_DIR}/src/runtime/local/kernels/Delilah)
add_custom_command(
    OUTPUT ${PROJECT_BINARY_DIR}/DelilahKernels.cpp
    COMMAND python3 ARGS genKernelInst.py kernels.json
    ${PROJECT_BINARY_DIR}/DelilahKernels.cpp Delilah
    MAIN_DEPENDENCY ${PREFIX}/../kernels.json
    DEPENDS ${PREFIX}/../genKernelInst.py
    WORKING_DIRECTORY ${PREFIX}/..
)

#set(PREFIX ${PROJECT_SOURCE_DIR}/src/runtime/local/kernels/Delilah)
set(DelilahKernels_SRC
	${PREFIX}/../../context/DelilahContext.cpp
 	${PREFIX}/../../context/DelilahContext.h
	${PREFIX}/../CreateDelilahContext.h
        ${PREFIX}/kernel_utils.h
        ${PREFIX}/kernel_utils.cpp
        ${PREFIX}/MatMul.h
	${PREFIX}/../Delilah_destroy.h
	${PREFIX}/../Delilah_init.h
	${PREFIX}/../Delilah_info.h
	${PROJECT_BINARY_DIR}/DelilahKernels.cpp
	${PREFIX}/kernel_utils.h
        ${PREFIX}/kernel_utils.cpp
) 

add_library(DelilahKernels SHARED ${DelilahKernels_SRC})
set_target_properties(DelilahKernels PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

target_include_directories(DelilahKernels PUBLIC ${PROJECT_SOURCE_DIR}/src/)

